/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:00:57 by asenat            #+#    #+#             */
/*   Updated: 2016/12/16 13:02:33 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/wstring.h"

size_t	ft_wstrlen(wchar_t const *str)
{
	int ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}
