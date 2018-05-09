/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:48:03 by asenat            #+#    #+#             */
/*   Updated: 2016/12/16 09:38:57 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

int			ft_atoi(char const *s)
{
	int result;
	int i;
	int neg;

	neg = 1;
	i = 0;
	result = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-')
		neg = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] && (ft_isdigit(s[i]) == 1))
	{
		result *= 10;
		result += s[i] - '0';
		i++;
	}
	return (result * neg);
}
