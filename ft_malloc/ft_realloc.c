/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:35:35 by asenat            #+#    #+#             */
/*   Updated: 2018/09/12 10:39:56 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc/ft_malloc.h"

#include "ft_malloc/algorithm.h"
#include "utils/utils.h"
#include "libft/memory/memory.h"

static void	*free_and_malloc(t_block_location *locations, size_t size)
{
	void	*ret;
	size_t	cpy;

	if (!(ret = ft_malloc(size)))
		return (NULL);
	cpy = locations->loc->size;
	if (size < cpy)
		cpy = size;
	ft_memcpy(ret, locations->loc + 1, cpy);
	if (locations->prev_free + 1 == (t_block*)ret)
		ft_free(locations->loc + 1);
	else
		free_location(locations);
	return (ret);
}

static int	is_next_enough(const t_block_location *locations,
		size_t size)
{
	t_block		*next;
	size_t		total_size;
	size_t		r_size;

	r_size = round_size(locations->type, size);
	next = get_next_block(locations->type, locations->loc);
	if (!is_in_free_list(next, g_areas[locations->type].free_blocks))
		return (0);
	total_size = round_size(locations->type,
			locations->loc->size + next->size);
	return (total_size == r_size || total_size
			>= round_size(locations->type, r_size + sizeof(t_block) + 1));
}

static void	*resize_with_next(t_block_location *locations,
		size_t size)
{
	t_block		*next;
	t_block		*new_next;
	t_block		*curr;
	size_t		r_size;
	size_t		size_needed;

	r_size = round_size(locations->type, size);
	curr = locations->loc;
	next = get_next_block(locations->type, locations->loc);
	size_needed = r_size - round_size(locations->type, curr->size);
	curr->size = size;
	if (size_needed < next->size)
	{
		new_next = (t_block*)((char*)next + size_needed);
		new_next->next_free = next->next_free;
		new_next->size = next->size - size_needed;
		next->next_free = new_next;
	}
	if (locations->prev_free)
		locations->prev_free->next_free = next->next_free;
	else
		g_areas[locations->type].free_blocks = next->next_free;
	return (locations->loc + 1);
}

void		*ft_realloc(void *ptr, size_t size)
{
	t_block_location	locations;

	if (!ptr)
		return (ft_malloc(size));
	if (!size)
		size = 16ul;
	ft_bzero(&locations, sizeof(locations));
	if (!(search_address(ptr, &locations)))
		return (NULL);
	if (locations.type != get_block_type(locations.loc->size - sizeof(t_block)))
		return (free_and_malloc(&locations, size));
	size += sizeof(t_block);
	if (round_size(locations.type, locations.loc->size) >= size)
		return (locations.loc + 1);
	if (is_next_enough(&locations, size))
		return (resize_with_next(&locations, size));
	return (free_and_malloc(&locations, size - sizeof(t_block)));
}
