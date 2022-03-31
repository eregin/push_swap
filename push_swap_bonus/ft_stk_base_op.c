/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_base_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:52:06 by ereginia          #+#    #+#             */
/*   Updated: 2022/02/02 15:21:32 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*ft_stknew(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new)
	{
		new->value = value;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

int	ft_stksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*ft_stklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_stkprelast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next && lst->next->next)
		lst = lst->next;
	return (lst);
}

void	ft_stkadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = ft_stklast(*lst);
	if (*lst == NULL)
		*lst = new;
	else
		last->next = new;
}
