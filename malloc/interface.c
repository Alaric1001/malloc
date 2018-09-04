/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat </var/spool/mail/asenat>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 00:32:29 by asenat            #+#    #+#             */
/*   Updated: 2018/09/04 14:46:27 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc/malloc.h"
#include "ft_malloc/ft_malloc.h"

void	*malloc(size_t size)
{
	return (ft_malloc(size));
}

void	*calloc(size_t count, size_t size)
{
	return (ft_calloc(count, size));
}

void	free(void *ptr)
{
	ft_free(ptr);	
}

void	*realloc(void *ptr, size_t size)
{
	return (ft_realloc(ptr, size));
}

void	*reallocf(void *ptr, size_t size)
{
	return (ft_reallocf(ptr, size));
}

void show_alloc_mem(void)
{
	ft_show_alloc_mem();
}
