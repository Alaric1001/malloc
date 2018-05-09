/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:26:11 by asenat            #+#    #+#             */
/*   Updated: 2016/11/04 11:06:58 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory/memory.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*dest;

	dest = (char*)s;
	if (!n)
		return (s);
	while (n)
		dest[--n] = (char)c;
	return (s);
}
