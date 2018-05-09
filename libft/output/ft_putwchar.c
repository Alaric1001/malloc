/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:26:00 by asenat            #+#    #+#             */
/*   Updated: 2016/12/16 10:27:18 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/output.h"

#include "string/wstring.h"

void	ft_putwchar(wchar_t c, size_t size)
{
	ft_putwchar_fd(c, 1, size);
}
