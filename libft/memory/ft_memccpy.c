/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:24:48 by asenat            #+#    #+#             */
/*   Updated: 2016/11/07 17:51:20 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory/memory.h"

void	*ft_memccpy(void *dest, void const *src, int c, size_t n)
{
	char const	*s;
	char		*d;
	size_t		i;

	s = (char*)src;
	d = (char*)dest;
	i = -1;
	while (++i < n)
		if ((*d++ = *s++) == (char)c)
			return (d);
	return (NULL);
}
