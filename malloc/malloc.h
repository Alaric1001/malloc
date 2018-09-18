/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:32:55 by asenat            #+#    #+#             */
/*   Updated: 2018/09/13 15:50:57 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>

void	*malloc(size_t size);
void	*calloc(size_t count, size_t size);
void	free(void *ptr);
void	*realloc(void *ptr, size_t size);

void	show_alloc_mem(void);

#endif
