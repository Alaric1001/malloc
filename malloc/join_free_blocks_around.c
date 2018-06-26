/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_free_blocks_around.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 18:00:01 by asenat            #+#    #+#             */
/*   Updated: 2018/05/19 18:23:47 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc/algorithm.h"

#include "utils/utils.h"

void			join_free_blocks_around(t_block_location *location)
{
	t_block	*current;
	t_block	*prev_free;
	t_block *next;

	current = location->loc;
	prev_free = location->prev_free;
	next = (t_block*)((char*)(current + 1) + round_size(location->type, current->size));
	if (prev_free && prev_free->next_free == next )
	{
		current->size = next->size + sizeof(t_block) + current->size;
		prev_free->next_free = next->next_free;
	}
	else if (!prev_free && g_areas[location->type].free_blocks == next)
	{
		current->size = next->size + sizeof(t_block) + current->size;
		g_areas[location->type].free_blocks = next->next_free;
	}
	if (prev_free && (char*)current - ((char*)(prev_free + 1)) == (long)prev_free->size)
	{
		prev_free->size = current->size + sizeof(t_block) + prev_free->size;
		location->loc = prev_free;
	}
	else if (prev_free)
	{
		current->next_free = prev_free->next_free;
		prev_free->next_free = current;
	}
	else
	{
		current->next_free = g_areas[location->type].free_blocks;
		g_areas[location->type].free_blocks = current;
	}
	location->loc->size = round_size(location->type, location->loc->size);
}
