/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:15:20 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/16 15:15:22 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fillit.h"

static t_info_p		*ft_creat_grid(t_info_p *info, int l)
{
	if (!(info->grid = (char**)ft_memalloc(sizeof(char*) * (l + 1))))
		return (0);
	if (!(info->grid_t = (char**)ft_memalloc(sizeof(char*) * (l + 1))))
		return (0);
	info->length_t = l;
	while (l--)
	{
		if (!(info->grid[l] = (char*)ft_memalloc(sizeof(char) *
				(info->length_t + 1))))
			return (0);
		if (!(info->grid_t[l] = (char*)ft_memalloc(sizeof(char) *
				(info->length_t + 1))))
			return (0);
		ft_memset(info->grid[l], '.', sizeof(char) * info->length_t);
	}
	return (info);
}

static void			ft_cl_min_grid(t_info_p *info, int nbt)
{
	int i;

	i = 0;
	while (i * i < nbt * 4)
		i++;
	info->cm = i;
}

t_info_p			*ft_creat_info(t_tetri *begin, int i)
{
	int			l;
	int			h;
	t_info_p	*info;

	if (!(info = (t_info_p*)ft_memalloc(sizeof(t_info_p))))
		return (0);
	info->begin = begin;
	l = 0;
	h = 0;
	while (begin)
	{
		l += begin->l;
		h += begin->h;
		begin = begin->next;
	}
	if (i < 5)
		l = (l <= h) ? h : l;
	else
		l = (l > h) ? h : l;
	ft_cl_min_grid(info, i);
	if (!(ft_creat_grid(info, l + 1)))
		return (0);
	return (info);
}
