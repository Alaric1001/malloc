/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:30:34 by asenat            #+#    #+#             */
/*   Updated: 2016/11/12 13:50:53 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

size_t	ft_strlcat(char *s1, char const *s2, size_t n)
{
	size_t		to_concat;
	size_t		dst_len;
	char const	*s;
	char		*d;

	to_concat = n;
	d = s1;
	s = s2;
	while (to_concat-- > 0 && *d)
		d++;
	dst_len = d - s1;
	to_concat = n - dst_len;
	if (!to_concat)
		return (n + ft_strlen(s2));
	while (*s)
	{
		if (to_concat > 1)
		{
			*d++ = *s;
			to_concat--;
		}
		s++;
	}
	*d = '\0';
	return (dst_len + (s - s2));
}
