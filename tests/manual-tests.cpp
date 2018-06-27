/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual-tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:05:47 by asenat            #+#    #+#             */
/*   Updated: 2018/05/27 15:15:16 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C" {
#include "malloc/malloc.h"
#include "unistd.h"
}

#include <vector>

int main(void)
{
	malloc(28);
	malloc(102);
	malloc(64);
	std::vector<void*> adresses;
	adresses.reserve(10);
	for (auto i = 0 ; i < 50; ++i)
		adresses.push_back(malloc(100));
	write(1, "---------\n", 10);
	show_alloc_mem();
	for (auto* adr : adresses)
		free(adr);
	write(1, "---------\n", 10);
	show_alloc_mem();
	return (0);
}
