/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:17:08 by ereginia          #+#    #+#             */
/*   Updated: 2022/02/02 12:03:38 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_handle_left(t_stack **stack)
{
	int	iter;
	int	max;
	int	r_max;
	int	p_max;

	max = ft_max_order(stack);
	r_max = ft_max_order_side(stack, 1);
	p_max = ft_premax_order_side(stack, 0);
	iter = 0;
	if (ft_unic_side(stack, 0) == 1)
	{
		ft_unic_three_handle_left(stack);
		return ;
	}
	else
		ft_not_unic_three_handle_left(stack, 0);
}

static void	ft_merge_checking(t_stack **stack)
{
	int	max;
	int	r_max;
	int	pre_max;

	max = ft_max_order_side(stack, 0);
	r_max = ft_max_order_side(stack, 1);
	pre_max = ft_premax_order_side(stack, 0);
	if (r_max < 0 || ft_is_sorted_left(stack[max]) != 0)
		return ;
	if (ft_is_sorted_left(stack[pre_max]) == 0)
		ft_merge(&stack[pre_max], &stack[max], stack[pre_max], stack[max]);
	else
	{
		while (ft_stksize(stack[max]) > 0)
			ft_push(&stack[max], &stack[r_max], stack[max], stack[r_max]);
	}
}

void	chanking_left(t_stack **stack, int order)
{
	int		k;

	k = order + 1;
	ft_merge_checking(stack);
	while (ft_stksize(stack[order]) > 3)
	{
		ft_normal_chank_handler_left(stack, k, order);
		k++;
	}
	if (ft_stksize(stack[order]) > 0 && ft_stksize(stack[order]) <= 3)
		three_handle_left(stack);
}

int	ft_is_sorted_left(t_stack *stack)
{
	t_stack	*buf;
	t_stack	*min;
	int		s_min;
	int		oper;

	min = find_stk_min(stack);
	buf = min;
	s_min = buf->value;
	oper = 0;
	while (buf)
	{
		if (s_min > buf->value)
			return (-1);
		s_min = buf->value;
		buf = buf->next;
	}
	buf = stack;
	while (buf != min && oper++ != -1)
	{
		if (s_min > buf->value)
			return (-1);
		s_min = buf->value;
		buf = buf->next;
	}
	return (oper);
}
