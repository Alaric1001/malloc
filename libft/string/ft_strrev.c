/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:44:10 by asenat            #+#    #+#             */
/*   Updated: 2016/11/11 13:55:29 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_strrev(char *s)
{
	int		length;
	int		i;
	char	cache;

	length = ft_strlen(s) - 1;
	i = 0;
	while (i < length)
	{
		cache = s[i];
		s[i] = s[length];
		s[length] = cache;
		i++;
		length--;
	}
	return (s);
}
