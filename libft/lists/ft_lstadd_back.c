/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 09:50:57 by asenat            #+#    #+#             */
/*   Updated: 2017/03/16 14:49:05 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists/lists.h"

void	ft_lstadd_back(t_list **lst, void *content, size_t size)
{
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = ft_lstnew(content, size);
		return ;
	}
	while ((*lst)->next)
		lst = &(*lst)->next;
	(*lst)->next = ft_lstnew(content, size);
}
