/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strresize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:36:00 by asenat            #+#    #+#             */
/*   Updated: 2018/05/08 17:40:38 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

#include "memory/memory.h"

char	*ft_strresize(char *s, size_t size)
{
	char	*res;

	if (!size)
		return (s);
	if (!(res = ft_strnew(ft_strlen(s) + size)))
		return (NULL);
	ft_strcpy(res, s);
	if (s)
		ft_strdel(&s);
	s = NULL;
	return (res);
}
