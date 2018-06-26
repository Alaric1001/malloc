/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 17:09:26 by asenat            #+#    #+#             */
/*   Updated: 2018/05/26 18:44:37 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc/malloc.h"
#include "utils/utils.h"

#include "libft/output/obuff.h"
#include "libft/memory/memory.h"

#define FTMALL_SHOW_FREE 1

static void add_ptr_to_obuff(const void* ptr, t_obuff *obuff)
{
	ft_add_uint_base_to_obuff((uintmax_t)ptr, "0123456789ABCDEF", obuff);
}

static void display_blocks(const t_area_and_type *val, size_t *total_size, t_obuff *obuff)
{
	t_block *iterator;
	size_t	cursor;
	const t_area* area = val->area;

	cursor = sizeof(t_area);
	while ((int)(area->size - cursor) > (int)sizeof(t_block))
	{
		iterator = (t_block *)((char *)(area) + cursor);
		if (FTMALL_SHOW_FREE || !is_in_free_list(iterator, g_areas[val->type].free_blocks))
		{
			add_ptr_to_obuff(iterator + 1, obuff);
			ft_add_str_to_obuff(" - ", obuff);
			add_ptr_to_obuff((char*)(area) + iterator->size, obuff);
			ft_add_str_to_obuff(" : ", obuff);
			ft_add_uint_to_obuff(iterator->size, obuff);
			ft_add_str_to_obuff(" octet", obuff);
			if (iterator->size > 1 && iterator->size)
				ft_add_char_to_obuff('s', obuff);
			ft_add_char_to_obuff('\n', obuff);
			(*total_size) += iterator->size;
		}
		cursor += round_size(val->type, iterator->size) + sizeof(t_block);
	}
}

void			show_alloc_mem()
{
	t_area_and_type current;
	t_area* areas[3];
	t_obuff obuff;
	size_t	total_size;

	total_size = 0;
	areas[0] = g_areas[TINY].area;
	areas[1] = g_areas[SMALL].area;
	areas[2] = g_areas[LARGE].area;
	ft_bzero(&obuff, sizeof(t_obuff));
	obuff.fd = 1;
	while ((current = get_lowest_area(&areas[0], &areas[1], &areas[2])).area)
	{
		ft_add_str_to_obuff(get_type_str(current.type), &obuff);
		ft_add_str_to_obuff(" : ", &obuff);
		add_ptr_to_obuff(current.area, &obuff);
		ft_add_char_to_obuff('\n', &obuff);
		display_blocks(&current, &total_size, &obuff);
	}
	ft_add_str_to_obuff("Total : ", &obuff);
	ft_add_uint_to_obuff(total_size, &obuff);
	ft_add_str_to_obuff(" octets\n", &obuff);
	ft_flush_obuff(&obuff);
}
