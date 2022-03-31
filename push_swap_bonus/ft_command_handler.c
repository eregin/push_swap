/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:34:26 by ereginia          #+#    #+#             */
/*   Updated: 2022/02/06 13:36:33 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_stack_a_handler(t_stack **stack, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		ft_swap(&stack[0], stack[0]);
	if (ft_strncmp(str, "ra\n", 3) == 0)
		ft_rotate(&stack[0], stack[0]);
	if (ft_strncmp(str, "rra\n", 4) == 0)
		ft_reverse_rotate(&stack[0], stack[0]);
	if (ft_strncmp(str, "pa\n", 3) == 0)
		ft_push(&stack[1], &stack[0], stack[1], stack[0]);
}

static void	ft_stack_b_handler(t_stack **stack, char *str)
{
	if (ft_strncmp(str, "sb\n", 3) == 0)
		ft_swap(&stack[1], stack[1]);
	if (ft_strncmp(str, "rb\n", 3) == 0)
		ft_rotate(&stack[1], stack[1]);
	if (ft_strncmp(str, "rrb\n", 4) == 0)
		ft_reverse_rotate(&stack[1], stack[1]);
	if (ft_strncmp(str, "pb\n", 3) == 0)
		ft_push(&stack[0], &stack[1], stack[0], stack[1]);
}

static void	ft_stack_ab_handler(t_stack **stack, char *str)
{
	if (ft_strncmp(str, "ss\n", 3) == 0)
	{
		ft_swap(&stack[0], stack[0]);
		ft_swap(&stack[1], stack[1]);
	}
	else if (ft_strncmp(str, "rr\n", 3) == 0)
	{
		ft_rotate(&stack[0], stack[0]);
		ft_rotate(&stack[1], stack[1]);
	}
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
	{
		ft_reverse_rotate(&stack[0], stack[0]);
		ft_reverse_rotate(&stack[1], stack[1]);
	}
}

static void	ft_check_valid_command(t_stack	**stack, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) && ft_strncmp(str, "ra\n", 3)
		&& ft_strncmp(str, "rra\n", 4) && ft_strncmp(str, "pa\n", 3)
		&& ft_strncmp(str, "sb\n", 3) && ft_strncmp(str, "rb\n", 3)
		&& ft_strncmp(str, "rrb\n", 4) && ft_strncmp(str, "pb\n", 3)
		&& ft_strncmp(str, "ss\n", 3) && ft_strncmp(str, "rr\n", 3)
		&& ft_strncmp(str, "rrr\n", 4))
	{
		ft_putstr_fd("wrong command ", 1);
		ft_putstr_fd(str, 1);
		ft_free_stack(stack, 0);
		exit(EXIT_FAILURE);
	}
}

void	ft_command_handler(t_stack	**stack, char *str)
{
	if (str == NULL)
		return ;
	ft_check_valid_command(stack, str);
	ft_stack_a_handler(stack, str);
	ft_stack_b_handler(stack, str);
	ft_stack_ab_handler(stack, str);
}
