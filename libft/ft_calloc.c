/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:31:38 by ereginia          #+#    #+#             */
/*   Updated: 2021/10/15 12:01:54 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	arr = malloc(num * size);
	if (arr)
	{
		i = 0;
		while (i < num * size)
		{
			arr[i] = '\0';
			i++;
		}
	}
	return ((void *)arr);
}
