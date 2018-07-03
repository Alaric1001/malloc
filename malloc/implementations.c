/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat </var/spool/mail/asenat>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 00:32:29 by asenat            #+#    #+#             */
/*   Updated: 2018/06/30 01:04:47 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc/malloc.h"
#include "ft_malloc/ft_malloc.h"

void	*malloc(size_t size)
{
	return (ft_malloc(size));
}

void	free(void *ptr)
{
	ft_free(ptr);	
}

void show_alloc_mem(void)
{
	ft_show_alloc_mem();
}
