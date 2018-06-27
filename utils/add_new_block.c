/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 17:54:53 by asenat            #+#    #+#             */
/*   Updated: 2018/05/13 16:03:32 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

t_block		*add_new_block(void* location, size_t size)
{
	t_block *block;

	block = (t_block*)location;
	block->size = size;
	block->next_free = NULL;
	return (block);
}
