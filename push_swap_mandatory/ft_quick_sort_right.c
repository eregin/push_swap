/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:17:27 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/28 12:56:12 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_handle_right(t_stack **stack)
{
	int	iter;
	int	max;
	int	l_max;
	int	p_max;

	max = ft_max_order_side(stack, 1);
	l_max = ft_max_order_side(stack, 0);
	p_max = ft_premax_order_side(stack, 1);
	iter = 0;
	if (ft_unic_side(stack, 1) == 1)
	{
		ft_unic_three_handle_right(stack);
		return ;
	}
	else
		ft_not_unic_three_handle_right(stack, 0);
}

static void	ft_merge_checking(t_stack **stack)
{
	int	max;
	int	l_max;
	int	pre_max;

	max = ft_max_order(stack);
	l_max = ft_max_order_side(stack, 0);
	pre_max = ft_premax_order_side(stack, 1);
	if (l_max < 0 || ft_is_sorted_right(stack[max]) != 0)
		return ;
	if (ft_is_sorted_right(stack[pre_max]) == 0)
		ft_merge(&stack[pre_max], &stack[max], stack[pre_max], stack[max]);
	else
	{
		while (ft_stksize(stack[max]) > 0)
			ft_push(&stack[max], &stack[l_max], stack[max], stack[l_max]);
	}
}

void	chanking_right(t_stack **stack, int order)
{
	int		k;

	k = order + 1;
	ft_merge_checking(stack);
	while (ft_stksize(stack[order]) > 3)
	{
		ft_normal_chank_handler_right(stack, k, order);
		k++;
	}
	if (ft_stksize(stack[order]) > 0 && ft_stksize(stack[order]) <= 3)
		three_handle_right(stack);
}

int	ft_is_sorted_right(t_stack *stack)
{
	t_stack	*buf;
	t_stack	*max;
	int		s_max;
	int		oper;

	max = find_stk_max(stack);
	buf = max;
	s_max = buf->value;
	oper = 0;
	while (buf)
	{
		if (s_max < buf->value)
			return (-1);
		s_max = buf->value;
		buf = buf->next;
	}
	buf = stack;
	while (buf != max && oper++ != -1)
	{
		if (s_max < buf->value)
			return (-1);
		s_max = buf->value;
		buf = buf->next;
	}
	return (oper);
}
