/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:39:15 by asenat            #+#    #+#             */
/*   Updated: 2018/09/07 16:40:26 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc/algorithm.h"

int	search_address(const void *ptr, t_block_location *ret)
{
	t_block *iterator;
	int		ptr_found;

	if (!search_in_areas(ptr, ret))
		return (0);
	iterator = g_areas[ret->type].free_blocks;
	ptr_found = 0;
	while (iterator)
	{
		if ((char*)(iterator + 1) == (char*)ptr)
			ptr_found = 1;
		else if (iterator > ret->prev_free && (char*)(iterator + 1)
				< (char*)ptr)
			ret->prev_free = iterator;
		else if ((char*)(iterator + 1) > (char*)ptr)
			return (!ptr_found);
		iterator = iterator->next_free;
	}
	return (!ptr_found);
}
