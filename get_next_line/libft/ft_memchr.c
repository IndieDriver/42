/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:03:09 by amathias          #+#    #+#             */
/*   Updated: 2015/11/25 16:36:09 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*sptr;
	size_t	i;

	i = 0;
	sptr = (char*)s;
	while (i < n)
	{
		if (sptr[i] == (char)c)
			return (&sptr[i]);
		i++;
	}
	return (NULL);
}
