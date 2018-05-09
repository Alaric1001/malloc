/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:24:33 by asenat            #+#    #+#             */
/*   Updated: 2018/05/09 13:55:13 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

int		ft_strcmp(char const *s1, char const *s2)
{
	unsigned char	*c1;
	unsigned char	*c2;
	int				i;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (1);
	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	i = 0;
	while (c1[i] == c2[i])
	{
		if (!c1[i] && !c2[i])
			return (0);
		i++;
	}
	return (c1[i] - c2[i]);
}
