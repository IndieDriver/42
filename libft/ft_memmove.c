/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:40:14 by amathias          #+#    #+#             */
/*   Updated: 2015/12/08 14:37:32 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str_dest;
	unsigned char	*str_src;
	size_t			i;

	i = 0;
	str_dest = ((unsigned char *)dest);
	str_src = ((unsigned char *)src);
	if (str_dest > str_src)
	{
		while (i < n)
		{
			str_dest[n - 1] = str_src[n - 1];
			n--;
		}
		return (dest);
	}
	else
		while (i < n)
		{
			str_dest[i] = str_src[i];
			i++;
		}
	return (dest);
}
