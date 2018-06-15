#include <cppunit/TestAssert.h>
#include <cppunit/TestCase.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>

extern "C" {
#include "malloc/malloc_data.h"
#include "malloc/algorithm.h"
#include <string.h>
}

#include <memory>


class AllocBlockTest : public CppUnit::TestCase {
private:
	void init_mem(char* mem, std::size_t size) {
		t_block b = {size - sizeof(t_block), 1, nullptr};
		memcpy(mem, &b, sizeof(t_block));
	}
public:
	CPPUNIT_TEST_SUITE(AllocBlockTest);
	CPPUNIT_TEST(basic_checks);
	CPPUNIT_TEST(two_different_size);
	CPPUNIT_TEST(three_different_size);
	CPPUNIT_TEST(not_enough_space);
	CPPUNIT_TEST(just_enough_space);
	CPPUNIT_TEST(free_block_before);
	CPPUNIT_TEST_SUITE_END();

	void basic_checks() {
//		auto mem = &get_fresh_mem(256)[0];
		char mem[256];
		std::size_t real_mem_size = 256 - sizeof(t_block);
		init_mem(mem, 256);
		t_block* first = alloc_block((t_block*)&mem[0], 64);
		t_block* second = first->next;
		CPPUNIT_ASSERT(second);
		CPPUNIT_ASSERT_EQUAL(64ul, first->size);
		CPPUNIT_ASSERT_EQUAL(real_mem_size - sizeof(t_block) - 64, second->size);
		CPPUNIT_ASSERT(second->free);
		CPPUNIT_ASSERT_EQUAL(64ul + sizeof(t_block), static_cast<std::size_t>((char*)second - (char*)first));
	}

	void two_different_size() {
		char mem[256];
		std::size_t real_mem_size = 256 - sizeof(t_block);
		init_mem(mem, 256);
		t_block* first = alloc_block((t_block*)&mem[0], 2);
		CPPUNIT_ASSERT(first);
		CPPUNIT_ASSERT_EQUAL(2ul, first->size);
		t_block* second = alloc_block((t_block*)&mem[0], 64);
		CPPUNIT_ASSERT(second);
	}

	void three_different_size() {
		char mem[256];
		std::size_t real_mem_size = 256 - sizeof(t_block);
		init_mem(mem, 256);
		t_block* first = alloc_block((t_block*)&mem[0], 5);
		CPPUNIT_ASSERT(first);
		CPPUNIT_ASSERT_EQUAL(5ul, first->size);
		t_block* second = alloc_block((t_block*)&mem[0], 64);
		CPPUNIT_ASSERT_EQUAL(64ul, second->size);
		CPPUNIT_ASSERT(second);
		t_block* third = alloc_block((t_block*)&mem[0], 11);
		CPPUNIT_ASSERT_EQUAL(11ul, third->size);
		CPPUNIT_ASSERT(third);
	}

	void not_enough_space() {
		constexpr auto sz = sizeof(t_block) + 5;
		char mem[sz];
		init_mem(mem, sz);
		t_block* first = alloc_block((t_block*)&mem[0], 6);
		CPPUNIT_ASSERT(!first);
	}
	
	void just_enough_space() {
		constexpr auto sz = sizeof(t_block) + 5;
		char mem[sz];
		init_mem(mem, sz);
		t_block* first = alloc_block((t_block*)&mem[0], 5);
		CPPUNIT_ASSERT(first);
		CPPUNIT_ASSERT_EQUAL(5ul, first->size);
	}

	void free_block_before() {
		constexpr auto sz = sizeof(t_block) + 1 + sizeof(t_block) + 5;
		char mem[sz];
		init_mem(mem, sz);
		t_block* first = alloc_block((t_block*)&mem[0], 1);
		CPPUNIT_ASSERT(first);
		first->free = 1;
		t_block* second = alloc_block((t_block*)&mem[0], 5);
		CPPUNIT_ASSERT(first->free);
		CPPUNIT_ASSERT(!second->free);
		CPPUNIT_ASSERT_EQUAL(5ul, second->size);
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION(AllocBlockTest);

int main() {
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest(registry.makeTest());
	return !runner.run();
}
