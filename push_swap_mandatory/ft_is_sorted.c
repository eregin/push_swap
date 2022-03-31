/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:46:31 by ereginia          #+#    #+#             */
/*   Updated: 2022/01/27 16:35:24 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//максимальная чанка
int	ft_max_order(t_stack **stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i - 1);
}

//максимальная чанка выбранной стороны
int	ft_max_order_side(t_stack **stack, int side)
{
	int	max;
	int	i;

	i = 0;
	max = -1;
	while (stack[i])
	{
		if (stack[i]->side == side)
			max = i;
		i++;
	}
	return (max);
}

//номер чанки которая находится под выбранной чанкой
int	ft_premax_order_side(t_stack **stack, int side)
{
	int	premax;
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i]->side == side)
			premax = i;
		i++;
	}
	while (premax > 0)
	{
		premax--;
		if (stack[premax]->side == side)
			break ;
	}
	return (premax);
}

//количество чанок выбранной стороны
int	ft_unic_side(t_stack **stack, int side)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (stack[i])
	{
		if (stack[i]->side == side)
			p++;
		i++;
	}
	return (p);
}
