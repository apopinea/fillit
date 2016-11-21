/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetricut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:57:13 by jyakdi            #+#    #+#             */
/*   Updated: 2016/11/16 14:17:53 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

char		*ft_cutline(char *str)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (str[i * 5 + j] == '.')
				j++;
			else
				j = 5;
		}
		if (j == 4)
		{
			j = 0;
			while (j < 4)
				str[i * 5 + j++] = '1';
		}
	}
	return (str);
}

char		*ft_cutcol(char *str)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (str[i + j * 5] == '.' || str[i + j * 5] == '1')
				j++;
			else
				j = 5;
		}
		if (j == 4)
		{
			j = 0;
			while (j < 4)
				str[i + j++ * 5] = '1';
		}
	}
	return (str);
}

char		*ft_tetricut(char *str)
{
	str = ft_cutline(str);
	str = ft_cutcol(str);
	return (str);
}
