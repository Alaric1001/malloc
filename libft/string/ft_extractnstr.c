/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extractnstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:28:25 by asenat            #+#    #+#             */
/*   Updated: 2018/05/09 15:01:07 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_extractnstr(char *str, size_t n)
{
	char		*ret;
	size_t		i;

	if (!str || !n)
		return (NULL);
	ret = ft_strnew(n);
	i = 0;
	while (i < n)
	{
		ret[i] = str[i];
		++i;
	}
	return (ret);
}
