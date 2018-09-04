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
	auto node_handler = map.extract(map.begin()->first);
	--(node_handler.key());
	ret.insert(std::move(node_handler));
	return ret;
}

int main () {
	constexpr int turns = 300;
	constexpr std::size_t max_size = 250;
	std::multimap<int, void*> map;
	std::random_device rd;
	auto seed = 2933141873;
	std::mt19937 gen(seed);
	std::uniform_int_distribution<> size(1, max_size);
	std::uniform_int_distribution<> longevity(1, 25);
	std::ofstream log("debug.log", std::ios::out | std::ios::trunc);

	std::cerr << "Seed: " << seed << std::endl;
	for (auto i = 0; i < turns; ++i) {
		auto to_free = map.equal_range(0);
		for(auto e = to_free.first; e != to_free.second; ++e) {
			log << "Freeing address: " << std::hex << e->second << std::endl;
			ft_free(e->second);
		}
		map.erase(0);
		map = decrement_keys(map);
		auto msize = size(gen);
		void* addr = ft_malloc(msize);
		log << "Mallocing size= " << std::dec <<  msize <<
			" addr= " << std::hex << addr << std::endl;
		map.insert({longevity(gen), addr});
	}
	ft_show_alloc_mem();
	log.close();
	return 0;
}
