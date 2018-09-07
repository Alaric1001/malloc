/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:58:59 by asenat            #+#    #+#             */
/*   Updated: 2018/09/07 11:21:33 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc/algorithm.h"

#include "utils/utils.h"
#include "libft/output/output.h"
#include <stdio.h>

t_block		*do_malloc(t_block_type type, size_t size)
{
	t_area **area;
	t_block **current_free;
	t_block	*tmp;

	current_free = &g_areas[type].free_blocks;
	while (*current_free)
	{
		if ((tmp = alloc_block(type, current_free, size)))
			return (tmp);
		current_free = &(*current_free)->next_free;
	}
	area = &g_areas[type].area;
	while (*area)
		area = &(*area)->next;
	if (!(*area = mmap_area(type, size)))
		return (NULL);
	*current_free = (t_block*)((*area) + 1);
	return (alloc_block(type, current_free, size));
}

t_block	*alloc_block(t_block_type type, t_block** it, size_t size)
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
	*it = ret->next_free;
	ret->next_free = NULL;
	return ret;
}
