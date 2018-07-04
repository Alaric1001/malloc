/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utest-join_free_block_around.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:43:00 by asenat            #+#    #+#             */
/*   Updated: 2018/07/04 18:17:26 by asenat           ###   ########.fr       */
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

#include <vector>
#include "tests/utils.hpp"

class DefragAroundAndFreeTest : public CppUnit::TestCase {
private:

public:
	CPPUNIT_TEST_SUITE(DefragAroundAndFreeTest);
	CPPUNIT_TEST(no_free_blocks);
	CPPUNIT_TEST(free_block_after);
	CPPUNIT_TEST(free_block_after2);
	CPPUNIT_TEST(free_block_before);
	CPPUNIT_TEST(free_block_around);
	CPPUNIT_TEST_SUITE_END();

	void no_free_blocks() {
		SimulatedArea sim_area(75, false);
		sim_area.add_block(0, 32).add_block(32, 16);
		t_block_location r{ nullptr, sim_area.area(), nullptr,
			                reinterpret_cast<t_block *>(sim_area.area() + 1), TINY };
		defrag_around_and_free(&r);
		bool check = sim_area == std::vector<SimulatedArea::Block>{{32}, {16}};
		CPPUNIT_ASSERT(check);
	}

	void free_block_after() {
		SimulatedArea sim_area(128, false);
		sim_area.add_block(0, 32).add_block(sizeof(t_block) + 16, 16, true);
		t_block_location r{ nullptr, sim_area.area(), nullptr,
			                reinterpret_cast<t_block *>(sim_area.area() + 1), TINY };
		sim_area.simulate_in_true_area(TINY,
		                               [&r] { defrag_around_and_free(&r); });
		bool check = sim_area == std::vector<SimulatedArea::Block>{ { 48, true } };
		CPPUNIT_ASSERT(check);
		unmap_everything(false);
	}
	
	void free_block_after2() {
		SimulatedArea sim_area(128, false);
		sim_area.add_block(0, 32).add_block(32, 32, true).add_block(32 * 2, 9);
		t_block_location r{ nullptr, sim_area.area(), nullptr,
			                reinterpret_cast<t_block *>(sim_area.area() + 1), TINY };
		sim_area.simulate_in_true_area(TINY,
		                               [&r] { defrag_around_and_free(&r); });
		bool check = sim_area == std::vector<SimulatedArea::Block>{ { 64 , true }, {9}};
		CPPUNIT_ASSERT(check);
		unmap_everything(false);
	}
	
	void free_block_before() {
		SimulatedArea sim_area(128, false);
		sim_area.add_block(0, 32, true).add_block(32, 32).add_block(32 * 2, 9);
		t_block_location r{ nullptr, sim_area.area(),
			                reinterpret_cast<t_block *>(sim_area.area() + 1),
			                reinterpret_cast<t_block *>(sim_area.area() + 3), TINY };
		sim_area.simulate_in_true_area(TINY,
		                               [&r] { defrag_around_and_free(&r); });
		bool check = sim_area == std::vector<SimulatedArea::Block>{ { 64, true }, {9}};
		CPPUNIT_ASSERT(check);
		unmap_everything(false);
	}
	
	void free_block_around() {
		SimulatedArea sim_area(128, false);
		sim_area.add_block(0, 32, true).add_block(32, 32).add_block(64, 32, true);
		t_block_location r{ nullptr, sim_area.area(),
			                reinterpret_cast<t_block *>(sim_area.area() + 1),
			                reinterpret_cast<t_block *>(sim_area.area() + 3), TINY };
		sim_area.simulate_in_true_area(TINY,
		                               [&r] { defrag_around_and_free(&r); });
		bool check = sim_area == std::vector<SimulatedArea::Block>{ { 32 * 3, true } };
		CPPUNIT_ASSERT(check);
		unmap_everything(false);
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION(DefragAroundAndFreeTest);

int main() {
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest(registry.makeTest());
	return !runner.run();
}
