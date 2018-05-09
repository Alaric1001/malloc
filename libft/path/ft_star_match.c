/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:10:26 by asenat            #+#    #+#             */
/*   Updated: 2017/06/08 13:30:28 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path/path.h"

#include "string/string.h"

static int	get_no_star_len(char const *s)
{
	int ret;

	ret = 0;
	while (s[ret] && s[ret] != '*')
		++ret;
	return (ret);
}

static int	special_case(char const *s, char const *patt)
{
	if (s[0] == '.' && patt[0] != '.')
		return (1);
	else if (!ft_strcmp(s, ".") || !ft_strcmp(s, ".."))
		return (1);
	return (0);
}

int			ft_star_match(char const *s, char const *patt)
{
	int tmp_len;

	if (special_case(s, patt))
		return (0);
	while (*s)
	{
		if (*patt == '*')
		{
			if (!*(patt + 1))
				return (1);
			while (*s && ft_strncmp(s, patt + 1, get_no_star_len(patt + 1)))
				++s;
			if (!*s)
				return (0);
			++patt;
		}
		tmp_len = get_no_star_len(patt);
		if (ft_strncmp(s, patt, tmp_len) && tmp_len)
			return (0);
		s += tmp_len;
		if (!*patt)
			return (0);
		patt += tmp_len;
	}
	return (1);
}
