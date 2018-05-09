/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublearraydel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:16:43 by asenat            #+#    #+#             */
/*   Updated: 2017/03/16 14:11:35 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory/memory.h"

void	ft_doublearraydel(void ***array)
{
	int i;

	if (!array || !*array)
		return ;
	i = 0;
	while (array[0][i])
		ft_memdel(&array[0][i++]);
	free(*array);
	*array = NULL;
}
