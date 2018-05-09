/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:17:32 by asenat            #+#    #+#             */
/*   Updated: 2016/11/08 09:33:51 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory/memory.h"

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	unsigned char const	*s;
	unsigned char		*d;

	s = (unsigned char*)src;
	d = (unsigned char*)dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}
