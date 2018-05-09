/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnblen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:16:11 by asenat            #+#    #+#             */
/*   Updated: 2018/05/08 17:53:40 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numeric/numeric.h"

size_t	ft_getnblen(unsigned long long n)
{
	size_t len;

	len = 0;
	while (n /= 10)
		len++;
	return (len);
}
