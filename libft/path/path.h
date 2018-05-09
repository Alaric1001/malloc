/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:04:04 by asenat            #+#    #+#             */
/*   Updated: 2018/05/09 15:04:06 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

char	*ft_path_append(char const *path, char const *app);
char	**ft_splitfilepath(char const *file);
int		ft_star_match(char const *str, char const *pattern);

#endif
