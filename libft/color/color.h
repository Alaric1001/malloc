/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:19:24 by asenat            #+#    #+#             */
/*   Updated: 2018/05/09 14:19:46 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define COLOR_NB	11
# define RESET		"\033[0m"
# define HIGHLIGHT	"\033[1m"
# define UNDERLINE	"\033[4m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

typedef struct	s_conv {
	char	*str;
	char	*color;
}				t_conv;

char const		*ft_getcolor(char const *code);

#endif
