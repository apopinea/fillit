/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 09:58:07 by jyakdi            #+#    #+#             */
/*   Updated: 2016/11/17 10:09:14 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_dellast(char *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	str[i - 1] = 0;
	return (str);
}

char			*ft_addchar(char *str, char c)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	str[i] = c;
	return (str);
}
