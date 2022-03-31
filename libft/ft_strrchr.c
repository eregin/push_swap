/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:47:32 by ereginia          #+#    #+#             */
/*   Updated: 2021/10/16 15:45:34 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != (char)ch && i > 0)
		i--;
	if (str[i] != (char)ch)
		return (NULL);
	return ((char *)(str + i));
}
