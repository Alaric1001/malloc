/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:49:42 by asenat            #+#    #+#             */
/*   Updated: 2018/05/09 14:19:01 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color/color.h"

#include "string/string.h"

char const	*ft_getcolor(char const *code)
{
	static const t_conv		conv[] = {
		{"RESET", RESET},
		{"HIGHLIGHT", HIGHLIGHT},
		{"UNDERLINE", UNDERLINE},
		{"BLACK", BLACK},
		{"RED", RED},
		{"GREEN", GREEN},
		{"YELLOW", YELLOW},
		{"BLUE", BLUE},
		{"PURPLE", PURPLE},
		{"CYAN", CYAN},
		{"WHITE", WHITE}
	};
	int						i;

	i = -1;
	while (++i < COLOR_NB)
		if (ft_strequ(conv[i].str, code))
			return (conv[i].color);
	return (NULL);
}
