/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:16:20 by ereginia          #+#    #+#             */
/*   Updated: 2021/10/18 11:59:48 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final;
	t_list	*buf;

	if (lst == NULL)
		return (NULL);
	final = ft_lstnew(f(lst->content));
	if (final == NULL)
		return (NULL);
	buf = final;
	lst = lst->next;
	while (lst)
	{
		buf->next = ft_lstnew(f(lst->content));
		if (!(buf->next))
		{
			ft_lstclear(&final, del);
			return (NULL);
		}
		buf = buf->next;
		lst = lst->next;
	}
	return (final);
}
