/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest-join_free_block_around.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:43:00 by asenat            #+#    #+#             */
/*   Updated: 2018/05/23 18:43:37 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include <vector>
#include "tests/utils.hpp"

class JoinFreeBlocksTest : public CppUnit::TestCase {
private:

public:
	CPPUNIT_TEST_SUITE(JoinFreeBlocksTest);
	CPPUNIT_TEST(no_free_blocks);
	CPPUNIT_TEST(free_block_after);
	CPPUNIT_TEST(free_block_after2);
	CPPUNIT_TEST(free_block_before);
	CPPUNIT_TEST(free_block_around);
	CPPUNIT_TEST_SUITE_END();

	void no_free_blocks() {
		SimulatedArea sim_area(128, false);
		sim_area.add_block(0, 5).add_block(sizeof(t_block) + 16, 6);
		t_block_location r{ nullptr, sim_area.area(), nullptr,
			                reinterpret_cast<t_block *>(sim_area.area() + 1), TINY };
		join_free_blocks_around(&r);
		bool check = sim_area == std::vector<SimulatedArea::Block>{{16}, {6}};
		CPPUNIT_ASSERT(check);
	}

	void free_block_after() {
		SimulatedArea sim_area(128, false);
		sim_area.add_block(0, 5).add_block(sizeof(t_block) + 16, 16, true);
		t_block_location r{ nullptr, sim_area.area(), nullptr,
			                reinterpret_cast<t_block *>(sim_area.area() + 1), TINY };
		sim_area.simulate_in_true_area(TINY,
		                               [&r] { join_free_blocks_around(&r); });
		bool check = sim_area == std::vector<SimulatedArea::Block>{ { 16 * 2 + sizeof(t_block), true } };
		CPPUNIT_ASSERT(check);
		unmap_everything(false);
	}
	
	void free_block_after2() {
		SimulatedArea sim_area(128, false);
		sim_area.add_block(0, 5).add_block(sizeof(t_block) + 16, 16, true).add_block((sizeof(t_block) + 16) * 2, 9);
		t_block_location r{ nullptr, sim_area.area(), nullptr,
			                reinterpret_cast<t_block *>(sim_area.area() + 1), TINY };
		sim_area.simulate_in_true_area(TINY,
		                               [&r] { join_free_blocks_around(&r); });
		bool check = sim_area == std::vector<SimulatedArea::Block>{ { sizeof(t_block) + 16 * 2, true }, {9}};
		CPPUNIT_ASSERT(check);
		unmap_everything(false);
	}
	
	void free_block_before() {
		SimulatedArea sim_area(128, false);
		sim_area.add_block(0, 16, true).add_block(sizeof(t_block) + 16, 6).add_block((sizeof(t_block) + 16) * 2, 9);
		t_block_location r{ nullptr, sim_area.area(),
			                reinterpret_cast<t_block *>(sim_area.area() + 1),
			                reinterpret_cast<t_block *>(sim_area.area() + 3), TINY };
		sim_area.simulate_in_true_area(TINY,
		                               [&r] { join_free_blocks_around(&r); });
		bool check = sim_area == std::vector<SimulatedArea::Block>{ { 16 * 2 + sizeof(t_block), true }, {9}};
		CPPUNIT_ASSERT(check);
		unmap_everything(false);
	}
	
	void free_block_around() {
		SimulatedArea sim_area(128, false);
		sim_area.add_block(0, 16, true).add_block(sizeof(t_block) + 16, 6).add_block((sizeof(t_block) + 16) * 2, 16, true);
		t_block_location r{ nullptr, sim_area.area(),
			                reinterpret_cast<t_block *>(sim_area.area() + 1),
			                reinterpret_cast<t_block *>(sim_area.area() + 3), TINY };
		sim_area.simulate_in_true_area(TINY,
		                               [&r] { join_free_blocks_around(&r); });
		bool check = sim_area == std::vector<SimulatedArea::Block>{ { (16 + sizeof(t_block)) * 2 + 16, true }};
		CPPUNIT_ASSERT(check);
		unmap_everything(false);
	}
/*	
	void free_block_around() {
		auto sim_area = get_simulation_area(256, {{5, true}, {6}});
		t_area* area = (t_area*)&sim_area[0];
		auto last_size = area->blocks->next->next->size;
		t_block_location r{nullptr, area, area->blocks, area->blocks->next};
		join_free_blocks_around(&r);
		CPPUNIT_ASSERT(check_sim_area(area, {{5 + sizeof(t_block) + 6 + sizeof(t_block) + last_size, true}}));
	}
	*/
};

CPPUNIT_TEST_SUITE_REGISTRATION(JoinFreeBlocksTest);

int main() {
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest(registry.makeTest());
	return !runner.run();
}
