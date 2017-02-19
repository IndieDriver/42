#include "malloc.h"

/*
TINY: 1 at 512 bytes (65536 bytes)
SMALL: 513 at 4096 bytes (409600 bytes)
 */
void init_malloc()
{
    t_chunk tiny;
    t_chunk small;
    size_t tiny_size;
    size_t small_size;
    ft_putstr("init_malloc\n");
    tiny_size = BLOCKS_MAX * TINY_MAX;
    small_size = BLOCKS_MAX * SMALL_MAX;
    tiny.start = mmap(NULL, tiny_size, PROT_WRITE | PROT_EXEC | PROT_READ,
            MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    printf("tiny.start: %p\n", tiny.start);
    small.start = mmap(NULL, small_size, PROT_WRITE | PROT_EXEC | PROT_READ,
            MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    printf("small.start: %p\n", small.start);
    ft_memset(&tiny.blocks, 0, sizeof(size_t) * BLOCKS_MAX);
    ft_memset(&small.blocks, 0, sizeof(size_t) * BLOCKS_MAX);
    int i = 0;
    while (i < BLOCKS_MAX){
        printf("%ld|", tiny.blocks[i]);
        i++;
    }
    smalloc.tiny = &tiny;
    smalloc.small = &small;

}

void    *malloc_small(t_chunk *chunk, size_t chunk_size, size_t malloc_size){
    int i;

    i = 0;
    while (i < BLOCKS_MAX)
    {
        if (chunk->blocks[i] == 0)
        { 
            chunk->blocks[i] = malloc_size; 
            return (chunk->start + (i * chunk_size)); 
        }
        i++;
    }
    return (NULL);
}

void    *malloc(size_t size)
{
    if (smalloc.tiny == NULL)
        init_malloc();
    if (size <= 0)
        return (NULL);
    else if (size < TINY_MAX)
        return (malloc_small(smalloc.tiny, TINY_MAX, size));
    else if (size < SMALL_MAX)
        return (malloc_small(smalloc.small, SMALL_MAX, size));
    else
    {
        void *ptr = mmap(NULL, size,PROT_WRITE | PROT_EXEC | PROT_READ,
                MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        return (ptr);
    }
    return (NULL);
}
