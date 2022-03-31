/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:54:08 by ereginia          #+#    #+#             */
/*   Updated: 2021/10/16 15:11:49 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(dest);
	if (size <= n)
		return (size + ft_strlen(src));
	while (src[i])
	{
		if ((i + n) < size - 1 && size != 0)
			dest[n + i] = src[i];
		i++;
	}
	if (i + n > size)
		dest[size - 1] = '\0';
	else
		dest[i + n] = '\0';
	return (i + n);
}
