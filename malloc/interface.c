/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:35:33 by asenat            #+#    #+#             */
/*   Updated: 2018/09/10 15:58:07 by asenat           ###   ########.fr       */
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
	return (ret);
}

void	*calloc(size_t count, size_t size)
{
	void *ret;

	pthread_mutex_lock(&g_mutex);
	ret = ft_calloc(count, size);
	pthread_mutex_unlock(&g_mutex);
	return (ret);
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
	return (ret);
}

void	show_alloc_mem(void)
{
	pthread_mutex_lock(&g_mutex);
	ft_show_alloc_mem();
	pthread_mutex_unlock(&g_mutex);
}
