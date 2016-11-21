/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolvator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:42:24 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/17 10:31:21 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "lib_fillit.h"
#include <stdlib.h>

static int	ft_limit_grid(t_info_p *info, int c)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j < c)
		if (info->grid[j++][c - 1] != '.')
			break ;
	while (i < c)
		if (info->grid[c - 1][i++] != '.')
			break ;
	if (j == i && i == c)
		return (ft_limit_grid(info, c - 1));
	else
		return (c);
}

static void	ft_relance(t_info_p *info, t_tetri *elem)
{
	int c;

	if (elem->next)
		ft_resolvator_2(info, elem->next, 0, 0);
	else
	{
		c = ft_limit_grid(info, info->length_t);
		if (c < info->length_t)
		{
			info->length_t = c;
			ft_tabscpy(info->grid_t, info->grid, c, c);
			if (c == info->cm)
			{
				ft_print_grid_t(info);
				ft_del_final(info, info->begin);
				exit(1);
			}
		}
	}
}

void		ft_resolvator_2(t_info_p *info, t_tetri *elem, int i, int j)
{
	while (j < info->length_t)
	{
		while (i < info->length_t)
		{
			if ((ft_place_t(info, elem, i, j)))
			{
				if (i + elem->l < info->length_t &&
							j + elem->h < info->length_t)
					ft_relance(info, elem);
			}
			ft_efface_t(info, elem, i, j);
			i++;
		}
		i = 0;
		j++;
	}
}
