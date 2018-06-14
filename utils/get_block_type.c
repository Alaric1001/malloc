/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_block_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:27:06 by asenat            #+#    #+#             */
/*   Updated: 2018/05/13 13:25:54 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc/malloc_data.h"

#include <unistd.h>
#include <stdio.h>

t_block_type	get_block_type(size_t size)
{
	int page_size;

	page_size = getpagesize();
	if (size < (page_size * TINY_AREA_SIZE - sizeof(t_area)
				- 100 * sizeof(t_block)) / 100)
		return TINY;
	if (size < (page_size * SMALL_AREA_SIZE - sizeof(t_area)
				- 100 * sizeof(t_block)) / 100)
		return SMALL;
	return LARGE;
}
