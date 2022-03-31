/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:42:22 by ereginia          #+#    #+#             */
/*   Updated: 2022/02/06 14:20:57 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack[32];
	int		i;

	i = 0;
	ft_validate(argc - 1, &argv[1]);
	stack_a_init(stack, argc - 1, &argv[1]);
	if (argc < 2)
		return (1);
	while (1)
	{
		if (ft_unic_side(stack, 0) == 1 && ft_unic_side(stack, 1) == 1
			&& ft_is_sorted_right(stack[1]) == 0
			&& ft_is_sorted_left(stack[0]) == 0)
			break ;
		if (ft_is_sorted_left(stack[0]) == 0 && ft_unic_side(stack, 1) == 0)
			break ;
		if (stack[ft_max_order(stack)]->side == 0)
			chanking_left(stack, ft_max_order(stack));
		else
			chanking_right(stack, ft_max_order(stack));
	}
	while (ft_unic_side(stack, 1) != 0)
		ft_push(&stack[1], &stack[0], stack[1], stack[0]);
	optimase(NULL);
	ft_free_stack(stack, 0);
}
