/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_area_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:45:31 by asenat            #+#    #+#             */
/*   Updated: 2018/09/07 16:45:34 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

#include <unistd.h>

size_t	get_area_size(t_block_type type)
{
	if (type == TINY)
		return (getpagesize() * TINY_AREA_SIZE);
	if (type == SMALL)
		return (getpagesize() * SMALL_AREA_SIZE);
	return (0);
}
