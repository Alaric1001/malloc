/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taddrnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 10:19:51 by asenat            #+#    #+#             */
/*   Updated: 2017/03/15 11:50:01 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree/tree.h"

void	ft_taddrnode(t_tree **tree, t_tree *node)
{
	if (!tree)
		return ;
	if (!*tree)
	{
		*tree = node;
		return ;
	}
	while ((*tree)->right)
		tree = &(*tree)->right;
	*tree = node;
}
