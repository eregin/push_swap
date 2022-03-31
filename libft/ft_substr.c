/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereginia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:53:48 by ereginia          #+#    #+#             */
/*   Updated: 2021/10/16 18:02:11 by ereginia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;
	unsigned int	d;

	if (s == NULL)
		return ((char *)s);
	d = (unsigned int)ft_strlen(s);
	if (start > d)
		len = 0;
	else if (len > d)
		len = d;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (sub)
	{
		while (i < len && s[start + i])
		{
			sub[i] = s[start + i];
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
	else
		return (NULL);
}
