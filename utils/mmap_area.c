/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap_area.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:17:00 by asenat            #+#    #+#             */
/*   Updated: 2018/09/07 16:50:41 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

#include <sys/mman.h>
#include <unistd.h>
#include <sys/resource.h>

#include "libft/memory/memory.h"

static size_t	get_total_allocated_memory(void)
{
	return (g_areas[TINY].total_size +
			g_areas[SMALL].total_size +
			g_areas[LARGE].total_size);
}

static size_t	avoid_overflow(t_block_type type, size_t area_size)
{
	int				page_size;
	int				total_mem;
	struct rlimit	lim;

	if (getrlimit(RLIMIT_DATA, &lim) == -1)
		return (0);
	total_mem = get_total_allocated_memory();
	if (total_mem + area_size < lim.rlim_cur)
		return (area_size);
	if (type == LARGE)
		return (0);
	page_size = getpagesize();
	while (area_size > 0 && total_mem + area_size >= lim.rlim_cur)
		area_size -= page_size;
	return (area_size);
}

t_area			*mmap_area(t_block_type type, size_t size)
{
	size_t	area_size;
	t_area	*ret;
	void	*mapped_region;

	if (type == LARGE)
		area_size = size + sizeof(t_area) + sizeof(t_block);
	else
		area_size = get_area_size(type);
	if (!(area_size = avoid_overflow(type, area_size)))
		return (NULL);
	mapped_region = mmap(0, area_size, PROT_READ | PROT_WRITE
			, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (mapped_region == MAP_FAILED)
		return (NULL);
	g_areas[type].total_size += area_size;
	ret = (t_area*)mapped_region;
	ret->next = NULL;
	ret->size = area_size;
	add_new_block(ret + 1, area_size - sizeof(t_area));
	return (ret);
}
