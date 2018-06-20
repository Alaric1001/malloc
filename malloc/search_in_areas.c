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

static int	search_addr(const t_area *area, const char* adr,
				t_block_location *result)
{
	size_t cursor;
	t_block *iterator;

	cursor = sizeof(area);
	while ((int)(area->size - cursor) > (int)sizeof(t_block))
	{
		iterator = (t_block *)((char *)(area) + cursor);
		if (!is_in_free_list(iterator, g_areas[val->type].free_blocks)
				&& (char*)(iterator + 1) == adr)
		{
			result->loc = iterator;
			return (1);
		}
		cursor += round_size(val->type, iterator->size) + sizeof(t_block);
		result->prev = iterator;
	}
	return (0);
}

int			search_in_area(const t_area* area,
				const char *adr, t_block_location *result)
{
	char	*area_pos;

	while (area) {
		area_pos = (const char*)area;
		result->loc_area = area;
		if (adr > area_pos && adr < area_pos + area->size)
			return (search_addr(area, adr, result))
		result->prev_area = area;
		area = area->next;
	}
	return (0);
}

int			search_in_areas(const void *adr, t_block_location *result)
{
	if (search_in_area(g_areas[TINY].area, (const char*)adr, result))
		return (1);
	if (search_in_area(g_areas[SMALL].area, (const char*)adr, result))
		return (1);
	if (search_in_area(g_areas[LARGE].area, (const char*)adr, result))
		return (1);
	return (0);
}