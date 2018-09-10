/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:03:13 by asenat            #+#    #+#             */
/*   Updated: 2018/09/07 16:03:15 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

#include "libft/memory/memory.h"
#include "libft/math/math.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	mult;
	uint8_t	mult_overflow;

	mult = safe_u_mult(count, size, &mult_overflow);
	if (mult_overflow)
		return (NULL);
	if (!(ret = ft_malloc(mult)))
		return (NULL);
	return (ft_memset(ret, '\0', mult));
}
