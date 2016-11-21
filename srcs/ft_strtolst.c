/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:43:08 by jyakdi            #+#    #+#             */
/*   Updated: 2016/11/17 10:46:29 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "lib_fillit.h"

t_tetri			*ft_strtoelem(char *str, char c)
{
	int			i;
	int			l;
	int			h;

	i = 0;
	while (str[i] != '\n' && str[i])
	{
		i++;
	}
	l = i;
	i = 0;
	h = 1;
	while (str[i])
	{
		if (str[i] == '\n')
			h++;
		i++;
	}
	return (ft_lstnew_t(str, l, h, c));
}

char			*ft_cutstr(char *str, char c)
{
	int			nl;
	char		*dest;
	int			i;

	i = -1;
	if (!(dest = ft_memalloc(sizeof(str))))
		return (NULL);
	nl = 1;
	while (str[++i])
	{
		if (str[i] == c || str[i] == '.')
		{
			dest = ft_addchar(dest, str[i]);
			nl = 0;
		}
		if (str[i] == '\n' && !nl)
		{
			dest = ft_addchar(dest, '\n');
			nl = 1;
		}
	}
	dest = ft_dellast(dest);
	return (dest);
}

static char		*ft_strtolst_2(char *str, int *i)
{
	char	*tmp;
	char	*tmp2;

	if (!(tmp = ft_strsub(str, *i, 20)))
		return (NULL);
	*i += 21;
	if (!(ft_validate(tmp)))
		return (NULL);
	if (!(tmp2 = ft_cutstr(tmp, '#')))
		return (NULL);
	ft_strdel(&tmp);
	return (tmp2);
}

t_tetri			*ft_strtolst(char *str, int nb)
{
	int			i;
	t_tetri		*begin;
	t_tetri		*elem;
	char		num;
	char		*tmp;

	num = 'A';
	begin = NULL;
	elem = NULL;
	i = 0;
	while (nb--)
	{
		if (!(tmp = ft_strtolst_2(str, &i)))
			return (NULL);
		elem = ft_strtoelem(tmp, num++);
		ft_strdel(&tmp);
		if (!(begin = ft_lstaddback(begin, elem)))
			return (NULL);
	}
	return (begin);
}
