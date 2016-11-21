/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:19:33 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/17 10:47:22 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fillit.h"
#include <stdlib.h>

/*
**#include <time.h>
**clock_t t1, t2;
**float	temps;
**t1 = clock();
**t2 = clock();
**temps = ((float)(t2-t1) / (double)CLOCKS_PER_SEC) / 1;
*/

static int	ft_lanceur(char *file)
{
	char		*s;
	int			i;
	t_tetri		*begin;
	t_info_p	*info;

	if (!(s = ft_lecture_f(file, 550, 560)))
		return (0);
	if (!(i = ft_verif_tetrinos_f(s)))
		return (0);
	if (!(begin = ft_strtolst(s, i)))
		return (0);
	if ((info = ft_creat_info(begin, i)))
	{
		ft_resolvator_2(info, begin, 0, 0);
		ft_print_grid_t(info);
		ft_del_final(info, begin);
		exit(2);
	}
	else
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!(ft_lanceur(*(argv + 1))))
			ft_putendl("error");
	}
	else
		ft_putendl("usage: ./fillit source_file");
	return (0);
}
