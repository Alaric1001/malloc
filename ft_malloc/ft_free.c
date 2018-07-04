/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:19:51 by asenat            #+#    #+#             */
/*   Updated: 2018/07/04 18:13:31 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc/ft_malloc.h"

#include "ft_malloc/algorithm.h"
#include "utils/utils.h"
#include "libft/output/output.h"
#include "libft/memory/memory.h"

#include <stdio.h>

static void error_and_abort(void)
{
		ft_putstr_fd("free(): Invalid pointer\n", 2);
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

void	ft_free(void *ptr)
{
	t_block_location	locations;

	if (!ptr)
		return ;
	ft_bzero(&locations, sizeof(locations));
	if (!search_and_handle_errors(ptr, &locations))
		error_and_abort();
	if(locations.type != LARGE)
	{
		defrag_around_and_free(&locations);
		if (locations.loc->size >= locations.loc_area->size
				- sizeof(t_area)) {
			printf("unmap area\n");
			remove_from_free_lst(locations.type, locations.loc);
			unmap_area(&locations);
		}
	}
	else
		unmap_area(&locations);
}
