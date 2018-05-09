/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:46:03 by asenat            #+#    #+#             */
/*   Updated: 2016/11/29 13:00:53 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_strcat(char *s1, char const *s2)
{
	int len;
	int y;

	if (!s1)
		return ((char*)s2);
	y = -1;
	len = ft_strlen(s1);
	while (s2[++y])
		s1[len + y] = s2[y];
	s1[len + y] = '\0';
	return (s1);
}
