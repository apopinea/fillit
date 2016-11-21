/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:10:31 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/14 13:10:33 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpushback(t_list *begin, void const *content, size_t content_size)
{
	if (!(begin && content))
		return (NULL);
	while (begin->next)
		begin = begin->next;
	if (!(begin->next = ft_lstnew(content, content_size)))
		return (NULL);
	return (begin->next);
}
