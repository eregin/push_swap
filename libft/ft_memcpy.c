/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:48:32 by ereginia          #+#    #+#             */
/*   Updated: 2021/10/13 16:00:59 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned const char	*buf1;
	unsigned char		*buf2;

	buf1 = src;
	buf2 = dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		buf2[i] = buf1[i];
		i++;
	}
	return (dest);
}
