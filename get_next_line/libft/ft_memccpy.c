/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:16:14 by amathias          #+#    #+#             */
/*   Updated: 2015/11/25 16:36:01 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*destptr;
	char	*srcptr;
	size_t	i;

	i = 0;
	destptr = (char*)dest;
	srcptr = (char*)src;
	while (i < n)
	{
		destptr[i] = srcptr[i];
		if (srcptr[i] == c)
			return ((char*)&destptr[i] + 1);
		i++;
	}
	return (NULL);
}
