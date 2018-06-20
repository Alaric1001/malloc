/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:00:20 by asenat            #+#    #+#             */
/*   Updated: 2018/05/27 16:26:57 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "malloc/malloc_data.h"

t_block	*do_malloc(t_block_type type, size_t size);
t_block	*alloc_block(t_block_type type, t_block** it, t_block* last_it, size_t size);
t_block	*resize_block(t_block* block, size_t size);
int	   	search_in_area(t_area *area, char *adr, t_block_location *result);
int	   	search_in_areas(void *adr, t_block_location *result);
void   	join_free_blocks_around(const t_block_location *location);


#endif
