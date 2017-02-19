#include "malloc.h"

void    print_memory_addr(void *ptr)
{
    size_t addr = (size_t) ptr; 
    ft_putstr("0x");
    ft_putstr(ft_sizet_to_hex(addr)); 
}

void    print_block(void *ptr, size_t size){
    printf("%p\n", ptr);
    print_memory_addr(ptr);
    ft_putstr(" - ");
    print_memory_addr(ptr + size);
    ft_putstr(" : ");
    ft_putstr(ft_itoa((int)size));
    ft_putstr(" octets\n");
}

void    show_alloc_small(t_chunk *chunk, size_t chunk_size, char *name)
{
    int i;

    i = 0;
    ft_putstr(name);
    printf("%p\n", (chunk->start));
    print_memory_addr(chunk->start);
    ft_putstr("\n");
    while (i < BLOCKS_MAX)
    {
        if (chunk->blocks[i] != 0)
        {
            printf("%ld|\n", chunk->blocks[i]);
            printf("%p\n", (chunk->start));
            print_block((void*)chunk->start + (i * chunk_size), chunk->blocks[i]);
            //printf("%p\n", chunk->start);
           //0xA0020 - 0xA004A : 42 octets 
        }
        i++;            
    }
}

void    show_alloc_mem()
{
    if (smalloc.tiny == NULL)
        return ;
    show_alloc_small(smalloc.tiny, TINY_MAX, "TINY : ");
    //show_alloc_small(smalloc.small, SMALL_MAX, "SMALL : ");
    
}
