/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strescape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:57:11 by asenat            #+#    #+#             */
/*   Updated: 2018/05/09 15:01:48 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

static int	get_res_len(char const *s, char const *to_escape)
{
	int i;
	int y;

	i = 0;
	while (*s)
	{
		y = -1;
		while (to_escape[++y])
			if (to_escape[y] == *s)
				i++;
			else if (*s == '\n')
				i += 3;
		i++;
		s++;
	}
	return (i);
}

static char	is_toescape(char c, char const *to_escape)
{
	while (*to_escape)
	{
		if (c == *to_escape)
			return (*to_escape);
		to_escape++;
	}
	if (c == '\n')
		return (c);
	return (0);
}

char		*ft_strescape(char const *s, char const *to_escape)
{
	char	*ret;
	int		i;
	char	c;

	if (!(ret = ft_strnew(get_res_len(s, to_escape))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if ((c = is_toescape(*s, to_escape)) == '\n')
		{
			ft_strcpy(ret + i, "'\\n'");
			i += 4;
			s++;
		}
		else if (c)
		{
			ret[i++] = '\\';
			ret[i++] = *s++;
		}
		else
			ret[i++] = *s++;
	}
	return (ret);
}
