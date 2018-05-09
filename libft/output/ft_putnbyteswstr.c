/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbyteswstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:16:17 by asenat            #+#    #+#             */
/*   Updated: 2016/12/16 17:53:02 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/output.h"

#include "string/wstring.h"

int		ft_putnbyteswstr(wchar_t const *str, size_t n)
{
	size_t	current_size;
	int		ret;

	ret = 0;
	while (n > 0 && *str)
	{
		current_size = ft_wcharsize(*str);
		if (n < current_size)
			return (ret);
		n -= current_size;
		ft_putwchar(*str++, current_size);
		ret += current_size;
	}
	return (ret);
}
