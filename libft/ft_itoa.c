/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:17:31 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/09 16:17:33 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_comp_itoa(int nb, int l, char *str)
{
	if (nb == -2147483648)
	{
		str[l - 1] = '8';
		ft_comp_itoa(nb / 10, l - 1, str);
	}
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			str[0] = '-';
		}
		if (nb > 9)
			ft_comp_itoa(nb / 10, l - 1, str);
		str[l - 1] = (nb % 10) + '0';
	}
}

char		*ft_itoa(int n)
{
	int		l;
	char	*str;
	int		nb;

	nb = n;
	l = (n < 0) ? 2 : 1;
	while (n /= 10)
		l++;
	if (!(str = ft_strnew(l)))
		return (NULL);
	ft_comp_itoa(nb, l, str);
	return (str);
}
