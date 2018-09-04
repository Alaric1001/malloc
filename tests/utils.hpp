/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:28:24 by asenat            #+#    #+#             */
/*   Updated: 2018/08/23 14:27:15 by asenat           ###   ########.fr       */
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
	g_areas[0].free_blocks = nullptr;
	unmap(&g_areas[1].area);
	g_areas[1].total_size = 0;
	g_areas[1].free_blocks = nullptr;
	unmap(&g_areas[2].area);
	g_areas[2].total_size = 0;
	g_areas[2].free_blocks = nullptr;
}

class SimulatedArea {
public:
	struct Block { std::size_t size; bool free = false; };
	bool iter_area(const SimulatedArea &sim_area,
	               const std::function<bool(const t_block *)> &action) const
	{
		std::size_t cursor = sizeof(t_area);
		auto* area = sim_area.area();
		while (static_cast<intmax_t>(area->size - cursor)
				> static_cast<intmax_t>(sizeof(t_block))) {
			const t_block *block = reinterpret_cast<const t_block *>(
			reinterpret_cast<const char *>(area) + cursor);
			if (not action(block))
				return false;
			cursor += round_size(sim_area.type(), block->size);
		}
		return true;
	}

private:
	std::vector<char> m_mem;
	t_area* m_area = nullptr;
	t_block* m_free_list = nullptr;
	t_block_type m_type;
public:
	SimulatedArea(std::size_t size, bool default_block = true, t_block_type type = TINY)
	: m_mem(size, 0), m_type(type) {
		m_area = reinterpret_cast<t_area*>(&m_mem[0]);
		m_area->size = size;
		if (default_block) {
			m_free_list = reinterpret_cast<t_block *>(&m_mem[sizeof(t_area)]);
			m_free_list->size = size - (sizeof(t_area) + sizeof(t_block));
		}
	}

	SimulatedArea& add_block(std::size_t location, std::size_t size, bool free = false) {
		location += sizeof(t_area);
		assert(location + size <= m_mem.size());
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
	t_block_type type() const { return m_type; }
	t_block** d_free_list() { return &m_free_list; }
	t_block *free_list() { return m_free_list; }

	void chain(SimulatedArea& a) {
		t_block* elem;
		for (elem = m_free_list; elem->next_free; elem = elem->next_free);
		elem->next_free = a.free_list();
		area()->next = a.area();
	}

	void set_in_g_areas(t_block_type type) {
		g_areas[type].area = area();
		g_areas[type].free_blocks = free_list();
	}

	void simulate_in_true_area(t_block_type type, std::function<void(void)> f) {
		set_in_g_areas(type);
		f();
		m_free_list = g_areas[type].free_blocks;
	}

	bool operator==(const std::vector<Block>& rhs) const {
		bool ret = true;
		std::size_t i = 0;
		SimulatedArea::iter_area(*this, [&](const t_block *block) {
			if (i >= rhs.size())
				return false;
			const auto& ref = rhs[i++];
			if (block->size == ref.size and ref.free == is_in_free_list(block, this->m_free_list))
				return true;
			std::cerr << "[err] index=" << i - 1 << ", s=" << block->size
			          << ", f=" << is_in_free_list(block, this->m_free_list) << "\n";
			return ret = false;
		});
		return ret;
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
