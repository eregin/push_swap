/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:39:44 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/28 13:24:48 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	ft_free_stack(t_stack **stacks, int i)
{
	t_stack	*buf;

	while (stacks[i])
	{
		if (ft_stksize(stacks[i]) == 1)
		{
			free(stacks[i]);
			break ;
		}
		while (ft_stksize(stacks[i]) > 0)
		{
			free(ft_stklast(stacks[i]));
			buf = stacks[i];
			while (buf && buf->next && buf->next->next)
				buf = buf->next;
			buf->next = NULL;
			if (ft_stksize(stacks[i]) == 1)
			{
				free(stacks[i]);
				break ;
			}
		}
		i++;
	}
}
