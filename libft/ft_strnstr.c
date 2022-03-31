/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:05:59 by ereginia          #+#    #+#             */
/*   Updated: 2021/10/15 12:39:28 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *strB, const char *strA, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (strA[0] == '\0')
		return ((char *)strB);
	while (strB[i] && i < len)
	{
		if (strB[i] == strA[j])
		{
			j++;
			if (strA[j] == '\0')
				return ((char *)(strB + i - j + 1));
		}
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
