/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:33:39 by asenat            #+#    #+#             */
/*   Updated: 2016/12/16 14:08:29 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char		*ft_strtrim(char const *s)
{
	unsigned int	west;
	unsigned int	east;

	if (!s)
		return ("");
	east = ft_strlen(s) - 1;
	west = 0;
	while (ft_isspace(s[west]))
		west++;
	if (!s[west])
		return (ft_strnew(1));
	while (ft_isspace(s[east]))
		east--;
	east = (ft_strlen(s) - 1) - east;
	return (ft_strsub(s, west, (size_t)(ft_strlen(s) - (west + east))));
}
