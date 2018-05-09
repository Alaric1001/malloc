/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:55:09 by asenat            #+#    #+#             */
/*   Updated: 2016/11/10 13:45:40 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_strncat(char *s1, char const *s2, size_t n)
{
	size_t		i;
	char const	*src;

	src = s2;
	i = ft_strlen(s1);
	while (n--)
	{
		if (!(s1[i] = *src++))
			break ;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
