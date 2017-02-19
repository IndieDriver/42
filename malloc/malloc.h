#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/mman.h>
# include "libft.h"

# define TINY_MAX 512
# define SMALL_MAX 4096

typedef struct s_alloc
{
  void         *ptr;
  void         *next;
}              t_alloc;

typedef struct s_chunk
{
  void         *start;
  t_alloc      *ptr;
}              t_chunk;

typedef struct s_malloc{
    t_chunk    *tiny;
    t_chunk    *small;
    t_alloc    *large;
}              t_malloc;


t_malloc       smalloc;

void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void show_alloc_mem();

#endif
