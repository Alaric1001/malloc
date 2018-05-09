/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tdelone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:59:32 by asenat            #+#    #+#             */
/*   Updated: 2017/03/11 17:27:08 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree/tree.h"

#include <stdlib.h>

void	ft_tdelone(t_tree **tree, void (*del)(void *))
{
	del((*tree)->value);
	free(*tree);
	*tree = NULL;
}
