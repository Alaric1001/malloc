/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:23:09 by asenat            #+#    #+#             */
/*   Updated: 2018/05/09 14:23:35 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <stdlib.h>

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, void const *src, size_t n);
void	*ft_memccpy(void *dest, void const *src, int c, size_t n);
void	*ft_memmove(void *dest, void const *src, size_t n);
void	*ft_memchr(void const *str, int c, size_t n);
int		ft_memcmp(void const *s1, void const *s2, size_t n);
void	ft_bzero(void *s, size_t n);
void	ft_doublearraydel(void ***array);
void	ft_doublearrayndel(void ***array, size_t n);

#endif
