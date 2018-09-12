extern "C" {
#include "ft_malloc/ft_malloc.h"
}
#include <random>
#include <map>
#include <iostream>
#include <fstream>

std::multimap<int, void*> decrement_keys(std::multimap<int, void*> &map) {
	if (map.empty()) return map;
	std::multimap<int, void*> ret;
	while (not map.empty()) {
		auto i = map.begin()->first;
		auto range = map.equal_range(i);
		for (auto e = range.first; e != range.second; ++e)
			ret.insert({e->first - 1, e->second});
		map.erase(i);
	}
	return ret;
}

int main () {
	constexpr int turns = 500;
	constexpr std::size_t max_size = 50;
	std::multimap<int, void*> map;
	std::random_device rd;
	auto seed = rd();
	std::mt19937 gen(seed);
	std::uniform_int_distribution<> size(0, max_size);
	std::uniform_int_distribution<> longevity(1, 50);
	std::ofstream log("debug.log", std::ios::out | std::ios::trunc);

	std::cerr << "Seed: " << seed << std::endl;
	for (auto i = 0; i < turns; ++i) {
		// Free
		auto to_free = map.equal_range(0);
		for(auto e = to_free.first; e != to_free.second; ++e) {
			log << "Freeing address: " << std::hex << e->second << std::endl;
			ft_free(e->second);
		}
		// Realloc
		map.erase(0);
		auto to_realloc = map.equal_range(3);
		for(auto e = to_realloc.first; e != to_realloc.second; ++e) {
			auto* tmp_a = e->second;
			auto rsize = size(gen);
			e->second = ft_realloc(e->second, rsize);
			log << "Reallocing address: " << std::hex << tmp_a << " -> " << e->second << std::endl;
		}
		map = decrement_keys(map);
		// Alloc
		auto msize = size(gen);
		char* addr = static_cast<char*>(ft_calloc(1, msize));
		for (auto i = 0; i < msize; ++i)
			addr[i] = 42;
		log << "Mallocing size= " << std::dec <<  msize <<
			" addr= " << std::hex << static_cast<void*>(addr) << std::endl;
		map.insert({longevity(gen), addr});
	}
	ft_show_alloc_mem();
	log.close();
	return 0;
}
