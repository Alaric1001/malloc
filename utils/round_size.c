/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:56:01 by asenat            #+#    #+#             */
/*   Updated: 2018/09/07 16:56:22 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

#ifndef ROUND_UP

# define ROUND_UP(num, align) (((num) + ((align) - 1)) & ~((align) - 1))

#endif

size_t	round_size(t_block_type type, size_t size)
{
	if (type == TINY)
		return (ROUND_UP(size, 16ul));
	if (type == SMALL)
		return (ROUND_UP(size, 512ul));
	return (size);
}
