/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 11:32:09 by ereginia          #+#    #+#             */
/*   Updated: 2021/10/16 18:15:33 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buf1;
	t_list	*buf2;

	if (*lst)
	{
		buf1 = *lst;
		while (buf1)
		{
			buf2 = buf1->next;
			del(buf1->content);
			free(buf1);
			buf1 = buf2;
		}
		*lst = NULL;
	}
}
