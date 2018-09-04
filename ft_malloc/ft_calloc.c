/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat </var/spool/mail/asenat>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 09:42:43 by asenat            #+#    #+#             */
/*   Updated: 2018/09/04 17:12:06 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft/memory/memory.h"

/*
** if the multiplication overflow return 0
** return the result otherwise
** TODO Insert in libft math/ section
*/
static size_t safe_mult(size_t n, size_t size)
{
	__uint128_t mult;

	mult = (__uint128_t)n * (__uint128_t)size;
	if(mult >> sizeof(size_t) * 8)
		return (0);
	return (mult);
}

void*	ft_calloc(size_t count, size_t size)
{
	void* ret;
	size_t mult;

	if (!(mult = safe_mult(count, size)))
		return (NULL);
	if (!(ret = ft_malloc(mult)))
		return (NULL);
	return (ft_memset(ret, '\0', mult));
}
