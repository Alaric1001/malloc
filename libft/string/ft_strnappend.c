/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 19:46:19 by asenat            #+#    #+#             */
/*   Updated: 2017/04/17 15:35:14 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_strnappend(char *dst, char const *s, size_t n)
{
	char	*ret;
	char	*tmp;
	size_t	i;
	size_t	len;

	if (n > ft_strlen(dst))
		return (ft_strappend(dst, s));
	if (!(ret = ft_strnew(ft_strlen(dst) + ft_strlen(s))))
		return (dst);
	i = 0;
	tmp = dst;
	len = (ft_strlen(dst) + ft_strlen(s));
	while (i < len)
	{
		if (i == n && *s)
		{
			ret[i++] = *s++;
			++n;
		}
		else
			ret[i++] = *tmp++;
	}
	(dst) ? ft_strdel(&dst) : 0;
	return (ret);
}
