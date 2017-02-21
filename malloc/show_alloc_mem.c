#include "malloc.h"

void    print_memory_addr(void *ptr)
{
    size_t addr = (size_t) ptr; 
    ft_putstr("0x");
    ft_put_addr(addr);
}

void    print_block(void *ptr, size_t size){
    ft_putstr("\t");
    print_memory_addr(ptr);
    ft_putstr(" - ");
    print_memory_addr(ptr + size);
    ft_putstr(" : ");
    ft_putnbr((int)size);
    ft_putstr(" octets\n");
}

void    show_alloc_small(t_chunk *chunk, size_t chunk_size, char *name)
{
    int     i;

    i = 0;
    ft_putstr(name);
    print_memory_addr(chunk);
    ft_putstr("\n");
    while (chunk)
    {
        while (i < BLOCKS_MAX)
        {
            if (chunk->blocks[i] != 0)
            {
                print_block((void*)chunk + sizeof(t_chunk) + (i * chunk_size), chunk->blocks[i]);
                //0xA0020 - 0xA004A : 42 octets 
            }
            i++;            
        }
        chunk = chunk->next;
    }
}

void    show_alloc_mem()
{
    if (smalloc.tiny == NULL)
        return ;
    show_alloc_small(smalloc.tiny, TINY_MAX, "TINY : ");
    //show_alloc_small(smalloc.small, SMALL_MAX, "SMALL : ");

}
