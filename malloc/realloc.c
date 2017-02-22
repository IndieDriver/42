#include "malloc.h"

void    *realloc_small(t_chunk **chunk, size_t chunk_size, void *ptr, size_t new_size)
{
    t_chunk *temp;
    int     i;

    temp = *chunk;
    while (temp)
    {
        i = 0;
        while (i < BLOCKS_MAX)
        {
            if (temp + sizeof(t_chunk) + (i * chunk_size) == ptr)
            {
                if (new_size < chunk_size){
                    temp->blocks[i] = new_size;
                    return (ptr); //Node is already at the good size
                }
                //TODO: create new node, copy and free 
            }
            i++;
        }
    }
    return (NULL);
}

void    *realloc_large(t_alloc **alloc, void *ptr, size_t new_size)
{
    t_alloc *temp;

    (void)new_size;
    temp = *alloc;
    while (temp)
    {
        if (temp + sizeof(t_alloc) == ptr)
        {
            //TODO: if new_size smaller munmap remaining
            //TODO: if new_size buffer create new node, copy and free previous one
        }
        temp = temp->next;
    }
    return (0);
}

void	*realloc(void *ptr, size_t size)
{
    printf("call realloc: %p (size: %ld)\n", ptr, size);
	(void)ptr;
	(void)size;
	return (NULL);	
}
