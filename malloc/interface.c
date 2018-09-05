/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat </var/spool/mail/asenat>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 00:32:29 by asenat            #+#    #+#             */
/*   Updated: 2018/09/05 16:03:35 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc/malloc.h"
#include "ft_malloc/ft_malloc.h"

#include <pthread.h>

static pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

void	*malloc(size_t size)
{
	void *ret;
	pthread_mutex_lock(&g_mutex);
	ret = ft_malloc(size);
	pthread_mutex_unlock(&g_mutex);
	return ret;
}

void	*calloc(size_t count, size_t size)
{
	void *ret;
	pthread_mutex_lock(&g_mutex);
	ret = ft_calloc(count, size);
	pthread_mutex_unlock(&g_mutex);
	return ret;
}

void	free(void *ptr)
{
	pthread_mutex_lock(&g_mutex);
	ft_free(ptr);	
	pthread_mutex_unlock(&g_mutex);
}

void	*realloc(void *ptr, size_t size)
{
	void *ret;
	pthread_mutex_lock(&g_mutex);
	ret = ft_realloc(ptr, size);
	pthread_mutex_unlock(&g_mutex);
	return ret;
}

void	*reallocf(void *ptr, size_t size)
{
	void *ret;
	pthread_mutex_lock(&g_mutex);
	ret = ft_reallocf(ptr, size);
	pthread_mutex_unlock(&g_mutex);
	return ret;
}

void show_alloc_mem(void)
{
	ft_show_alloc_mem();
}
