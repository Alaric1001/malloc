/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 08:38:58 by asenat            #+#    #+#             */
/*   Updated: 2016/12/06 10:11:05 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/output.h"

int		ft_putnstr(char const *str, size_t n)
{
	char const *tmp;

	if (!str)
		return (0);
	tmp = str;
	while (n-- && str)
		ft_putchar(*tmp++);
	return (tmp - str);
}
