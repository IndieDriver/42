/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:20:19 by amathias          #+#    #+#             */
/*   Updated: 2015/12/08 18:36:30 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	mem = NULL;
	mem = (unsigned char *)malloc(size);
	if (mem)
	{
		while (size--)
		{
			mem[i] = 0;
			i++;
		}
	}
	return ((void *)mem);
}
