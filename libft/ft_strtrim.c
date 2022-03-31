/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:40:30 by ereginia          #+#    #+#             */
/*   Updated: 2021/10/16 18:11:20 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getstart(char const *s1, char const *set)
{
	int	k;
	int	flag;
	int	i;

	k = 0;
	i = 0;
	flag = 0;
	while (set[k])
	{
		while (s1[i] == set[k])
		{
			i++;
			flag = 1;
		}
		k++;
		if (set[k] == '\0' && flag)
		{
			flag = 0;
			k = 0;
		}
	}
	return (i);
}

static int	getend(char const *s1, char const *set, int start, int end)
{
	int	k;
	int	flag;
	int	i;
	int	j;

	k = 0;
	flag = 0;
	i = start;
	j = end;
	while (set[k])
	{
		while (s1[j - 1] == set[k] && j > i)
		{
			j--;
			flag = 1;
		}
		k++;
		if (set[k] == '\0' && flag)
		{
			flag = 0;
			k = 0;
		}
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	int		flag;
	char	*final;

	k = 0;
	j = ft_strlen(s1);
	i = getstart(s1, set);
	j = getend(s1, set, i, j);
	final = (char *)malloc(sizeof(char) * (j - i + 1));
	if (final)
	{
		flag = j - i;
		while (k < flag)
		{
			final[k] = s1[i];
			k++;
			i++;
		}
		final[k] = '\0';
		return (final);
	}
	else
		return (NULL);
}
