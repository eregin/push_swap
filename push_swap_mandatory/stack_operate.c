/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:59:54 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/29 12:39:24 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **st_ptr, t_stack *stack)
{
	t_stack	*buf_one;
	t_stack	*buf_two;
	t_stack	*buf_thr;

	if (stack->side == 0)
		string_output("sa\n");
	else
		string_output("sb\n");
	buf_one = stack;
	buf_two = stack->next;
	buf_thr = stack->next->next;
	stack->next->next = buf_one;
	stack->next = buf_thr;
	*st_ptr = buf_two;
}

void	ft_reverse_rotate(t_stack **st_ptr, t_stack *stack)
{
	t_stack	*buf_one;
	t_stack	*buf_prelast;
	t_stack	*buf_last;
	t_stack	*buf;

	if (stack->side == 0)
		string_output("rra\n");
	else
		string_output("rrb\n");
	buf_one = stack;
	buf_prelast = ft_stkprelast(stack);
	buf_last = ft_stklast(stack);
	buf = buf_last;
	buf->next = buf_one;
	buf = buf_prelast;
	buf->next = NULL;
	*st_ptr = buf_last;
}

void	ft_rotate(t_stack **st_ptr, t_stack *stack)
{
	t_stack	*buf_one;
	t_stack	*buf_two;
	t_stack	*buf_last;

	if (stack->side == 0)
		string_output("ra\n");
	else
		string_output("rb\n");
	buf_one = stack;
	buf_two = stack->next;
	buf_last = ft_stklast(stack);
	stack->next = NULL;
	buf_last->next = buf_one;
	*st_ptr = buf_two;
}

void	ft_push(t_stack **st_ptr_a, t_stack **st_ptr_b,
		t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->side == 1)
		string_output("pa\n");
	else
		string_output("pb\n");
	if (ft_stksize(stack_a) > 0)
	{
		*st_ptr_a = stack_a->next;
		*st_ptr_b = stack_a;
		stack_a->next = stack_b;
		stack_a->side = !stack_a->side;
	}
}

void	ft_merge(t_stack **st_ptr_a, t_stack **st_ptr_b,
		t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*buf_last;

	(void)stack_a;
	buf_last = ft_stklast(stack_b);
	buf_last->next = *st_ptr_a;
	*st_ptr_a = *st_ptr_b;
	*st_ptr_b = NULL;
}
