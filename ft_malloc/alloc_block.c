/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:58:59 by asenat            #+#    #+#             */
/*   Updated: 2018/09/04 10:35:00 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc/algorithm.h"

#include "utils/utils.h"
#include "libft/output/output.h"
#include <stdio.h>

t_block	*alloc_block(t_block_type type, t_block** it, t_block* last_it, size_t size)
{
	t_block *ret;
	t_block *next;
	size_t	rounded_size;

	ret = *it;
	if (ret->size < size + sizeof(t_block))
		return NULL;
	rounded_size = round_size(type, size + sizeof(t_block));
	if (ret->size > rounded_size + sizeof(t_block) + 1)
	{
		next = (t_block*)((char*)ret + rounded_size);
		next->size = ret->size - rounded_size;
		next->next_free = ret->next_free;
		ret->next_free = next;
	}
	else if (ret->size != rounded_size)
		return NULL;
	ret->size = size + sizeof(t_block);
	if (!last_it)
		*it = ret->next_free;
	else
		last_it->next_free = ret->next_free;
	ret->next_free = NULL;
	return ret;
}

t_block		*do_malloc(t_block_type type, size_t size)
{
	t_area **area;
	t_block *last_free;
	t_block **current_free;
	t_block	*tmp;
	last_free = NULL;
	current_free = &g_areas[type].free_blocks;
	while (*current_free)
	{
		if ((tmp = alloc_block(type, current_free, last_free, size)))
			return (tmp);
		current_free = &(*current_free)->next_free;
	}
	area = &g_areas[type].area;
	while (*area)
		area = &(*area)->next;
	if (!(*area = mmap_area(type, size)))
		return (NULL);
	*current_free = (t_block*)((*area) + 1);
	return (alloc_block(type, current_free, last_free, size));
}
