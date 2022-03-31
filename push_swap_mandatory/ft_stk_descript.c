/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_descript.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:45:04 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/27 17:03:47 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_mass_median(int *mass, int count)
{
	int	i;
	int	j;
	int	buf;

	i = 0;
	j = 0;
	buf = 0;
	while (i++ < (count / 2 + count % 2) - 1)
	{
		while (j < count)
		{
			if (mass[j] < mass[buf])
				buf = j;
			j++;
		}
		mass[buf] = 2147483647;
		j = 0;
	}
	while (j < count)
	{
		if (mass[j] < mass[buf])
			buf = j;
		j++;
	}
	return (mass[buf]);
}

int	find_stk_median(t_stack *stack)
{
	t_stack	*buf;
	int		*mass;
	int		count;
	int		i;

	i = 0;
	count = ft_stksize(stack);
	buf = stack;
	mass = (int *)malloc(sizeof(int) * (count + 1));
	while (i < count)
	{
		mass[i] = buf->value;
		buf = buf->next;
		i++;
	}
	mass[i] = 0;
	i = find_mass_median(mass, count);
	free(mass);
	return (i);
}

t_stack	*find_stk_min(t_stack *stack)
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

t_stack	*find_stk_max(t_stack *stack)
{
	t_stack	*res;
	t_stack	*buf;

	buf = stack;
	res = stack;
	while (buf)
	{
		if (buf->value > res->value)
			res = buf;
		buf = buf->next;
	}
	return (res);
}
