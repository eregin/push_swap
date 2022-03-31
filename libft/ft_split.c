/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:49:20 by ereginia          #+#    #+#             */
/*   Updated: 2021/10/18 16:09:21 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countword(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				count++;
		}
		i++;
	}
	return (count);
}

static char	*getword(char *s, char c, int cword)
{
	int		i;
	int		j;
	int		p;
	int		l;
	char	*str;

	i = 0;
	j = 0;
	while (s[i] && j < cword + 1)
	{
		while (s[i] == c)
			i++;
		p = i;
		while (s[i] && s[i] != c)
			i++;
		l = i;
		j++;
	}
	str = (char *)malloc(sizeof(char) * (l - p + 1));
	if (str)
		ft_strlcpy(str, &s[p], (l - p + 1));
	return (str);
}

void	ft_free(char **splitted, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**final;
	char	*buf;
	int		wcont;
	int		i;

	i = 0;
	buf = (char *) s;
	wcont = countword(buf, c);
	final = (char **)malloc(sizeof(char *) * (wcont + 1));
	if (!final)
		return (NULL);
	while (i < wcont)
	{
		final[i] = getword(buf, c, i);
		if (!final[i])
			break ;
		i++;
	}
	if (i < wcont)
	{
		ft_free(final, i);
		return (NULL);
	}
	final[i] = NULL;
	return (final);
}
