/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 10:54:30 by asenat            #+#    #+#             */
/*   Updated: 2018/06/14 23:13:24 by asenat           ###   ########.fr       */
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
size_t			round_size(t_block_type type, size_t size);

t_area_and_type	get_lowest_area(t_area** tiny, t_area** small, t_area** large);
const char* 	get_type_str(t_block_type type);
#endif
