/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 12:21:17 by amathias          #+#    #+#             */
/*   Updated: 2017/03/11 13:13:49 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	print_memory_addr(void *ptr)
{
	size_t addr;

	addr = (size_t)ptr;
	ft_putstr("0x");
	ft_put_addr((size_t)addr);
}

void	print_block(void *ptr, size_t size)
{
	ft_putstr("\t");
	print_memory_addr(ptr);
	ft_putstr(" - ");
	print_memory_addr((char*)ptr + size);
	ft_putstr(" : ");
	ft_putnbr((int)size);
	ft_putstr(" octets\n");
}

void	show_alloc_small(t_chunk *chunk, size_t chunk_size, char *name)
{
	t_chunk	*temp;
	int		i;

	temp = chunk;
	ft_putstr(name);
	print_memory_addr(chunk);
	ft_putstr("\n");
	while (temp)
	{
		i = 0;
		while (i < BLOCKS_MAX)
		{
			if (temp->blocks[i] != 0)
			{
				print_block((char*)temp + sizeof(t_chunk) + (i * chunk_size),
						temp->blocks[i]);
			}
			i++;
		}
		temp = temp->next;
	}
}

void	show_alloc_large(t_alloc *alloc, char *name)
{
	t_alloc *temp;

	temp = alloc;
	ft_putstr(name);
	print_memory_addr(alloc);
	ft_putstr("\n");
	while (temp)
	{
		print_block((char*)temp + sizeof(t_alloc), temp->size);
		temp = temp->next;
	}
}

void	show_alloc_mem(void)
{
	if (g_malloc.tiny != NULL)
		show_alloc_small(g_malloc.tiny, TINY_MAX, "TINY : ");
	if (g_malloc.small != NULL)
		show_alloc_small(g_malloc.small, SMALL_MAX, "SMALL : ");
	if (g_malloc.large != NULL)
		show_alloc_large(g_malloc.large, "LARGE : ");
}
