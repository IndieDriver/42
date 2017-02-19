/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:56:30 by amathias          #+#    #+#             */
/*   Updated: 2015/12/14 12:04:32 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *destptr;
	char *srcptr;

	destptr = dest;
	srcptr = (char*)src;
	while (n > 0)
	{
		*destptr++ = *srcptr++;
		n--;
	}
	return (dest);
}
