/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:31:07 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/15 13:31:09 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"
#include "libft.h"

int		ft_place_t(t_info_p *info, t_tetri *elem, int i, int j)
{
	int k;
	int l;

	k = -1;
	l = i;
	if (i + elem->l > info->length_t || j + elem->h > info->length_t)
		return (0);
	while (((char*)elem->str)[++k])
	{
		if (((char*)elem->str)[k] == '\n')
		{
			j++;
			i = l;
		}
		else if (((char*)elem->str)[k] == '.')
			i++;
		else
		{
			if (info->grid[j][i] != '.')
				return (0);
			else
				info->grid[j][i++] = elem->c;
		}
	}
	return (1);
}
