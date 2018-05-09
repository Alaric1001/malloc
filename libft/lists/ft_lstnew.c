/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:06:49 by asenat            #+#    #+#             */
/*   Updated: 2017/03/30 17:50:25 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists/lists.h"

#include "memory/memory.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*result;
	void	*n_content;

	if (!(result = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	n_content = NULL;
	result->next = NULL;
	if (!content)
		content_size = 0;
	else
	{
		if (!(n_content = ft_memalloc(content_size)))
		{
			free(result);
			return (NULL);
		}
		ft_memcpy(n_content, content, content_size);
	}
	result->content_size = content_size;
	result->content = n_content;
	return (result);
}
