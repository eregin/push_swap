/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:52:17 by ereginia          #+#    #+#             */
/*   Updated: 2022/02/06 15:47:56 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_check_number(long long int number, char c)
{
	if (c != '\0')
	{
		ft_putstr_fd("Error\nnot valid input\n", 2);
		exit(EXIT_FAILURE);
	}
	if (number > 2147483647 || number < -2147483648)
	{
		ft_putstr_fd("Error\nnumber out of range\n", 2);
		exit(EXIT_FAILURE);
	}
}

static int	ft_atoi_max(const char *str)
{
	int				i;
	int				sign;
	long long int	num;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	if ((str[i] == '0' && str[i + 1] != '\0')
		|| (str[0] == '-' && (str[i] == '0' || str[i] == '\0')))
	{
		ft_putstr_fd("Error\nnot valid input\n", 2);
		exit(EXIT_FAILURE);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	ft_check_number(sign * num, str[i]);
	return (sign * num);
}

void	ft_validate(int count, char **vals)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		if (vals[i][0] == '\0')
		{
			ft_putstr_fd("Error\nnot valid input\n", 2);
			exit(EXIT_FAILURE);
		}
		while (vals[i][j])
		{
			if ((vals[i][j] != ' ' && vals[i][j] != '-')
					&& (vals[i][j] < '0' || vals[i][j] > '9'))
			{
				ft_putstr_fd("Error\nnot valid input\n", 2);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	stack_a_init(t_stack **stack, int count, char **val)
{
	t_stack	*buf;
	char	**spt_buf;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < 3)
		stack[i] = NULL;
	while (j < count)
	{
		i = 0;
		spt_buf = ft_split(val[j], ' ');
		while (spt_buf[i])
		{
			buf = ft_stknew(ft_atoi_max(spt_buf[i]));
			buf->side = 0;
			ft_stkadd_back(&stack[0], buf);
			i++;
		}
		ft_free_split(spt_buf);
		j++;
	}
	ft_check_same_numbers(stack, ft_stksize(stack[0]));
}

void	ft_check_same_numbers(t_stack **stack, int size)
{
	t_stack	*buf;
	int		i;
	int		j;
	int		srav;

	i = -1;
	while (++i < size)
	{
		buf = stack[0];
		j = 0;
		while (j++ < i)
			buf = buf->next;
		srav = buf->value;
		while (buf->next)
		{
			if (buf->next->value == srav)
			{
				ft_putstr_fd("Error\nsome elements has same values\n", 2);
				ft_free_stack(stack, 0);
				exit(EXIT_FAILURE);
			}
			buf = buf->next;
		}
	}
}
