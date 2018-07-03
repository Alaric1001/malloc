#include <cppunit/TestAssert.h>
#include <cppunit/TestCase.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>

#include "tests/utils.hpp"

extern "C" {
#include "ft_malloc/malloc_data.h"
#include "ft_malloc/algorithm.h"
#include <string.h>
}
#include <memory>
#include <iostream>


class AllocBlockTest : public CppUnit::TestCase {
public:
	CPPUNIT_TEST_SUITE(AllocBlockTest);
	CPPUNIT_TEST(too_small);
	CPPUNIT_TEST(one_block);
	CPPUNIT_TEST(two_blocks_second_allocated);
	CPPUNIT_TEST(two_blocks_first_allocated);
	CPPUNIT_TEST(chained_areas);
	CPPUNIT_TEST_SUITE_END();

	void too_small() {
		t_block b;
		b.size = 1;
		t_block *b_ptr = &b;
		CPPUNIT_ASSERT(not alloc_block(TINY, &b_ptr, nullptr, 2));
	}

	void one_block() {
		SimulatedArea sarea(128);
		std::size_t real_mem_size = 128 - sizeof(t_area) - sizeof(t_block);
		t_block* first = alloc_block(TINY, sarea.d_free_list(), nullptr, 12);
		t_block *second =
		reinterpret_cast<t_block *>(reinterpret_cast<char*>(first + 1) + 16);
		CPPUNIT_ASSERT(second);
		CPPUNIT_ASSERT(!first->next_free);
		CPPUNIT_ASSERT_EQUAL(12ul + sizeof(t_block), first->size);
		CPPUNIT_ASSERT_EQUAL(real_mem_size - sizeof(t_block) - 16, second->size);
		CPPUNIT_ASSERT_EQUAL(16ul + sizeof(t_block),
							static_cast<std::size_t>((char *)second - (char *)first));
		CPPUNIT_ASSERT_EQUAL(sarea.free_list(), second);
	}

	void two_blocks_second_allocated() {
		SimulatedArea sarea(128, false);
		sarea.add_block(0, 2, true).add_block(sizeof(t_block) + 2, 16 + sizeof(t_block), true);
		auto* nxt = sarea.free_list()->next_free;
		t_block* block = alloc_block(TINY, &nxt, sarea.free_list(), 16);
		CPPUNIT_ASSERT(block);
		CPPUNIT_ASSERT_EQUAL(16ul + sizeof(t_block), block->size);
		CPPUNIT_ASSERT(not sarea.free_list()->next_free);
	}

	void two_blocks_first_allocated() {
		SimulatedArea sarea(128, false);
		sarea.add_block(0, 16 + sizeof(t_block), true).add_block(sizeof(t_block) * 2, 16, true);
		auto* old_first_elem = sarea.free_list()->next_free;
		t_block* block = alloc_block(TINY, sarea.d_free_list(), nullptr, 2);
		CPPUNIT_ASSERT(block);
		CPPUNIT_ASSERT_EQUAL(2 + sizeof(t_block), block->size);
		CPPUNIT_ASSERT_EQUAL(old_first_elem, sarea.free_list());
		CPPUNIT_ASSERT(not sarea.free_list()->next_free);
	}

	void chained_areas() {
		SimulatedArea sarea(128, false);
		SimulatedArea sarea2(64);
		sarea.add_block(0, 2, true).add_block(sizeof(t_block) + 2, 16 + sizeof(t_block), true);
		sarea.chain(sarea2);
		auto* nxt = sarea.free_list()->next_free;
		t_block* block = alloc_block(TINY, &nxt, sarea.free_list(), 12);
		CPPUNIT_ASSERT(block);
		CPPUNIT_ASSERT_EQUAL(12 + sizeof(t_block), block->size);
		CPPUNIT_ASSERT_EQUAL(sarea2.free_list(), sarea.free_list()->next_free);
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION(AllocBlockTest);

int main() {
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest(registry.makeTest());
	return !runner.run();
}
