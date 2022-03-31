/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:42:11 by ereginia          #+#    #+#             */
/*   Updated: 2021/10/15 11:56:49 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rev(char *start, char *final, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		final[i] = start[len - 1 - i];
		i++;
	}
	final[i] = '\0';
}

static int	mas(char *start, unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		start[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static int	module(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

char	*ft_itoa(int n)
{
	char	start[12];
	char	final[12];
	char	*num;
	int		len;

	len = mas(start, module(n));
	rev(start, final, len);
	if (n <= 0)
		len++;
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	if (n <= 0)
	{
		if (n == 0)
			num[0] = '0';
		else
			num[0] = '-';
		ft_strlcpy(&num[1], final, len + 1);
	}
	else
		ft_strlcpy(num, final, len + 1);
	return (num);
}
