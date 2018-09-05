/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:02:17 by asenat            #+#    #+#             */
/*   Updated: 2018/09/05 17:29:27 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

t_block		*get_next_block(t_block_type type, const t_block *block)
{
	char *c_block;

	c_block = (char*)block;
	return ((t_block*)(c_block + round_size(type, block->size)));
}
