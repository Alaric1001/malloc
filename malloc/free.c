/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:19:51 by asenat            #+#    #+#             */
/*   Updated: 2018/05/27 14:19:16 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc/malloc.h"

#include "malloc/algorithm.h"
#include "utils/utils.h"
#include "libft/output/output.h"
#include "libft/memory/memory.h"

static void error_and_abort(void)
{
		ft_putstr_fd("free(): Invalid pointer", 2);
		exit(6);
}

static int search_and_handle_errors(const void *ptr, t_block_location* ret)
{
	t_block *iterator;
	int		ptr_found;

	if (!search_in_areas(ptr, ret))
		return 0;
	iterator = g_areas[ret->type].free_blocks;
	ptr_found = 0;
	while (iterator)
	{
		if ((char*)(iterator + 1) == (char*)ptr)
			ptr_found = 1;
		else if (iterator > ret->prev_free && (char*)(iterator + 1) < (char*)ptr)
			ret->prev_free = iterator;
		else if ((char*)(iterator + 1) > (char*)ptr)
			return (!ptr_found);
		iterator = iterator->next_free;
	}
	return (!ptr_found);
}

void	free(void *ptr)
{
	t_block_location	locations;
	t_block				*first_area_block;

	if (!ptr)
		return ;
	ft_bzero(&locations, sizeof(locations));
	if (!search_and_handle_errors(ptr, &locations))
		error_and_abort();
	if(locations.type != LARGE)
	{
		join_free_blocks_around(&locations);
		first_area_block = (t_block*)(locations.loc_area + 1);
		if (first_area_block->size == locations.loc_area->size
				- sizeof(t_block) - sizeof(t_area)) {
			printf("unmap area\n");
			unmap_area(locations.type, &locations);
		}
		return ;
	}
	unmap_area(locations.type, &locations);
}
