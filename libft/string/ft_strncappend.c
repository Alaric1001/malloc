/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnappend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 10:24:18 by asenat            #+#    #+#             */
/*   Updated: 2017/04/17 16:46:09 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_strncappend(char *dst, char c, size_t n)
{
	char	*ret;
	char	*tmp;
	size_t	i;

	if (n > ft_strlen(dst))
		return (ft_strcappend(dst, c));
	if (!(ret = ft_strnew(ft_strlen(dst) + 1)))
		return (dst);
	i = 0;
	tmp = dst;
	while (i < ft_strlen(dst) + 1)
		if (i == n)
			ret[i++] = c;
		else
			ret[i++] = *tmp++;
	if (dst)
		ft_strdel(&dst);
	dst = NULL;
	return (ret);
}
