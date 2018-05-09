/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:49:38 by asenat            #+#    #+#             */
/*   Updated: 2016/11/26 10:17:23 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory/memory.h"

void	*ft_memchr(void const *str, int c, size_t n)
{
	unsigned char	ch;
	size_t			i;

	if (!str)
		return (NULL);
	i = -1;
	ch = (unsigned char)c;
	while (++i < n)
		if (((unsigned char*)str)[i] == ch)
			return ((void*)str + i);
	return (NULL);
}
