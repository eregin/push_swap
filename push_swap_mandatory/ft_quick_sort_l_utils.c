/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_l_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:34:22 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/28 13:00:53 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_unic_three_handle_left(t_stack **stack)
{
	int	k;

	k = ft_is_sorted_left(stack[0]);
	if (k == 1)
		ft_rotate(&stack[0], stack[0]);
	else if (k == 2)
		ft_reverse_rotate(&stack[0], stack[0]);
	else if (k < 0)
	{
		ft_swap(&stack[0], stack[0]);
		three_handle_left(stack);
	}
}

void	ft_not_unic_three_handle_left(t_stack **stack, int iter)
{
	int	max;
	int	r_max;
	int	p_max;

	max = ft_max_order_side(stack, 0);
	r_max = ft_max_order_side(stack, 1);
	p_max = ft_premax_order_side(stack, 0);
	if (ft_stksize(stack[max]) < 3)
	{
		if (ft_is_sorted_left(stack[max]) == 1)
			ft_swap(&stack[max], stack[max]);
		return ;
	}
	while (stack[max]->value != find_stk_min(stack[max])->value)
	{
		ft_rotate(&stack[max], stack[max]);
		iter++;
	}
	ft_push(&stack[max], &stack[max + 1], stack[max], stack[max + 1]);
	while (iter--)
		ft_reverse_rotate(&stack[max], stack[max]);
	if (ft_is_sorted_left(stack[max]) == 1)
		ft_swap(&stack[max], stack[max]);
	ft_push(&stack[max + 1], &stack[max], stack[max + 1], stack[max]);
}

void	ft_normal_chank_handler_left(t_stack **stack, int k, int order)
{
	int		med;
	int		oper;
	int		i;

	i = ft_stksize(stack[order]);
	med = find_stk_median(stack[order]);
	oper = 0;
	while (ft_stksize(stack[order]) > i / 2)
	{
		if (stack[order]->value <= med)
			ft_push(&stack[order], &stack[k], stack[order], stack[k]);
		else
		{
			ft_rotate(&stack[order], stack[order]);
			oper++;
		}
	}
	if (ft_unic_side(stack, 0) > 1)
	{
		while (oper-- > 0)
			ft_reverse_rotate(&stack[order], stack[order]);
	}
}
