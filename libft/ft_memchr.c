/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:02:05 by ereginia          #+#    #+#             */
/*   Updated: 2021/10/15 12:07:14 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned const char	*buf;
	size_t				i;

	buf = arr;
	i = 0;
	while (i < n && buf[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	return ((void *)(arr + i));
}
