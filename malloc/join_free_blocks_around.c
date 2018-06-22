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

void	join_free_blocks_around(t_block_type type, const t_block_location *location)
{
	t_block	*current;
	t_block	*prev_free;
	t_block* next;

	current = location->loc;
	prev_free = location->prev_free;
	next = (t_block*)((char*)(current + 1) + current->size);
	if (prev_free && current - (prev_free + sizeof(t_block)) == (long)prev_free->size)
		prev_free->size = current->size + sizeof(t_block) + prev_free->size;
	if (prev_free && prev_free->next_free == next )
	{
		current->size = next->size + sizeof(t_block) + current->size;
		prev_free->next_free = next->next_free;
	}
	else if (g_areas[type].free_blocks == next)
	{
		current->size = next->size + sizeof(t_block) + current->size;
		g_areas[type].free_blocks = next->next_free;
	}
}
