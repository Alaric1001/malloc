/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tdel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:12:01 by asenat            #+#    #+#             */
/*   Updated: 2017/03/30 14:07:16 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree/tree.h"

#include <stdlib.h>

void	ft_tdel(t_tree **tree, void (*del)(void*))
{
	t_tree	*left;
	t_tree	*right;

	if (!tree || !*tree || !del)
		return ;
	left = (*tree)->left;
	right = (*tree)->right;
	ft_tdel(&left, del);
	ft_tdel(&right, del);
	del((*tree)->value);
	free(*tree);
	*tree = NULL;
}
