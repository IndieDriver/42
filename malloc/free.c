#include "malloc.h"

int     is_chunk_free(t_chunk *chunk)
{
    int i;

    i = 0;
    while (i < BLOCKS_MAX)
    {
        if (chunk->blocks[i] != 0)
            return (0);
        i++;
    }
    return (1);
}

int     free_alloc_small(t_chunk **chunk, size_t chunk_size, void *ptr)
{
    t_chunk *temp;
    int     i;

    temp = *chunk;
    while (temp)
    {
        i = 0;
        while (i < BLOCKS_MAX)
        {
            printf("%p %p\n", temp + sizeof(t_chunk) + (i * chunk_size), ptr);
            if (temp + sizeof(t_chunk) + (i * chunk_size) == ptr)
            {
                printf("found ptr\n");
                temp->blocks[i] = 0;
                if (is_chunk_free(temp))
                {
                    printf("DELETE CHUNK\n");
                   //TODO: Delete node
                   munmap(temp, BLOCKS_MAX * chunk_size); 
                }
                return (1);
            }
            i++;
        }
        temp = temp->next;
    }
    return (0);
}

int     free_alloc_big(){

    return (0);
}

void	free(void *ptr)
{   
    printf("call free: %p\n", ptr);
    if (free_alloc_small(&smalloc.tiny, TINY_MAX, ptr))
       return ;
    if (free_alloc_small(&smalloc.small, SMALL_MAX, ptr))
       return ;
    if (free_alloc_big())
       return ;
}
