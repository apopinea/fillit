/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:33:56 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/17 10:44:59 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lib_fillit.h"

t_tetri		*ft_lstnew_t(char const *str, int l, int h, char c)
{
	t_tetri	*new;

	if (!(new = (t_tetri*)ft_memalloc(sizeof(t_tetri))))
		return (NULL);
	if (str)
	{
		new->str = ft_strdup(str);
		new->l = l;
		new->h = h;
		new->c = c;
	}
	else
	{
		new->str = NULL;
		new->l = 0;
		new->h = 0;
		new->c = 0;
	}
	new->next = NULL;
	return (new);
}

t_tetri		*ft_lstaddback(t_tetri *begin, t_tetri *end)
{
	t_tetri		*tmp;

	if (end == NULL)
		return (NULL);
	if (begin == NULL)
		return (end);
	tmp = begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = end;
	return (begin);
}
