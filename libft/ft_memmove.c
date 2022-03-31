/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:58:27 by ereginia          #+#    #+#             */
/*   Updated: 2021/10/15 12:16:48 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned const char	*buf1;
	unsigned char		*buf2;

	if (n == 0 || dest == src)
		return (dest);
	buf1 = src;
	buf2 = dest;
	i = 0;
	if (src > dest)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			n--;
			buf2[n] = buf1[n];
		}
	}
	return (dest);
}
