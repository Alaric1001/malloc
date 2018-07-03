/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual-tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:05:47 by asenat            #+#    #+#             */
/*   Updated: 2018/07/04 00:08:31 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
#include "ft_malloc/ft_malloc.h"
#include "unistd.h"
}

#include <vector>

int main(void)
{
	ft_malloc(28);
	ft_malloc(102);
	ft_malloc(64);
	auto* t = ft_malloc(1024);
	ft_malloc(1025);
	std::vector<void*> adresses;
	adresses.reserve(50);
	for (auto i = 0 ; i < 50; ++i)
		adresses.push_back(ft_malloc(90 + i));
	write(1, "---------\n", 10);
//	ft_show_alloc_mem();
	ft_free(t);
	for (auto i = 5u; i < adresses.size() - 5; ++i)
		ft_free(adresses[i]);
	ft_free(adresses[2]);
	ft_free(adresses[0]);
	ft_free(adresses[1]);
	write(1, "---------\n", 10);
	ft_show_alloc_mem();
	return (0);
}
