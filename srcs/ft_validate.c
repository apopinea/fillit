/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:55:34 by jyakdi            #+#    #+#             */
/*   Updated: 2016/11/16 14:15:10 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fillit.h"

int		ft_check(char *str, int i)
{
	int		nb;

	nb = 0;
	if (i > 4 && str[i - 5] == '#')
		nb++;
	if (i < 14 && str[i + 5] == '#')
		nb++;
	if (i % 5 != 3 && str[i + 1] == '#')
		nb++;
	if (i % 5 != 0 && str[i - 1] == '#')
		nb++;
	return (nb);
}

char	*ft_validate(char *str)
{
	int		nb;
	int		i;
	int		link;

	link = 0;
	i = -1;
	nb = 0;
	while (str[++i])
	{
		if (str[i] == '#')
		{
			link += ft_check(str, i);
			nb++;
		}
		if (nb > 4)
			return (0);
	}
	if (link < 6)
		return (0);
	if (nb == 4)
		return (ft_tetricut(str));
	return (NULL);
}
