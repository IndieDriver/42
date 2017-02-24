#include "malloc.h"

void    *copy_chunk(void *ptr, size_t old_size, size_t new_size)
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
            if ((void*)temp + sizeof(t_chunk) + (i * chunk_size) == ptr)
            {
                if (new_size < chunk_size){
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

void    *copy_alloc(void *ptr, size_t old_size, size_t new_size)
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

void    *realloc_large(t_alloc **alloc, void *ptr, size_t new_size)
{
    t_alloc *temp;
    size_t  old_size;

    temp = *alloc;
    while (temp)
    {
        if ((void*)temp + sizeof(t_alloc) == ptr)
        {
            old_size = temp->size;
            if (new_size < old_size){
                munmap(ptr + new_size, old_size); 
                temp->size = new_size;
                return (ptr);
            }
            return ((void*)copy_alloc(ptr, old_size, new_size)); 
        }
        temp = temp->next;
    }
    return (0);
}

void	*realloc(void *ptr, size_t size)
{
    printf("call realloc: %p (size: %ld)\n", ptr, size);
    void *new_ptr;

    if ((new_ptr = realloc_small(&smalloc.tiny, TINY_MAX, ptr, size)) != NULL)
        return (new_ptr);
    if ((new_ptr = realloc_small(&smalloc.small, SMALL_MAX, ptr, size)) != NULL)
        return (new_ptr);
    if ((new_ptr = realloc_large(&smalloc.large, ptr, size)) != NULL)
        return (new_ptr);
	return (NULL);	
}
