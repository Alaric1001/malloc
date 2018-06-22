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

void	free(void *ptr)
{
	t_block_location locations;
	t_block			*first_area_block;
	t_block_type	type;

	if (!ptr)
		return ;
	ft_bzero(&locations, sizeof(locations));
	if (!search_in_areas(ptr, &locations))
		error_and_abort();
	if (locations.loc->free)
		error_and_abort();
	type = get_block_type(locations.loc->size);
	if(type != LARGE)
	{
		locations.loc->free = 1;
		join_free_blocks_around(&locations);
		first_area_block = (t_block*)(locations.loc_area + 1);
		if (!first_area_block->next) {
			printf("unmap area\n");
			unmap_area(type, &locations);
		}
		return ;
	}
	unmap_area(type, &locations);
}
