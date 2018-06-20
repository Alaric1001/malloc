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
//	malloc(500);
//	malloc(5);
//	malloc(50);
//	malloc(2);
	malloc(65);
	malloc(70);
	malloc(23);
//	malloc(1);
	malloc(1025);
//	malloc(12);
//	malloc(275);
//	malloc(17);
//	malloc(1);
////	malloc(0);
	malloc(100);
	std::vector<void*> adresses;
	adresses.reserve(150);
	for (auto i = 0 ; i < 150; ++i)
		adresses.push_back(malloc(42));
	write(1, "---------\n", 10);
//	for (auto* adr : adresses)
//		free(adr);
//	write(1, "---------\n", 10);
	show_alloc_mem();
	return (0);
}
