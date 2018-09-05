/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat </var/spool/mail/asenat>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 09:42:43 by asenat            #+#    #+#             */
/*   Updated: 2018/09/05 13:58:13 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft/memory/memory.h"

/*
** multiply n and size. If the multiplication result overflow, *overflow is set to 1
** TODO Insert in libft math/ section
*/
static size_t safe_mult(size_t n, size_t size, uint8_t* overflow)
{
	__uint128_t mult;

	*overflow = 0;
	mult = (__uint128_t)n * (__uint128_t)size;
	if(mult >> sizeof(size_t) * 8)
		*overflow = 1;
	return (mult);
}

void*	ft_calloc(size_t count, size_t size)
{
	void*	ret;
	size_t	mult;
	uint8_t	mult_overflow;

	mult = safe_mult(count, size, &mult_overflow);
	if (mult_overflow)
		return (NULL);
	if (!(ret = ft_malloc(mult)))
		return (NULL);
	return (ft_memset(ret, '\0', mult));
}
