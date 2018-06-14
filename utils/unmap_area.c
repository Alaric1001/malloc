/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unmap_area.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:22:07 by asenat            #+#    #+#             */
/*   Updated: 2018/05/25 15:22:26 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

#include <sys/mman.h>

void	unmap_area(t_block_type type, const t_block_location *locations)
{
	t_area *current;
	t_area *prev;

	current = locations->loc_area;
	prev = locations->prev_area;
	if (prev)
		prev->next = current->next;
	else
	{
		if (current->next)
			g_areas[type].area = current->next;
		else
			g_areas[type].area = NULL;
	}
	g_areas[type].total_size -= current->size;
	
	munmap(current, current->size);
}
