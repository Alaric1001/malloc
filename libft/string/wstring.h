/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:03:20 by asenat            #+#    #+#             */
/*   Updated: 2018/05/09 15:03:24 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WSTRING_H
# define FT_WSTRING_H

# include <wchar.h>

size_t	ft_wcharsize(wchar_t c);
size_t	ft_wstrsize(wchar_t const *str);
size_t	ft_wstrlen(wchar_t const *str);

#endif
