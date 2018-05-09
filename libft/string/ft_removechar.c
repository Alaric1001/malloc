/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removechar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:11:45 by asenat            #+#    #+#             */
/*   Updated: 2018/05/08 17:56:21 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_removechar(char *dst, size_t loc)
{
	char	*ret;
	char	*tmp;
	int		i;
	size_t	y;

	if (loc > ft_strlen(dst) || ft_strlen(dst) == 0)
		return (dst);
	if (ft_strlen(dst) - 1 == 0)
	{
		ft_strdel(&dst);
		return (NULL);
	}
	if (!(ret = ft_strnew(ft_strlen(dst) - 1)))
		return (dst);
	tmp = dst;
	i = 0;
	y = 0;
	while (y < ft_strlen(dst))
	{
		if (y++ != loc)
			ret[i++] = *tmp;
		tmp++;
	}
	(dst) ? ft_strdel(&dst) : 0;
	return (ret);
}
