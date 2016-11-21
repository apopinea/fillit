/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:05:46 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/17 09:56:47 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIB_FILLIT_H
# define __LIB_FILLIT_H
# include "libft.h"

typedef struct		s_info_p
{
	char			**grid;
	char			**grid_t;
	int				length_t;
	int				cm;
	struct s_tetri	*begin;
}					t_info_p;

typedef struct		s_tetri
{
	char			*str;
	int				l;
	int				h;
	char			c;
	struct s_tetri	*next;
}					t_tetri;

int					ft_verif_tetrinos_f(char *s);
int					ft_resolvator(void);
t_tetri				*ft_strtolst(char *str, int nb);
int					ft_place_t(t_info_p *info, t_tetri *elem, int i, int j);
void				ft_print_grid(t_info_p *info);
void				ft_print_grid_t(t_info_p *info);
void				ft_efface_t(t_info_p *info, t_tetri *elem, int i, int j);
t_tetri				*ft_lstnew_t(char const *str, int l, int h, char c);
t_tetri				*ft_lstaddback(t_tetri *begin, t_tetri *end);
void				ft_resolvator_2(t_info_p *info,
						t_tetri *elem, int i, int j);
char				*ft_validate(char *str);
char				*ft_tetricut(char *str);
t_info_p			*ft_creat_info(t_tetri *begin, int i);
char				*ft_addchar(char *str, char c);
char				*ft_dellast(char *str);
void				ft_del_final(t_info_p *info, t_tetri *beg);

#endif
