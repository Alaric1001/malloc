/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:45:31 by asenat            #+#    #+#             */
/*   Updated: 2018/08/23 13:03:54 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc/ft_malloc.h"

#include "libft/memory/memory.h"

void *ft_calloc(size_t count, size_t size)
{
	void *ret;

	ret = ft_malloc(count * size);
	ft_bzero(ret, count * size);
	return (ret);
}
