/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:35:44 by amathias          #+#    #+#             */
/*   Updated: 2015/11/27 11:29:17 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*tmpdest;
	const char	*tmpsrc;
	size_t		n;
	size_t		destlen;

	n = size;
	tmpdest = dst;
	tmpsrc = src;
	while (n-- != 0 && *tmpdest != '\0')
		tmpdest++;
	destlen = tmpdest - dst;
	n = size - destlen;
	if (n == 0)
		return (destlen + ft_strlen(tmpsrc));
	while (*tmpsrc != '\0')
	{
		if (n != 1)
		{
			*tmpdest++ = *tmpsrc;
			n--;
		}
		tmpsrc++;
	}
	*tmpdest = '\0';
	return (destlen + (tmpsrc - src));
}
