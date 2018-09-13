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

#ifdef FT_MALL_DEBUG
#include "libft/output/obuff.h"
static t_obuff			obuff = {.cursor = 0, .fd = 2};
#endif

static pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

void	*malloc(size_t size)
{
	void *ret;

	pthread_mutex_lock(&g_mutex);
	ret = ft_malloc(size);
#ifdef FT_MALL_DEBUG
	ft_add_str_to_obuff("\n", &obuff);
	ft_add_str_to_obuff("->  malloc: ", &obuff);
	ft_add_uint_to_obuff(size, &obuff);
	ft_add_str_to_obuff(", ", &obuff);
	ft_add_uint_base_to_obuff((uintmax_t)ret, "0123456789ABCDEF", &obuff);
	ft_add_str_to_obuff("\n\n", &obuff);
	ft_flush_obuff(&obuff);
	ft_show_alloc_mem();
#endif
	pthread_mutex_unlock(&g_mutex);
	return (ret);
}

void	*calloc(size_t count, size_t size)
{
	void *ret;

	pthread_mutex_lock(&g_mutex);
	ret = ft_calloc(count, size);
#ifdef FT_MALL_DEBUG
	ft_add_str_to_obuff("\n", &obuff);
	ft_add_str_to_obuff("->  calloc: ", &obuff);
	ft_add_uint_to_obuff(count, &obuff);
	ft_add_str_to_obuff(", ", &obuff);
	ft_add_uint_to_obuff(size, &obuff);
	ft_add_str_to_obuff(", ", &obuff);
	ft_add_uint_base_to_obuff((uintmax_t)ret, "0123456789ABCDEF", &obuff);
	ft_add_str_to_obuff("\n\n", &obuff);
	ft_flush_obuff(&obuff);
	ft_show_alloc_mem();
#endif
	pthread_mutex_unlock(&g_mutex);
	return (ret);
}

void	free(void *ptr)
{
	pthread_mutex_lock(&g_mutex);
	ft_free(ptr);
#ifdef FT_MALL_DEBUG
	ft_add_str_to_obuff("\n", &obuff);
	ft_add_str_to_obuff("->  free: ", &obuff);
	ft_add_uint_base_to_obuff((uintmax_t)ptr, "0123456789ABCDEF", &obuff);
	ft_add_str_to_obuff("\n\n", &obuff);
	ft_flush_obuff(&obuff);
	ft_show_alloc_mem();
#endif
	pthread_mutex_unlock(&g_mutex);
}

void	*realloc(void *ptr, size_t size)
{
	void *ret;

	pthread_mutex_lock(&g_mutex);
	ret = ft_realloc(ptr, size);
#ifdef FT_MALL_DEBUG
	ft_add_str_to_obuff("\n", &obuff);
	ft_add_str_to_obuff("->  realloc: ", &obuff);
	ft_add_uint_base_to_obuff((uintmax_t)ptr, "0123456789ABCDEF", &obuff);
	ft_add_str_to_obuff(", ", &obuff);
	ft_add_uint_to_obuff(size, &obuff);
	ft_add_str_to_obuff(", ", &obuff);
	ft_add_uint_base_to_obuff((uintmax_t)ret, "0123456789ABCDEF", &obuff);
	ft_add_str_to_obuff("\n\n", &obuff);
	ft_flush_obuff(&obuff);
	ft_show_alloc_mem();
#endif
	pthread_mutex_unlock(&g_mutex);
	return (ret);
}

void	*reallocf(void *ptr, size_t size)
{
	void *ret;

	ret = realloc(ptr, size);
	return (ret);
}

void	show_alloc_mem(void)
{
	pthread_mutex_lock(&g_mutex);
	ft_show_alloc_mem();
	pthread_mutex_unlock(&g_mutex);
}
