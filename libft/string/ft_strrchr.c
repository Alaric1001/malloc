/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:55:33 by asenat            #+#    #+#             */
/*   Updated: 2016/11/08 12:14:56 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_strrchr(char const *s, int c)
{
	int len;

	len = ((int)ft_strlen(s) + 1);
	while (--len >= 0)
		if (s[len] == (char)c)
			return ((char *)&s[len]);
	return (NULL);
}
