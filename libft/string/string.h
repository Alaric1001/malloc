/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:02:38 by asenat            #+#    #+#             */
/*   Updated: 2018/05/09 15:03:02 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <unistd.h>

size_t	ft_strlen(char const *s);
char	*ft_strcpy(char *dest, char const *src);
char	*ft_strncpy(char *dest, char const *src, size_t n);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
int		ft_strcmp(char const *s1, char const *s2);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
char	*ft_strdup(char const *s);
char	*ft_strchr(char const *s, int c);
char	*ft_strrchr(char const *s, int c);
char	*ft_strcat(char *s1, char const *s2);
char	*ft_strncat(char *s1, char const *s2, size_t n);
char	*ft_strstr(char const *big, char const *little);
char	*ft_strnstr(char const *big, char const *little, size_t len);
size_t	ft_strlcat(char *s1, char const *s2, size_t n);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_strrev(char *s);
char	*ft_strappend(char *dst, char const *src);
char	*ft_strcappend(char *dst, char c);
char	*ft_strnappend(char *dst, char const *s, size_t n);
char	*ft_strncappend(char *dst, char c, size_t n);
char	*ft_removechar(char *dst, size_t loc);
char	*ft_strescape(char const *s, char const *to_escape);
char	*ft_strresize(char *s, size_t size);

/*
** Integer<=>String
*/

int		ft_atoi(char const *s);
char	*ft_itoa(long long n);
char	*ft_uitoa(unsigned long long nb);

/*
** Char utils
*/

int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isstrnum(char const *str);
int		ft_isstrprintable(char const *str);

#endif
