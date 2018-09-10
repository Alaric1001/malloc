/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_areas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 17:01:37 by asenat            #+#    #+#             */
/*   Updated: 2018/09/10 14:25:55 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc/algorithm.h"

#include "utils/utils.h"
#include "libft/memory/memory.h"

static int	search_addr(const t_area *area,
		const char *adr, t_block_location *result)
{
	size_t	cursor;
	t_block	*iterator;

	cursor = sizeof(t_area);
	while ((intmax_t)(area->size - cursor) > (int)sizeof(t_block))
	{
		iterator = (t_block *)((char *)(area) + cursor);
		if ((char*)(iterator + 1) == adr)
		{
			result->loc = iterator;
			return (1);
		}
		cursor += round_size(result->type, iterator->size);
	}
	return (0);
}

int			search_in_area(t_area *area,
		const char *adr, t_block_location *result)
{
	char	*area_pos;

	while (area)
	{
		area_pos = (char*)area;
		result->loc_area = area;
		if (adr > area_pos && adr < area_pos + area->size)
			return (search_addr(area, adr, result));
		result->prev_area = area;
		area = area->next;
	}
	ft_bzero(result, sizeof(t_block_location));
	return (0);
}

int			search_in_areas(const void *adr, t_block_location *result)
{
	if (!adr)
		return (0);
	result->type = TINY;
	if (search_in_area(g_areas[TINY].area, (const char*)adr, result))
		return (1);
	result->type = SMALL;
	if (search_in_area(g_areas[SMALL].area, (const char*)adr, result))
		return (1);
	result->type = LARGE;
	if (search_in_area(g_areas[LARGE].area, (const char*)adr, result))
		return (1);
	return (0);
}
