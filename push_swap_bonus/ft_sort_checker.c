/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:26:28 by ereginia          #+#    #+#             */
/*   Updated: 2022/02/06 13:23:03 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static t_stack	*find_stk_min(t_stack *stack)
{
	t_stack	*res;
	t_stack	*buf;

	buf = stack;
	res = stack;
	while (buf)
	{
		if (buf->value < res->value)
			res = buf;
		buf = buf->next;
	}
	return (res);
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
