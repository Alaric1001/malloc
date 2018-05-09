/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:37:22 by asenat            #+#    #+#             */
/*   Updated: 2016/11/10 11:39:35 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	if (!c1 && !c2)
		return (0);
	while (n-- && (*c1 || *c2))
		if (*c1++ != *c2++)
			return (*(c1 - 1) - *(c2 - 1));
	return (0);
}
