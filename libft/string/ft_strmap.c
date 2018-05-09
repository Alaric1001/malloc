/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:47:37 by asenat            #+#    #+#             */
/*   Updated: 2016/11/10 16:16:28 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		result[i] = f(s[i]);
	return (result);
}
