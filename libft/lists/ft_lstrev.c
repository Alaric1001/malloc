/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:22:03 by asenat            #+#    #+#             */
/*   Updated: 2016/11/17 11:28:06 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists/lists.h"

void	ft_lstrev(t_list **lst)
{
	t_list	*next;
	t_list	*current;
	t_list	*last;

	last = NULL;
	current = *lst;
	while (current)
	{
		next = current->next;
		current->next = last;
		last = current;
		current = next;
	}
	*lst = last;
}
