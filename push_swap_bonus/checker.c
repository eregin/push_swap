/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:08:19 by ereginia          #+#    #+#             */
/*   Updated: 2022/02/06 15:45:17 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*string_output(char *operation)
{
	static char	*result;
	char		*buf;

	buf = result;
	if (result == NULL)
		result = ft_strdup(operation);
	else
		result = ft_strjoin(result, operation);
	free(buf);
	return (result);
}

int	main(int argc, char **argv)
{
	t_stack	*stack[3];
	char	*buf;

	ft_validate(argc - 1, &argv[1]);
	stack_a_init(stack, argc - 1, &argv[1]);
	if (argc < 2)
		return (1);
	buf = (void *)1;
	while (buf)
	{
		buf = get_next_line(0);
		ft_command_handler(stack, buf);
		free(buf);
	}
	if (ft_is_sorted_left(stack[0]) == 0 && stack[1] == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_stack(stack, 0);
}
