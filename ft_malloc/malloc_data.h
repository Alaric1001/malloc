/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:16:23 by asenat            #+#    #+#             */
/*   Updated: 2018/07/03 17:31:06 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_DATA_H
# define MALLOC_DATA_H

# include <stdlib.h>

typedef struct		s_block
{
	size_t			size;
	struct s_block	*next_free;
}					t_block;

typedef struct		s_area
{
	size_t			size;
	struct s_area	*next;
}					t_area;

typedef struct		s_area_contrainer
{
	size_t	total_size;
	t_block	*free_blocks;
	t_area	*area;
}					t_area_container;

typedef enum		e_block_type
{
	TINY,
	SMALL,
	LARGE
}					t_block_type;

typedef struct		s_block_location
{
	t_area*			prev_area;
	t_area*			loc_area;
	t_block*		prev_free;
	t_block*		loc;
	t_block_type 	type;
}					t_block_location;

typedef struct		s_area_and_type {
	const t_area*	area;
	t_block_type	type;
}					t_area_and_type;

/**
 ** These macros express the number of memory pages in each areas
**/

# define TINY_AREA_SIZE		2
# define SMALL_AREA_SIZE	4

/**
 * the three malloc main areas
 * [0] -> Tiny
 * [1] -> Small
 * [2] -> Large
 */

extern t_area_container		g_areas[3];
extern size_t ma_supa_size;
#endif
