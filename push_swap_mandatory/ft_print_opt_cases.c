/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_opt_cases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:36:36 by ereginia          #+#    #+#             */
/*   Updated: 2022/02/02 13:05:43 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_any_case(char *str, int cased)
{
	if (cased == 0)
	{
		return (ft_strncmp(str, "ra\nrra\n", 7) == 0
			|| ft_strncmp(str, "rra\nra\n", 7) == 0
			|| ft_strncmp(str, "rb\nrrb\n", 7) == 0
			|| ft_strncmp(str, "rrb\nrb\n", 7) == 0);
	}
	else if (cased == 1)
	{
		return (ft_strncmp(str, "pa\npb\n", 6) == 0
			|| ft_strncmp(str, "pb\npa\n", 6) == 0);
	}
	else if (cased == 2)
	{
		return (ft_strncmp(str, "sa\nsb\n", 6) == 0
			|| ft_strncmp(str, "sb\nsa\n", 6) == 0);
	}
	return (0);
}

int	string_optimase_rotate(char *str)
{
	int		i;
	int		j;
	char	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		j = 0;
		if (ft_any_case(&str[i], 0))
		{
			flag = 1;
			while (j < 7)
			{
				str[i + j] = '*';
				j++;
			}
		}
		i = i + j;
		while ((str[i] != '\n' || str[i] == '*') && str[i])
			i++;
		i++;
	}
	return (flag);
}

int	string_optimase_push(char *str)
{
	int		i;
	int		j;
	char	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		j = 0;
		if (ft_any_case(&str[i], 1))
		{
			flag = 1;
			while (j < 6)
			{
				str[i + j] = '*';
				j++;
			}
		}
		i = i + j;
		while ((str[i] != '\n' || str[i] == '*') && str[i])
			i++;
		i++;
	}
	return (flag);
}

int	string_optimase_swap(char *str)
{
	int		i;
	int		j;
	char	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		j = 0;
		if (ft_any_case(&str[i], 2))
		{
			flag = 1;
			while (j < 3)
				str[i + j++] = '*';
			str[i + j++] = 's';
			str[i + j++] = 's';
			str[i + j++] = '\n';
		}
		i = i + j;
		while ((str[i] != '\n' || str[i] == '*') && str[i])
			i++;
		i++;
	}
	return (flag);
}
