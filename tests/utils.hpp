/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:28:24 by asenat            #+#    #+#             */
/*   Updated: 2018/05/24 17:07:33 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef UTILS_HPP
# define UTILS_HPP

extern "C" {
#include "utils/utils.h"
#include "sys/mman.h"
}
#include <cassert>

inline void unmap_everything(bool unmap_for_real = true) {
	auto unmap = [&](t_area** area) {
		auto* it = *area;
		while (it) {
			auto* next = it->next;
			if (unmap_for_real)
				munmap(it, it->size);
			it = next;
		}
		*area = nullptr;
	};
	unmap(&g_areas[0].area);
	g_areas[0].total_size = 0;
	unmap(&g_areas[1].area);
	g_areas[1].total_size = 0;
	unmap(&g_areas[2].area);
	g_areas[2].total_size = 0;
}

class SimulatedArea {
private:
	std::vector<char> m_mem;
	t_area* m_area = nullptr;
	t_block* m_free_list = nullptr;
public:
	SimulatedArea(std::size_t size, bool default_block = true) : m_mem(size, 0) {
		m_area = reinterpret_cast<t_area*>(&m_mem[0]);
		m_area->size = size;
		if (default_block) {
			m_free_list = reinterpret_cast<t_block *>(&m_mem[sizeof(t_area)]);
			m_free_list->size = size - (sizeof(t_area) + sizeof(t_block));
		}
	}

	SimulatedArea& add_block(std::size_t location, std::size_t size, bool free = false) {
		location += sizeof(t_area);
		assert(location + sizeof(t_block) + size <= m_mem.size());
		t_block* block = reinterpret_cast<t_block*>(&m_mem[location]);
		block->size = size;
		block->next_free = nullptr;
		if (not free) return *this;
		if (not m_free_list)
			m_free_list = block;
		else {
			t_block* elem;
			for (elem = m_free_list; elem->next_free; elem = elem->next_free);
			elem->next_free = block;
		}
		return *this;
	}
	t_area* area() { return m_area; }
	const t_area* area() const { return m_area; }
	t_block** d_free_list() { return &m_free_list; }
	t_block *free_list() { return m_free_list; }

	void chain(SimulatedArea& a) {
		t_block* elem;
		for (elem = m_free_list; elem->next_free; elem = elem->next_free);
		elem->next_free = a.free_list();
	}
};

//
//struct test_block_dat {
//	std::size_t size;
//	bool free = 0;
//};
//
//inline std::vector<char> get_simulation_area(std::size_t size,
//		const std::vector<test_block_dat>& blocks_sizes) {
//	std::vector<char> ret(size, '\0');
//	t_area area{size, nullptr};
//	memcpy(&ret[0], &area, sizeof(area));
//	auto shift = sizeof(area);
//	t_block* last_adr = nullptr;
//	for (const auto& s : blocks_sizes) {
//		t_block b{s.size, s.free, nullptr};
//		memcpy(&ret[shift], &b, sizeof(b));
//		if (last_adr)
//			last_adr->next = (t_block*)(&ret[shift]);
//		last_adr = (t_block*)(&ret[shift]);
//		shift += sizeof(b) + s.size;
//	}
//	if (size > shift and size - shift > sizeof(t_block) + 1)
//	{
//		t_block b{size - shift, 1, nullptr};
//		memcpy(&ret[shift], &b, sizeof(b));
//		if (last_adr)
//			last_adr->next = (t_block*)(&ret[shift]);
//	}
//	((t_area*)&ret[0])->blocks = (t_block*)(&ret[sizeof(t_area)]);
//	return ret;
//}
//
//inline bool check_sim_area(const t_area* area,
//		const std::vector<test_block_dat>& ref) {
//	t_block* it = area->blocks;
//	for (auto &dat : ref) {
//		if (dat.size != it->size) {
//			std::cout << "[Err] check_sim_area (size): " << dat.size << " != " << it->size << "\n";
//			return false;
//		}
//		if ((int)dat.free != it->free) {
//			std::cout << "[Err] check_sim_area (free): " << (int)dat.free << " != " << it->free << "\n";
//			return false;
//		}
//		it = it->next;
//	}
//	return true;
//}
//
//inline std::vector<t_area*> chain_areas(t_block_type type,
//		std::initializer_list<const std::vector<char>*> areas) {
//	std::vector<t_area*> ret;
//	t_area* last = nullptr;
//	ret.resize(areas.size());
//	auto i = 0;
//	for (auto* s_a : areas) {
//		t_area* a = (t_area*)&s_a->at(0);
//		if (last)
//			last->next = a;
//		else
//			g_areas[type].area = a;
//		last = a;
//		g_areas[type].total_size += a->size;
//		ret[i++] = a;
//	}
//	return ret;
//}
//
#endif
