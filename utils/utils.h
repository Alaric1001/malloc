/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 10:54:30 by asenat            #+#    #+#             */
/*   Updated: 2018/09/10 10:31:29 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "ft_malloc/malloc_data.h"

size_t			get_area_size(t_block_type type);
t_block_type	get_block_type(size_t size);
t_area			*mmap_area(t_block_type type, size_t size);
void			unmap_area(const t_block_location *locations);
t_block			*add_new_block(void *location, size_t size);
size_t			round_size(t_block_type type, size_t size);
t_area_and_type	get_lowest_area(t_area **tiny, t_area **small, t_area **large);
const char		*get_type_str(t_block_type type);
int				is_in_free_list(const t_block *b, const t_block *free_list);
t_block			*search_free_block(t_block_type type, const t_block *ref);
void			remove_from_free_lst(t_block_type type, const t_block *block);
t_block			*get_next_block(t_block_type type, const t_block *block);

#endif
