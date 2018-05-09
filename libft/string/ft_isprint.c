/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:09:28 by asenat            #+#    #+#             */
/*   Updated: 2017/05/31 14:09:08 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

int		ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}

int		ft_isstrprintable(char const *str)
{
	if (!str)
		return (0);
	while (*str)
		if (!ft_isprint(*str++))
			return (0);
	return (1);
}
