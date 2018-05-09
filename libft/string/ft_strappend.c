/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:00:23 by asenat            #+#    #+#             */
/*   Updated: 2018/05/08 17:57:02 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_strappend(char *dst, char const *src)
{
	if (!src)
		return (dst);
	dst = ft_strresize(dst, ft_strlen(src));
	ft_strcat(dst, src);
	return (dst);
}
