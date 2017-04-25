/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 13:07:03 by amathias          #+#    #+#             */
/*   Updated: 2017/03/11 13:09:47 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/mman.h>
# include "libft.h"

# define TINY_MAX 512
# define SMALL_MAX 4096
# define BLOCKS_MAX 128

typedef struct		s_alloc
{
	struct s_alloc	*next;
	size_t			size;
}					t_alloc;

typedef struct		s_chunk
{
	struct s_chunk	*next;
	size_t			blocks[BLOCKS_MAX];
}					t_chunk;

typedef struct		s_malloc
{
	t_chunk			*tiny;
	t_chunk			*small;
	t_alloc			*large;
}					t_malloc;

t_malloc			g_malloc;

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem();
int					is_chunk_free(t_chunk *chunk);
void				ft_put_addr(size_t size);

#endif
