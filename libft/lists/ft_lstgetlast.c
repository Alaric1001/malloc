/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:15:27 by asenat            #+#    #+#             */
/*   Updated: 2017/05/12 16:16:32 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists/lists.h"

t_list	*ft_lstgetlast(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}