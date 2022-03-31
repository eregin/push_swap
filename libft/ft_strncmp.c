/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:21:09 by ereginia          #+#    #+#             */
/*   Updated: 2021/10/13 16:43:34 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
			i++;
	}
	else
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
