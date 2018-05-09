/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublearrayndel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:06:46 by asenat            #+#    #+#             */
/*   Updated: 2017/05/30 17:32:42 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory/memory.h"

void	ft_doublearrayndel(void ***a, size_t n)
{
	size_t i;

	if (!a)
		return ;
	i = 0;
	while (i < n)
		ft_memdel(&a[0][i++]);
	free(*a);
	*a = NULL;
}
