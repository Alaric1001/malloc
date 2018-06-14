/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 10:54:30 by asenat            #+#    #+#             */
/*   Updated: 2018/05/26 17:26:10 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "malloc/malloc_data.h"

size_t			get_area_size(t_block_type type);
t_block_type	get_block_type(size_t size);
t_area*			mmap_area(t_block_type type, size_t size);
void			unmap_area(t_block_type type, const t_block_location *locations);
t_block*		add_new_block(void *location, size_t size);

#endif
