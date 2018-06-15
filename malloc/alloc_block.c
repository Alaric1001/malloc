/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:58:59 by asenat            #+#    #+#             */
/*   Updated: 2018/06/14 23:18:16 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc/algorithm.h"

#include "utils/utils.h"
#include "libft/output/output.h"
#include <stdio.h>

t_block	*alloc_block(t_block** it, t_block* last_it, size_t size)
{
	t_block *ret;
	t_block *next;

	ret = *it;
	if (ret->size < size)
		return NULL;
	if (ret->size > size + sizeof(t_block))
	{
		next = (t_block*)((char*)(ret + 1) + size);
		next->size = ret->size - (size + sizeof(t_block));
		next->next_free = ret->next_free;
		ret->next_free = next;
	}
	ret->size = size;
	if (!last_it)
	{
		*it = NULL;
		return ret;
	}
	last_it->next_free = ret->next_free;
	return ret;
}

t_block		*do_malloc(t_block_type type, size_t size)
{
	t_area **area;
	t_block *last_free;
	t_block **current_free;
	t_block	*ret;

	size = round_size(type, size);
	last_free = NULL;
	current_free = &g_areas[type].free_blocks;
	while (*current_free)
	{
		if ((ret = alloc_block(current_free, last_free, size)))
			return (ret);
		area = &(*area)->next;
	}
	if (!(*area = mmap_area(type, size)))
		return (NULL);
	if (*current_free)
		(*current_free)->next_free = (t_block *)*area + 1;
	last_free = *current_free;
	current_free = &(*current_free)->next_free;
	return (alloc_block(current_free, last_free, size));
}
