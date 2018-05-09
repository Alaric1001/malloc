/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:45:29 by asenat            #+#    #+#             */
/*   Updated: 2016/11/08 15:29:00 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	size_t i;
	size_t y;

	if (little == big || *little == '\0')
		return ((char*)big);
	i = 0;
	while (big[i] && i < len)
	{
		y = 0;
		while ((big[i + y] == little[y]) && (i + y < len))
			if (little[++y] == '\0')
				return ((char*)(big + i));
		i++;
	}
	return (0);
}
