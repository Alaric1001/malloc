/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_free_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:46:58 by asenat            #+#    #+#             */
/*   Updated: 2018/09/07 16:47:41 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

int	is_in_free_list(const t_block *b, const t_block *free_list)
{
	if (b && b->next_free)
		return (1);
	while (free_list)
	{
		if (free_list == b)
			return (1);
		free_list = free_list->next_free;
	}
	return (0);
}
