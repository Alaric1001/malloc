/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:34:41 by asenat            #+#    #+#             */
/*   Updated: 2017/06/16 12:01:12 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

int		ft_isstrnum(char const *str)
{
	int neg;

	if (!str)
		return (0);
	neg = (*str == '-');
	while (*(str + neg))
		if (!ft_isdigit(*(str++ + neg)))
			return (0);
	return ((neg) ? -1 : 1);
}
