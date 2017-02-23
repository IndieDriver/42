#include "malloc.h"

void    delete_alloc(t_alloc **start, t_alloc *to_delete) 
{
    t_alloc *temp;

    temp = *start;
    if (temp == to_delete)
        *start = temp->next;
    else
    {
       while (temp->next != NULL && temp->next != to_delete)
          temp = temp->next; 
       temp->next = temp->next->next;
    }

}

void    delete_chunk(t_chunk **start, t_chunk *to_delete)
{
    t_chunk *temp;

    temp = *start;
    if (temp == to_delete)
        *start = temp->next;
    else
    {
       while (temp->next != NULL && temp->next != to_delete)
          temp = temp->next; 
       temp->next = temp->next->next;
    }
}

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
            if ((void*)temp + sizeof(t_chunk) + (i * chunk_size) == ptr)
            {
                temp->blocks[i] = 0;
                if (is_chunk_free(temp))
                {
                    delete_chunk(chunk, temp);
                    munmap(temp, BLOCKS_MAX * chunk_size + sizeof(t_chunk)); 
                }
                return (1);
            }
            i++;
        }
        temp = temp->next;
    }
    return (0);
}

int     free_alloc_large(t_alloc **alloc, void *ptr)
{
    t_alloc *temp;

    temp = *alloc;
    while (temp)
    {
        if ((void*)temp + sizeof(t_alloc) == ptr)
        {
            delete_alloc(alloc, temp);
            munmap(temp, sizeof(t_alloc) + temp->size);
            return (1);
        }
        temp = temp->next;
    }
    return (0);
}

void	free(void *ptr)
{   
    printf("call free: %p\n", ptr);
    if (free_alloc_small(&smalloc.tiny, TINY_MAX, ptr)){
        return ;
    }
    if (free_alloc_small(&smalloc.small, SMALL_MAX, ptr)){
       return ;
    }
    if (free_alloc_large(&smalloc.large, ptr)){
       return ;
    }
}
