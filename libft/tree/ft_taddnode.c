/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taddnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:18:54 by asenat            #+#    #+#             */
/*   Updated: 2017/03/11 17:24:37 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree/tree.h"

void	ft_taddnode(t_tree **tree, t_tree *node)
{
	t_tree *left;
	t_tree *right;

	if (!tree || !*tree)
		return ;
	left = (*tree)->left;
	right = (*tree)->right;
	if (left)
		(*tree)->left = node;
	else if (right)
		(*tree)->right = node;
	else
		ft_taddnode(&right, node);
}
