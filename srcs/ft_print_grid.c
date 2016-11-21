/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:31:54 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/15 13:31:59 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"
#include "libft.h"
#include <unistd.h>

void	ft_print_grid(t_info_p *info)
{
	int i;

	i = -1;
	while (++i < info->length_t)
	{
		write(1, info->grid[i], info->length_t);
		ft_putchar('\n');
	}
}

void	ft_print_grid_t(t_info_p *info)
{
	int i;

	i = -1;
	while (++i < info->length_t)
	{
		write(1, info->grid_t[i], info->length_t);
		ft_putchar('\n');
	}
}
