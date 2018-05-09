/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <asenat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:00:00 by asenat            #+#    #+#             */
/*   Updated: 2017/03/30 16:38:56 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path/path.h"

#include <string/string.h>

char	*ft_path_append(char const *path, char const *app)
{
	char *ret;

	ret = ft_strdup(path);
	if (path[ft_strlen(path) - 1] != '/')
		ret = ft_strcappend(ret, '/');
	ret = ft_strappend(ret, app);
	return (ret);
}
