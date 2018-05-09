/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:49:26 by asenat            #+#    #+#             */
/*   Updated: 2017/05/12 14:08:21 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *result;

	if (!s1 && !s2)
		return (NULL);
	if (!(result = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	(s1) ? ft_strcpy(result, s1) : 0;
	(s2) ? ft_strcat(result, s2) : 0;
	return (result);
}
