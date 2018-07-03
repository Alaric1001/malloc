/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest-search_in_areas.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:39:03 by asenat            #+#    #+#             */
/*   Updated: 2018/06/30 01:10:09 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cppunit/TestAssert.h>
#include <cppunit/TestCase.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>

extern "C" {
#include "ft_malloc/malloc_data.h"
#include "ft_malloc/algorithm.h"
#include <string.h>
}

#include "tests/utils.hpp"
#include <vector>

class SearchInAreaTest : public CppUnit::TestCase
{
	public:
	CPPUNIT_TEST_SUITE(SearchInAreaTest);
	CPPUNIT_TEST(test_not_found);
	CPPUNIT_TEST(match_in_first_place);
	CPPUNIT_TEST(match_in_second_place_free_before);
	CPPUNIT_TEST(match_in_second_place_alloc_before);
	CPPUNIT_TEST(match_in_second_area);
	CPPUNIT_TEST_SUITE_END();

	void test_not_found() {
		t_block_location r{nullptr, nullptr, nullptr, nullptr};
		SimulatedArea sim_a(256);
		t_area* area = sim_a.area();
		sim_a.set_in_g_areas(TINY);
		auto found = search_in_area(area, reinterpret_cast<char*>(0xbeef), &r);
		CPPUNIT_ASSERT(!found);
		found = search_in_area(area, reinterpret_cast<char*>(area + 1) + 1 , &r);
		CPPUNIT_ASSERT(!found);
		unmap_everything(false);
	}

	void match_in_first_place() {
		t_block_location r{nullptr, nullptr, nullptr, nullptr};
		SimulatedArea sim_a(90, false);
		sim_a.add_block(0, 16 + sizeof(t_block)).add_block(16 + sizeof(t_block), 32);
		t_area* area = sim_a.area();
		sim_a.set_in_g_areas(TINY);
		auto found = search_in_area(area, ((char*)(area + 1) + sizeof(t_block)), &r);
		CPPUNIT_ASSERT(found);
		CPPUNIT_ASSERT(!r.prev_area);
		CPPUNIT_ASSERT_EQUAL(area, r.loc_area);
		CPPUNIT_ASSERT(!r.prev_free);
		CPPUNIT_ASSERT_EQUAL(reinterpret_cast<t_block*>(area + 1), r.loc);
		unmap_everything(false);
	}

	void match_in_second_place_free_before() {
		t_block_location r{nullptr, nullptr, nullptr, nullptr};
		SimulatedArea sim_a(90, false);
		sim_a.add_block(0, 16 + sizeof(t_block), true).add_block(16 + sizeof(t_block), 32);
		t_area* area = sim_a.area();
		sim_a.set_in_g_areas(TINY);
		char *first_block = reinterpret_cast<char *>(area + 1);
		auto found = search_in_area(area, first_block + sizeof(t_block) * 2 + 16, &r);
		CPPUNIT_ASSERT(found);
		CPPUNIT_ASSERT(!r.prev_area);
		CPPUNIT_ASSERT_EQUAL(area, r.loc_area);
		CPPUNIT_ASSERT(!r.prev_free);
		CPPUNIT_ASSERT_EQUAL(reinterpret_cast<t_block *>(first_block + sizeof(t_block) + 16), r.loc);
		unmap_everything(false);
	}

	void match_in_second_place_alloc_before() {
		t_block_location r{nullptr, nullptr, nullptr, nullptr};
		SimulatedArea sim_a(90, false);
		sim_a.add_block(0, 16 + sizeof(t_block)).add_block(16 + sizeof(t_block), 32);
		t_area* area = sim_a.area();
		sim_a.set_in_g_areas(TINY);
		char *first_block = reinterpret_cast<char *>(area + 1);
		auto found = search_in_area(area, first_block + sizeof(t_block) * 2 + 16, &r);
		CPPUNIT_ASSERT(found);
		CPPUNIT_ASSERT(!r.prev_area);
		CPPUNIT_ASSERT_EQUAL(area, r.loc_area);
		CPPUNIT_ASSERT(!r.prev_free);
		CPPUNIT_ASSERT_EQUAL(reinterpret_cast<t_block *>(first_block + sizeof(t_block) + 16), r.loc);
		unmap_everything(false);
	}

	void match_in_second_area() {
		t_block_location r{nullptr, nullptr, nullptr, nullptr};
		SimulatedArea sim_a(90, false);
		sim_a.add_block(0, 16 + sizeof(t_block), true).add_block(16 + sizeof(t_block), 32);
		SimulatedArea sim_a2(90, false);
		sim_a2.add_block(0, 16 + sizeof(t_block)).add_block(16 + sizeof(t_block), 32);
		sim_a.chain(sim_a2);
		sim_a.set_in_g_areas(TINY);
		char *first_block = reinterpret_cast<char *>(sim_a2.area() + 1);
		auto found = search_in_area(sim_a.area(), first_block + sizeof(t_block) * 2 + 16, &r);
		CPPUNIT_ASSERT(found);
		CPPUNIT_ASSERT_EQUAL(sim_a.area(), r.prev_area);
		CPPUNIT_ASSERT_EQUAL(sim_a2.area(), r.loc_area);
		CPPUNIT_ASSERT(!r.prev_free);
		CPPUNIT_ASSERT_EQUAL(reinterpret_cast<t_block *>(first_block + sizeof(t_block) + 16), r.loc);
		unmap_everything(false);
	}

};

CPPUNIT_TEST_SUITE_REGISTRATION(SearchInAreaTest);

int main() {
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest(registry.makeTest());
	return !runner.run();
}
