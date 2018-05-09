/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:20:56 by asenat            #+#    #+#             */
/*   Updated: 2016/12/16 17:52:26 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists/lists.h"

size_t		ft_lstlen(t_list const *lst)
{
	size_t			result;
	t_list const	*tmp;

	tmp = lst;
	result = 0;
	while (tmp)
	{
		result++;
		tmp = tmp->next;
	}
	return (result);
}
