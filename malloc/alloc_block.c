/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 14:58:59 by asenat            #+#    #+#             */
/*   Updated: 2018/05/25 15:24:26 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc/algorithm.h"

#include "utils/utils.h"
#include "libft/output/output.h"
#include <stdio.h>

static int		is_allocable(t_block *block, size_t size)
{
	return (block->free && block->size >= size);
}

t_block	*alloc_block(t_block** it, t_block* last_it, size_t size)
{
//	size_t	space_left;
//	t_block	*new_block;
//
//	while (iterator->next && !is_allocable(iterator, size))
//		iterator = iterator->next;
//	if (!is_allocable(iterator, size) && !iterator->next)
//			return (NULL);
//	space_left = iterator->size - size;
//	new_block = NULL;
//	if (space_left > sizeof(t_block))
//	{
//		new_block = add_new_block(((char*)(iterator + 1)) + size,
//				space_left);
//	}
//	iterator->free = 0;
//	iterator->next = new_block;
//	iterator->size = size;
//	return (iterator);
}

t_block		*do_malloc(t_block_type type, size_t size)
{
	t_area	**area;
	t_block	*last_free;
	t_block **current_free;

	last_free = NULL;
	current_free = &g_areas[type].free_blocks;
	while (*current_free)
	{
		if ((ret = alloc_block(last_free, current_free, size)))
		   	return (ret);
		last_free = *current_free;
		current_free = &(*current_free)->next;
	}
	area = &g_areas[type].area;
	while (*area)
		area = &(*area)->next;
	if (!(*area = mmap_area(type, size)))
		return (NULL);
	if (*current_free)
		(*current_free)->next = (t_block *)*area + 1;
	last_free = current_free;
	current_free = &(*current_free)->next;
	return (alloc_block(last_free, current_free, size));
}
