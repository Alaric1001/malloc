/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolored.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:50:19 by asenat            #+#    #+#             */
/*   Updated: 2018/05/09 14:20:18 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/output.h"

#include "color/color.h"

int		ft_putcolored(char const *s, char const *code, int fd)
{
	char const	*color;

	if (!s || !code)
		return (-1);
	color = ft_getcolor(code);
	if (!color)
		return (0);
	ft_putstr_fd(color, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(ft_getcolor("RESET"), fd);
	return (1);
}
