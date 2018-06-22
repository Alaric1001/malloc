/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_areas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 17:01:37 by asenat            #+#    #+#             */
/*   Updated: 2018/05/21 16:42:05 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc/algorithm.h"
#include "utils/utils.h"

static int search_addr(t_block_type type, const t_area *area, const char *adr, t_block_location *result)
{
	size_t cursor;
	int in_free_list;
	t_block *iterator;

	cursor = sizeof(t_area);
	while ((int)(area->size - cursor) > (int)sizeof(t_block))
	{
		iterator = (t_block *)((char *)(area) + cursor);
		in_free_list = is_in_free_list(iterator, g_areas[type].free_blocks);
		if (!in_free_list && (char*)(iterator + 1) == adr)
		{
			result->loc = iterator;
			return (1);
		}
		else if (in_free_list) 
			result->prev_free = iterator;
		cursor += round_size(type, iterator->size) + sizeof(t_block);
	}
	return (0);
}

int			search_in_area(t_block_type type,
				const char *adr, t_block_location *result)
{
	char	*area_pos;
	t_area *area;

	area = g_areas[type].area;
	while (area) {
		area_pos = (char*)area;
		result->loc_area = area;
		if (adr > area_pos && adr < area_pos + area->size)
			return (search_addr(type, area, adr, result));
		result->prev_area = area;
		area = area->next;
	}
	return (0);
}

int			search_in_areas(const void *adr, t_block_location *result)
{
	if (search_in_area(TINY, (const char*)adr, result))
		return (1);
	if (search_in_area(SMALL, (const char*)adr, result))
		return (1);
	if (search_in_area(LARGE, (const char*)adr, result))
		return (1);
	return (0);
}
