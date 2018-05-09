/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:35:06 by asenat            #+#    #+#             */
/*   Updated: 2016/12/16 11:23:32 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/output.h"

#include "string/wstring.h"

void	ft_putwstr_fd(wchar_t const *str, int fd)
{
	while (*str)
	{
		ft_putwchar_fd(*str, fd, ft_wcharsize(*str));
		str++;
	}
}
