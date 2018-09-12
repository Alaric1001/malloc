/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_from_free_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:51:36 by asenat            #+#    #+#             */
/*   Updated: 2018/09/11 18:01:13 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

void	remove_from_free_lst(t_block_type type, t_block *block)
{
	t_block *iterator;
	t_block *prev;

	iterator = g_areas[type].free_blocks;
	prev = NULL;
	while (iterator && iterator != block)
	{
		prev = iterator;
		iterator = iterator->next_free;
	}
	remove_from_free_lst_with_prev(type, block, prev);
}

void	remove_from_free_lst_with_prev(t_block_type type, t_block *block,
		t_block *prev)
{
	if (!block)
		return ;
	if (prev)
		prev->next_free = block->next_free;
	else
		g_areas[type].free_blocks = block->next_free;
	block->next_free = NULL;
}
