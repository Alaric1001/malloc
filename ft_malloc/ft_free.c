/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:19:51 by asenat            #+#    #+#             */
/*   Updated: 2018/09/10 13:11:04 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc/ft_malloc.h"

#include "ft_malloc/algorithm.h"
#include "utils/utils.h"
#include "libft/output/output.h"
#include "libft/memory/memory.h"

void	ft_free(void *ptr)
{
	t_block_location	locations;

	if (!ptr)
		return ;
	ft_bzero(&locations, sizeof(locations));
	if (search_address(ptr, &locations))
		free_location(&locations);
}

void	free_location(t_block_location *locations)
{
	if (locations->type != LARGE)
	{
		defrag_around_and_free(locations);
		if (locations->loc->size >= locations->loc_area->size
				- sizeof(t_area))
		{
			remove_from_free_lst(locations->type, locations->loc);
			unmap_area(locations);
		}
	}
	else
		unmap_area(locations);
}
