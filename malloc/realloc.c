/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:16:19 by amathias          #+#    #+#             */
/*   Updated: 2017/03/11 13:12:47 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*copy_chunk(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	new_ptr = malloc(new_size);
	if (new_ptr)
	{
		new_ptr = ft_memcpy((void*)new_ptr, (void*)ptr, old_size);
		free(ptr);
		return (new_ptr);
	}
	return (NULL);
}

void	*realloc_small(t_chunk **chunk, size_t chunk_size, void *ptr,
			size_t new_size)
{
	t_chunk	*temp;
	int		i;

	temp = *chunk;
	while (temp)
	{
		i = 0;
		while (i < BLOCKS_MAX)
		{
			if ((char*)temp + sizeof(t_chunk) + (i * chunk_size) == ptr)
			{
				if (new_size < chunk_size)
				{
					temp->blocks[i] = new_size;
					return (ptr);
				}
				return ((void*)copy_chunk(ptr, temp->blocks[i], new_size));
			}
			i++;
		}
		temp = temp->next;
	}
	return (NULL);
}

void	*copy_alloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	new_ptr = malloc(new_size);
	if (new_ptr)
	{
		new_ptr = ft_memcpy((char*)new_ptr, (char*)ptr, old_size);
		free(ptr);
		return (new_ptr);
	}
	return (NULL);
}

void	*realloc_large(t_alloc **alloc, void *ptr, size_t new_size)
{
	t_alloc	*temp;
	size_t	old_size;

	temp = *alloc;
	while (temp)
	{
		if ((char*)temp + sizeof(t_alloc) == ptr)
		{
			old_size = temp->size;
			if (new_size < old_size)
			{
				munmap((char*)ptr + new_size, old_size);
				temp->size = new_size;
				return (ptr);
			}
			return ((char*)copy_alloc(ptr, old_size, new_size));
		}
		temp = temp->next;
	}
	return (0);
}

void	*realloc(void *ptr, size_t size)
{
	void *new_ptr;

	if (ptr == NULL || size <= 0)
		new_ptr = malloc(size);
	new_ptr = realloc_small(&g_malloc.tiny, TINY_MAX, ptr, size);
	if (new_ptr != NULL)
		return (new_ptr);
	new_ptr = realloc_small(&g_malloc.small, SMALL_MAX, ptr, size);
	if (new_ptr != NULL)
		return (new_ptr);
	if ((new_ptr = realloc_large(&g_malloc.large, ptr, size)) != NULL)
		return (new_ptr);
	return (malloc(size));
}
