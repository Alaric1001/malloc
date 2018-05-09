/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:18:53 by asenat            #+#    #+#             */
/*   Updated: 2016/11/12 16:25:43 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory/memory.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	unsigned char const	*s;
	unsigned char		*d;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	if (!n)
		return (dest);
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	while (n--)
		d[n] = s[n];
	return (dest);
}
