/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:16:19 by amathias          #+#    #+#             */
/*   Updated: 2017/03/11 13:12:47 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*calloc(size_t nitems, size_t size)
{
	void *ptr;

	ptr = malloc(nitems * size);
	if (ptr != NULL)
		ft_bzero(ptr, nitems * size);
	return (ptr);
}
