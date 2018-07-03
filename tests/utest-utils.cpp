#include <cppunit/TestAssert.h>
#include <cppunit/TestCase.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>

extern "C" {
#include "ft_malloc/malloc_data.h"
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
	CPPUNIT_TEST_SUITE_END();

	void location() {
		char loc[sizeof(t_block) + 42];
		{
			auto* block = add_new_block(&loc, 42);
		}
		t_block* block = reinterpret_cast<t_block*>(&loc[0]);
		CPPUNIT_ASSERT_EQUAL(42ul, block->size);
		CPPUNIT_ASSERT(!block->next_free);
	}
};

class RoundTestSize : public CppUnit::TestCase {
public:
	CPPUNIT_TEST_SUITE(RoundTestSize);
	CPPUNIT_TEST(test);
	CPPUNIT_TEST_SUITE_END();

	void test() {
		CPPUNIT_ASSERT_EQUAL(16ul, round_size(TINY, 1ul));
		CPPUNIT_ASSERT_EQUAL(32ul, round_size(TINY, 31ul));
		CPPUNIT_ASSERT_EQUAL(0ul, round_size(TINY, 0ul));

		CPPUNIT_ASSERT_EQUAL(512ul, round_size(SMALL, 1ul));
		CPPUNIT_ASSERT_EQUAL(1024ul, round_size(SMALL, 958ul));
		CPPUNIT_ASSERT_EQUAL(0ul, round_size(SMALL, 0ul));

		CPPUNIT_ASSERT_EQUAL(5633ul, round_size(LARGE, 5633ul));
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
		auto* block = reinterpret_cast<t_block*>(mapped + 1);
		CPPUNIT_ASSERT(block);
		CPPUNIT_ASSERT(not block->next_free);
		if (type == LARGE)
			CPPUNIT_ASSERT_EQUAL(size + sizeof(t_block), block->size);
		else
			CPPUNIT_ASSERT_EQUAL(get_area_size(type) - sizeof(t_area), block->size);
		unmap_everything();
	}

	void rlimit(std::size_t lim, std::function<void()>&& tests) {
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

CPPUNIT_TEST_SUITE_REGISTRATION(AddBlockTest);
CPPUNIT_TEST_SUITE_REGISTRATION(MmapAreaTest);
CPPUNIT_TEST_SUITE_REGISTRATION(RoundTestSize);
//CPPUNIT_TEST_SUITE_REGISTRATION(UnmapAreaTest);

int main() {
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest(registry.makeTest());
	return !runner.run();
}
