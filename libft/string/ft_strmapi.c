/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:05:37 by asenat            #+#    #+#             */
/*   Updated: 2016/11/10 13:47:39 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		s_len;
	int		i;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	if (!(result = ft_strnew(s_len)))
		return (NULL);
	i = -1;
	while (++i < s_len)
		result[i] = f(i, s[i]);
	return (result);
}
