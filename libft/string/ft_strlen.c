/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:53:31 by asenat            #+#    #+#             */
/*   Updated: 2016/11/24 14:48:08 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

size_t	ft_strlen(const char *s)
{
	size_t result;

	if (!s)
		return (0);
	result = 0;
	while (s[result])
		result++;
	return (result);
}
