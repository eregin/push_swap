/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:23:59 by ereginia          #+#    #+#             */
/*   Updated: 2021/10/16 18:06:29 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*strj;
	size_t			i;
	unsigned int	d;
	unsigned int	c;

	c = (unsigned int)ft_strlen(s1);
	d = (unsigned int)ft_strlen(s2);
	strj = (char *)malloc(sizeof(char) * (c + d + 1));
	i = 0;
	if (strj)
	{
		while (i++ < c)
			strj[i - 1] = s1[i - 1];
		i = 0;
		while (i < d)
		{
			strj[c + i] = s2[i];
			i++;
		}
		strj[c + d] = '\0';
		return (strj);
	}
	else
		return (NULL);
}
