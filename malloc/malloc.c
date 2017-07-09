/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 11:28:44 by amathias          #+#    #+#             */
/*   Updated: 2017/03/11 13:11:44 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*is_free_node(t_chunk *chunk, size_t chunk_size, size_t malloc_size)
{
	int i;

	i = 0;
	while (i < BLOCKS_MAX)
	{
		if (chunk->blocks[i] == 0)
		{
			chunk->blocks[i] = malloc_size;
			return ((char*)chunk + sizeof(t_chunk) + (i * chunk_size));
		}
		i++;
	}
	return (NULL);
}

void	add_chunk_node(t_chunk **begin, t_chunk *new)
{
	new->next = *begin;
	*begin = new;
}

void	*malloc_small(t_chunk **chunk, size_t chunk_size, size_t malloc_size)
{
	t_chunk	*new_chunk;
	void	*free_addr;

	free_addr = NULL;
	if (!*chunk)
	{
		*chunk = mmap(NULL, chunk_size * BLOCKS_MAX + sizeof(t_chunk),
				PROT_WRITE | PROT_READ,
				MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		ft_memset(*chunk, 0, chunk_size * BLOCKS_MAX + sizeof(t_chunk));
	}
	while ((free_addr = is_free_node(*chunk, chunk_size, malloc_size)) == NULL)
	{
		new_chunk = mmap(NULL, chunk_size * BLOCKS_MAX + sizeof(t_chunk),
				PROT_WRITE | PROT_READ,
				MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		ft_memset(new_chunk, 0, chunk_size * BLOCKS_MAX + sizeof(t_chunk));
		add_chunk_node(chunk, new_chunk);
	}
	return (free_addr);
}

void	*malloc_large(t_alloc **begin, size_t malloc_size)
{
	t_alloc *node;

	node = mmap(NULL, malloc_size + sizeof(t_alloc),
			PROT_WRITE | PROT_READ,
			MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	node->size = malloc_size;
	node->next = *begin;
	*begin = node;
	return ((char*)node + sizeof(t_alloc));
}

void	*malloc(size_t size)
{
	void *ptr;

	ptr = NULL;
	if (size <= 0)
		ptr = NULL;
	else if (size <= TINY_MAX)
		ptr = malloc_small(&g_malloc.tiny, TINY_MAX, size);
	else if (size <= SMALL_MAX)
		ptr = malloc_small(&g_malloc.small, SMALL_MAX, size);
	else
		ptr = malloc_large(&g_malloc.large, size);
	return (ptr);
}
