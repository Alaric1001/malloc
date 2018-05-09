/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asenat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:04:39 by asenat            #+#    #+#             */
/*   Updated: 2018/05/09 15:04:50 by asenat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

typedef	struct	s_tree
{
	void			*value;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

t_tree			*ft_tnewnode(void *val);
void			ft_tdelone(t_tree **tree, void (*del)(void*));
void			ft_tdel(t_tree **tree, void (*del)(void*));
void			ft_taddnode(t_tree **tree, t_tree *node);
void			ft_taddrnode(t_tree **tree, t_tree *node);

#endif
