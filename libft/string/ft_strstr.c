/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:04:26 by asenat            #+#    #+#             */
/*   Updated: 2016/11/08 15:31:45 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_strstr(char const *big, char const *little)
{
	int i;
	int y;

	if (big == little || *little == '\0')
		return ((char*)big);
	i = 0;
	while (big[i])
	{
		y = 0;
		while (big[i + y] == little[y])
			if (little[++y] == '\0')
				return ((char*)(big + i));
		i++;
	}
	return (0);
}
