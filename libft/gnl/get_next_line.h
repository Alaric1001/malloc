/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:30:59 by asenat            #+#    #+#             */
/*   Updated: 2018/05/08 17:26:03 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <fcntl.h>

# define BUFF_SIZE 128

typedef struct	s_content
{
	int		fd;
	char	*rest;
}				t_content;

int				get_next_line(int fd, char **line);

#endif
