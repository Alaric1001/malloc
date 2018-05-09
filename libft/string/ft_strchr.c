/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:01:13 by asenat            #+#    #+#             */
/*   Updated: 2016/11/29 10:21:36 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

#include "memory/memory.h"

char	*ft_strchr(char const *s, int c)
{
	if (!s)
		return (NULL);
	return ((char*)ft_memchr((char*)s, c, ft_strlen(s) + 1));
}
