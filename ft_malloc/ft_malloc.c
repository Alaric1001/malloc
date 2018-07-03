/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 10:45:34 by asenat            #+#    #+#             */
/*   Updated: 2018/06/30 00:37:41 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc/ft_malloc.h"

#include "ft_malloc/algorithm.h"
#include "utils/utils.h"
#include <stdio.h>

t_area_container	g_areas[3] = 	{{0, NULL, NULL},
									{0, NULL, NULL},
									{0, NULL, NULL}};

void	*ft_malloc(size_t size)
{
	t_block_type	type;
	t_block*		ret;

	if (!size)
		return (NULL);
	type = get_block_type(size);
	ret = do_malloc(type, size);
	if (!ret)
		return (NULL);
	return (ret + 1);
}

