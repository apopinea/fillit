/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_efface_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:31:21 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/15 13:31:23 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"
#include "libft.h"

void	ft_efface_t(t_info_p *info, t_tetri *elem, int i, int j)
{
	int		m;
	int		l;
	int		h;
	char	c;

	m = info->length_t;
	c = elem->c;
	l = 0;
	h = 0;
	while (j + h < m && h < elem->h)
	{
		while (i + l < m && l < elem->l)
		{
			if (info->grid[j + h][i + l] == c)
				info->grid[j + h][i + l] = '.';
			++l;
		}
		l = 0;
		++h;
	}
}
