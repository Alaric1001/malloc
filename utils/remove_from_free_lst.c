/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_from_free_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:51:36 by asenat            #+#    #+#             */
/*   Updated: 2018/09/07 16:52:42 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

void	remove_from_free_lst(t_block_type type, const t_block *block)
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
	if (prev && iterator)
		prev->next_free = iterator->next_free;
	else if (iterator)
		g_areas[type].free_blocks = iterator->next_free;
}
