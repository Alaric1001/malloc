/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 09:07:57 by asenat            #+#    #+#             */
/*   Updated: 2018/05/08 17:57:27 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	*ft_strcappend(char *dst, char c)
{
	dst = ft_strresize(dst, 1);
	dst[ft_strlen(dst)] = c;
	return (dst);
}
