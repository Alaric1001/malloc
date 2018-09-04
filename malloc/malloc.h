/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat </var/spool/mail/asenat>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 00:29:10 by asenat            #+#    #+#             */
/*   Updated: 2018/09/04 16:35:40 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

#include <stdlib.h>

void	*malloc(size_t size);
void 	*calloc(size_t count, size_t size);
void 	free(void *ptr);
void 	*realloc(void *ptr, size_t size);
void 	*reallocf(void *ptr, size_t size);

void 	show_alloc_mem(void);

#endif
