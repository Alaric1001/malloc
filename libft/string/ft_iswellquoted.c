/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswellquoted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 11:17:00 by asenat            #+#    #+#             */
/*   Updated: 2017/06/14 15:44:21 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string/string.h"

char	ft_getmissing_quote(char *sentence)
{
	char	in_quote;

	in_quote = 0;
	while (sentence && *sentence)
	{
		if (*sentence == '\\' && in_quote == 0)
		{
			if (*(sentence + 1))
				sentence += 2;
			else
				return ('\\');
		}
		else
		{
			if (in_quote == *sentence)
				in_quote = 0;
			else if (!in_quote && (*sentence == '\'' || *sentence == '"'))
				in_quote = *sentence;
			++sentence;
		}
	}
	return (in_quote);
}
