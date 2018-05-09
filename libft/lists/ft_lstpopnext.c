/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopnext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:04:35 by asenat            #+#    #+#             */
/*   Updated: 2017/03/12 15:16:33 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists/lists.h"

void	ft_lstpopnext(t_list *node, void (*del)(void*, size_t))
{
	t_list *next;
	t_list *tmp;

	next = node->next;
	tmp = next->next;
	ft_lstdelone(&next, del);
	node->next = tmp;
}
