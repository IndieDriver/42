#include "malloc.h"

/*
TINY: 1 at 512 bytes (65536 bytes)
SMALL: 513 at 4096 bytes (409600 bytes)
 */
void init_malloc()
{
    /*
    t_chunk tiny;
    t_chunk small;
    size_t tiny_size;
    size_t small_size;
    ft_putstr("init_malloc\n");
    tiny_size = BLOCKS_MAX * TINY_MAX;
    small_size = BLOCKS_MAX * SMALL_MAX;
    printf("size_t sizeof: %ld\n", sizeof(size_t));
    printf("tiny_size: %ld|sizeof: %ld\n", tiny_size, sizeof(t_chunk));
    tiny.start = mmap(NULL, tiny_size, PROT_WRITE | PROT_EXEC | PROT_READ,
            MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    printf("tiny.start: %p\n", tiny.start);
    small.start = mmap(NULL, small_size, PROT_WRITE | PROT_EXEC | PROT_READ,
            MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    printf("small.start: %p\n", small.start);
    //ft_memset(&tiny.blocks, 0, sizeof(size_t) * BLOCKS_MAX);
    //ft_memset(&small.blocks, 0, sizeof(size_t) * BLOCKS_MAX);
    int i = 0;
    while (i < BLOCKS_MAX){
        tiny.blocks[i] = 0;
        small.blocks[i] = 0;
        //printf("%ld|", tiny.blocks[i]);
        i++;
    }
    smalloc.tiny = &tiny;
    smalloc.small = &small; */
}
void    *is_free_node(t_chunk *chunk, size_t chunk_size, size_t malloc_size)
{
    int i;

    i = 0;
    while (i < BLOCKS_MAX)
    {
        if (chunk->blocks[i] == 0)
        { 
            chunk->blocks[i] = malloc_size; 
            return (chunk->blocks + sizeof(t_chunk) + (i * chunk_size)); 
        }
        i++;
    }
    return (NULL);
}
void    add_chunk_node(t_chunk **begin, t_chunk *new)
{
    new->next = *begin;
    *begin = new;
}


void    *malloc_small(t_chunk **chunk, size_t chunk_size, size_t malloc_size)
{
    t_chunk *new_chunk;    
    void    *free_addr;
    
    free_addr = NULL;
    if (!*chunk)
    {
        *chunk = mmap(NULL, chunk_size * BLOCKS_MAX + sizeof(t_chunk),
                PROT_WRITE | PROT_EXEC | PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        ft_memset(*chunk, 0, chunk_size * BLOCKS_MAX + sizeof(t_chunk));
    }
    while ((free_addr = is_free_node(*chunk, chunk_size, malloc_size)) == NULL)
    {
        printf("chunk before: %p\n", *chunk);
        new_chunk = mmap(NULL, chunk_size * BLOCKS_MAX + sizeof(t_chunk),
                PROT_WRITE | PROT_EXEC | PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0); 
        ft_memset(new_chunk, 0, chunk_size * BLOCKS_MAX + sizeof(t_chunk));
        add_chunk_node(chunk, new_chunk);
    }
    return (free_addr);
}

void    *malloc_big(t_alloc **begin, size_t malloc_size)
{
    t_alloc node;

    node.ptr = mmap(NULL, malloc_size, PROT_WRITE | PROT_EXEC | PROT_READ,
                MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    node.next = *begin;
    *begin = &node;
    return (node.next);
}

void    *malloc(size_t size)
{
    printf("call malloc: %ld\n", size);
    void *ptr;
    if (smalloc.tiny == NULL)
    {
        init_malloc();
    }


    ptr = NULL;

    if (size <= 0)
        ptr = NULL;
    else if (size < TINY_MAX)
        ptr = malloc_small(&smalloc.tiny, TINY_MAX, size);
    else if (size < SMALL_MAX)
        ptr = malloc_small(&smalloc.small, SMALL_MAX, size);
    else
        ptr = malloc_big(&smalloc.large, size);
    //printf("returned ptr: %p\n", ptr);
    return (ptr);
}
