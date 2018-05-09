/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:08:23 by asenat            #+#    #+#             */
/*   Updated: 2017/01/09 18:12:07 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output/output.h"

#include "string/string.h"

static char *g_queue = NULL;

void	ft_flushqueue(void)
{
	ft_putstr(g_queue);
	ft_strclr(g_queue);
}

void	ft_queuestr(char const *str)
{
	int cursor;
	int i;

	if (!g_queue)
		g_queue = ft_strnew(QUEUE_SIZE);
	cursor = ft_strlen(g_queue);
	i = -1;
	while (str[++i])
	{
		if (cursor == QUEUE_SIZE)
		{
			ft_flushqueue();
			cursor = 0;
		}
		g_queue[cursor++] = str[i];
	}
}

void	ft_queuechar(char c)
{
	int cursor;

	if (!g_queue)
		g_queue = ft_strnew(QUEUE_SIZE);
	cursor = ft_strlen(g_queue);
	if (cursor == QUEUE_SIZE)
	{
		ft_flushqueue();
		cursor = 0;
	}
	g_queue[cursor] = c;
}

void	ft_queuenbr(int n)
{
	unsigned int i;

	if (n < 0)
	{
		ft_queuechar('-');
		i = -n;
	}
	else
		i = n;
	if (i >= 10)
	{
		ft_queuenbr((i / 10));
		ft_queuenbr((i % 10));
	}
	else
		ft_queuechar(i + '0');
}
