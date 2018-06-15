#include <cppunit/TestAssert.h>
#include <cppunit/TestCase.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>

extern "C" {
#include "malloc/malloc_data.h"
#include "utils/utils.h"
#include <sys/resource.h>
#include <unistd.h>
}

#include "tests/utils.hpp"
#include <iostream>

class AddBlockTest : public CppUnit::TestCase {
public:
	CPPUNIT_TEST_SUITE(AddBlockTest);
	CPPUNIT_TEST(location);
	CPPUNIT_TEST(block_content);
	CPPUNIT_TEST_SUITE_END();

	void location() {
		char loc[sizeof(t_block)];
		{
			auto* block = add_new_block(&loc, 42);
			block->free= 0;
		}
		t_block* block = (t_block*)&loc[0];
		CPPUNIT_ASSERT_EQUAL(42ul - sizeof(t_block), block->size);
		CPPUNIT_ASSERT(!block->free);
	}
	void block_content() {
		char loc[sizeof(t_block)];
		auto* block = add_new_block(&loc, 420);
		CPPUNIT_ASSERT_EQUAL(420ul - sizeof(t_block), block->size);
		CPPUNIT_ASSERT_EQUAL(1, block->free);
		CPPUNIT_ASSERT(!block->next);
	}
};

class MmapAreaTest : public CppUnit::TestCase {
private: 
	void basic_check(t_block_type type, std::size_t size) {
		auto* mapped = mmap_area(type, size);
		CPPUNIT_ASSERT(mapped);
		if (type == LARGE) {
			CPPUNIT_ASSERT_EQUAL(size + sizeof(t_block) + sizeof(t_area), mapped->size);
			CPPUNIT_ASSERT_EQUAL(size + sizeof(t_block) + sizeof(t_area), g_areas[type].total_size);
		}
		else {
			CPPUNIT_ASSERT_EQUAL(get_area_size(type), mapped->size);
			CPPUNIT_ASSERT_EQUAL(get_area_size(type), g_areas[type].total_size);
		}
		auto* block = (t_block*)(mapped + 1);
		CPPUNIT_ASSERT(block);
		CPPUNIT_ASSERT(block->free);
		if (type == LARGE)
			CPPUNIT_ASSERT_EQUAL(size, block->size);
		else
			CPPUNIT_ASSERT_EQUAL(get_area_size(type) - sizeof(t_area) - sizeof(t_block), block->size);
		unmap_everything();
	}

	void rlimit(std::size_t lim, std::function<void()> tests) {
		struct rlimit old;
		struct rlimit new_lim;
		getrlimit(RLIMIT_DATA, &old);
		new_lim = old;
		new_lim.rlim_cur = lim;
		setrlimit(RLIMIT_DATA, &new_lim);
		tests();
		setrlimit(RLIMIT_DATA, &old);
		unmap_everything();
	}
public:
	CPPUNIT_TEST_SUITE(MmapAreaTest);
	CPPUNIT_TEST(basic_checks);
	CPPUNIT_TEST(rlimit);
	CPPUNIT_TEST_SUITE_END();

	void basic_checks() {
		basic_check(LARGE, 1024);
		basic_check(TINY, 1);
		basic_check(TINY, 10);
		basic_check(SMALL, 100);
		basic_check(SMALL, 142);
	}

	void rlimit() {
		rlimit(1000, []() {
				auto *p = mmap_area(TINY, 1000);
				CPPUNIT_ASSERT(not p);
				});
		rlimit(1000, []() {
				auto *p = mmap_area(LARGE, 1000);
				CPPUNIT_ASSERT(not p);
				});
		rlimit(getpagesize(), []() {
				auto *p = mmap_area(SMALL, 64);
				CPPUNIT_ASSERT(not p);
				});
		rlimit(getpagesize() * 2, []() {
				auto *p = mmap_area(SMALL, 64);
				CPPUNIT_ASSERT(p);
				CPPUNIT_ASSERT_EQUAL(getpagesize() * 1ul, p->size);
				});
		rlimit(getpagesize() * 3, []() {
				auto *p = mmap_area(SMALL, 64);
				CPPUNIT_ASSERT(p);
				CPPUNIT_ASSERT_EQUAL(getpagesize() * 2ul, p->size);
				});
	}
};

class UnmapAreaTest : public CppUnit::TestCase {
public:
	CPPUNIT_TEST_SUITE(UnmapAreaTest);
	CPPUNIT_TEST(remove_first);
	CPPUNIT_TEST(remove_second_nothing_after);
	CPPUNIT_TEST(remove_second_something_after);
	CPPUNIT_TEST_SUITE_END();
	void remove_first() {
		auto area_sim1 = get_simulation_area(64, {});
		auto area_sim2 = get_simulation_area(72, {});
		auto areas = chain_areas(TINY, {&area_sim1, &area_sim2});

		t_block_location l{nullptr, areas[0], nullptr, nullptr};
		unmap_area(TINY, &l);
		CPPUNIT_ASSERT_EQUAL(areas[1], g_areas[TINY].area);
		CPPUNIT_ASSERT_EQUAL(areas[1]->size, g_areas[TINY].total_size);
		unmap_everything();
	}

	void remove_second_nothing_after() {
		auto area_sim1 = get_simulation_area(64, {});
		auto area_sim2 = get_simulation_area(72, {});
		auto areas = chain_areas(TINY, {&area_sim1, &area_sim2});

		t_block_location l{areas[0], areas[1], nullptr, nullptr};
		unmap_area(TINY, &l);
		CPPUNIT_ASSERT_EQUAL(areas[0], g_areas[TINY].area);
		CPPUNIT_ASSERT(!areas[0]->next);
		CPPUNIT_ASSERT_EQUAL(areas[0]->size, g_areas[TINY].total_size);
		unmap_everything();
	}

	void remove_second_something_after() {
		auto area_sim1 = get_simulation_area(56, {});
		auto area_sim2 = get_simulation_area(124, {});
		auto area_sim3 = get_simulation_area(64, {});
		auto areas = chain_areas(TINY, {&area_sim1, &area_sim2, &area_sim3});

		t_block_location l{areas[0], areas[1], nullptr, nullptr};
		unmap_area(TINY, &l);
		CPPUNIT_ASSERT_EQUAL(areas[0], g_areas[TINY].area);
		CPPUNIT_ASSERT_EQUAL(areas[0]->next, areas[2]);
		CPPUNIT_ASSERT_EQUAL(areas[0]->size + areas[2]->size, g_areas[TINY].total_size);
		unmap_everything();
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION(AddBlockTest);
CPPUNIT_TEST_SUITE_REGISTRATION(MmapAreaTest);
CPPUNIT_TEST_SUITE_REGISTRATION(UnmapAreaTest);

int main() {
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest(registry.makeTest());
	return !runner.run();
}
