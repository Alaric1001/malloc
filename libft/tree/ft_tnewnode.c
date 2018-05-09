/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tnewnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:33:56 by asenat            #+#    #+#             */
/*   Updated: 2017/05/17 11:35:54 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree/tree.h"

#include "memory/memory.h"

t_tree			*ft_tnewnode(void *val)
{
	t_tree	*ret;

	if (!(ret = ft_memalloc(sizeof(*ret))))
		return (NULL);
	ret->value = val;
	ret->left = NULL;
	ret->right = NULL;
	return (ret);
}
