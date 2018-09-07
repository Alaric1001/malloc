/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_tests.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat </var/spool/mail/asenat>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 20:05:37 by asenat            #+#    #+#             */
/*   Updated: 2018/09/06 17:23:15 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cppunit/TestAssert.h>
#include <cppunit/TestCase.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>

#include "tests/utils.hpp"

extern "C" {
#include "ft_malloc/malloc_data.h"
#include "ft_malloc/ft_malloc.h"
#include <string.h>
}
#include <memory>
#include <iostream>

#define BLOCK_SIZE(size) size + sizeof(t_block)

class AllocBlockTest : public CppUnit::TestCase {
public:
	CPPUNIT_TEST_SUITE(AllocBlockTest);
	CPPUNIT_TEST(not_found_check);
	CPPUNIT_TEST(enough_space_no_new_block);
	CPPUNIT_TEST(enough_space_new_block);
	CPPUNIT_TEST(no_space_after);
	CPPUNIT_TEST(space_after);
	CPPUNIT_TEST_SUITE_END();
	
	void not_found_check() {
		auto test = [](void* adr) {
			SimulatedArea sa(256, false);
			sa.add_block(0, 32).add_block(32, 128, true);
			sa.simulate_in_true_area(TINY, [&]() {
					ft_realloc(adr, 8);
			});
			bool check = sa == std::vector<SimulatedArea::Block>{{32, false}, {24, false}, {96, true}};
			CPPUNIT_ASSERT(check);
			unmap_everything(false);
		};
		test(nullptr);
		test(reinterpret_cast<void*>(0xbeef));
	}

	void enough_space_no_new_block() {
		auto test = [](std::size_t initial, std::size_t realloc, t_block_type type) -> bool {
			SimulatedArea sa(initial * 2, false, type);
			sa.add_block(0, initial);
			sa.simulate_in_true_area(type, [&]() {
					ft_realloc(reinterpret_cast<t_block*>(sa.area() + 1) + 1, realloc);
			});
			bool check = sa == std::vector<SimulatedArea::Block>{{BLOCK_SIZE(realloc), false}};
			unmap_everything(false);
			return check;
		};
		CPPUNIT_ASSERT(test(32, 15, TINY));
		CPPUNIT_ASSERT(not test(32, 19980, TINY));
		CPPUNIT_ASSERT(test(20480, 20453, SMALL));
	}

	void enough_space_new_block() {
		auto test = [](std::size_t initial, std::size_t realloc, t_block_type type) -> bool {
			SimulatedArea sa(initial * 2, false, type);
			sa.add_block(0, initial);
			sa.simulate_in_true_area(type, [&]() {
					ft_realloc(reinterpret_cast<t_block*>(sa.area() + 1) + 1, realloc);
			});
			bool check = sa == std::vector<SimulatedArea::Block>{{BLOCK_SIZE(realloc), false},
								{initial - round_size(type, realloc + sizeof(t_block)), true}};
			unmap_everything(false);
			return check;
		};
		CPPUNIT_ASSERT(test(64, 9, TINY));
		CPPUNIT_ASSERT(test(64, 15, TINY));
		CPPUNIT_ASSERT(not test(64, 49, TINY));
		CPPUNIT_ASSERT(test(20992, 20450, SMALL));
	}

	void no_space_after() {
		auto test = [] (std::size_t initial, std::size_t realloc) -> bool {
			SimulatedArea sa(4096, false, TINY);
			sa.add_block(0, initial).add_block(initial, 16).add_block(initial + 16, 1024, true);
			sa.simulate_in_true_area(TINY, [&]() {
					ft_realloc(reinterpret_cast<t_block*>(sa.area() + 1) + 1, realloc);
			});
			bool check = sa == std::vector<SimulatedArea::Block>{{initial, true}, {16, false}, {realloc + sizeof(t_block), false}};
			unmap_everything(false);
			return check;
		};
		CPPUNIT_ASSERT(test(16, 32));
	}
	
	void space_after() {
		auto test = [] (std::size_t initial, std::size_t realloc) -> bool {
			SimulatedArea sa(4096, false, TINY);
			sa.add_block(0, initial).add_block(initial, 1024, true);
			sa.simulate_in_true_area(TINY, [&]() {
					ft_realloc(reinterpret_cast<t_block*>(sa.area() + 1) + 1, realloc);
			});
			auto realloc_sz = realloc + sizeof(t_block);
			bool check = sa == std::vector<SimulatedArea::Block>{{realloc_sz},
				{1024 - (realloc_sz - initial), true}};
			unmap_everything(false);
			return check;
		};
		CPPUNIT_ASSERT(test(16, 32));
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION(AllocBlockTest);

int main() {
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest(registry.makeTest());
	return !runner.run();
}
