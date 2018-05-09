/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:26:05 by asenat            #+#    #+#             */
/*   Updated: 2017/03/15 11:54:23 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists/lists.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (del)
		del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
