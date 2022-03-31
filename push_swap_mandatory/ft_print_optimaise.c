/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_optimaise.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:29:21 by ereginia          #+#    #+#             */
/*   Updated: 2022/02/06 14:35:18 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_free_str(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static char	*ft_joining(char *str)
{
	char	**spt;
	char	*buf;
	int		i;

	i = 0;
	spt = ft_split(str, '*');
	free(str);
	str = ft_strdup("");
	while (spt[i])
	{
		buf = str;
		str = ft_strjoin(str, spt[i]);
		free(buf);
		i++;
	}
	ft_free_str(spt);
	return (str);
}

void	optimase(char *stam)
{
	char	*str;
	int		flag;

	flag = 0;
	if (stam == NULL)
		str = string_output("");
	else
		str = stam;
	flag = string_optimase_rotate(str) + string_optimase_push(str)
		+ string_optimase_swap(str);
	str = ft_joining(str);
	if (flag)
		optimase(str);
	else
	{
		ft_putstr_fd(str, 1);
		free(str);
	}
	return ;
}
