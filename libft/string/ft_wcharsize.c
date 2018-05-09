/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 08:48:03 by asenat            #+#    #+#             */
/*   Updated: 2016/12/16 17:53:31 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/wstring.h"

size_t	ft_wcharsize(wchar_t c)
{
	wchar_t	tmp;
	size_t	ret;

	tmp = c;
	ret = 0;
	while (tmp > 0x7f)
	{
		tmp = tmp >> 6;
		ret++;
	}
	return (ret + 1);
}
