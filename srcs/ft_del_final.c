/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_final.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:56:16 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/17 10:56:18 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fillit.h"
#include <stdlib.h>

static void		ft_del_grid(char **tab)
{
	int j;

	j = 0;
	while (tab[j])
		ft_strdel(&tab[j++]);
	free(tab);
}

static void		ft_tetri_del(t_tetri **alst, void (*del)(t_tetri **))
{
	t_tetri	*begin;
	t_tetri	*next;

	if (alst && *alst && *del)
	{
		begin = *alst;
		while (begin)
		{
			next = begin->next;
			(*del)(&begin);
			begin = next;
		}
		*alst = NULL;
	}
}

static void		ft_tetri_delone(t_tetri **alst)
{
	if (alst && *alst)
	{
		ft_strdel(&(*alst)->str);
		free(*alst);
		*alst = NULL;
	}
}

void			ft_del_final(t_info_p *info, t_tetri *beg)
{
	ft_tetri_del(&beg, &ft_tetri_delone);
	ft_del_grid(info->grid);
	info->grid = NULL;
	ft_del_grid(info->grid_t);
	info->grid_t = NULL;
	free(info);
}
