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
    t_chunk *temp;
    int     i;

    temp = chunk;
    ft_putstr(name);
    print_memory_addr(chunk);
    ft_putstr("\n");
    while (temp)
    {
        i = 0;
        while (i < BLOCKS_MAX)
        {
            if (temp->blocks[i] != 0)
            {
                print_block((void*)temp + sizeof(t_chunk) + (i * chunk_size), temp->blocks[i]);
                //0xA0020 - 0xA004A : 42 octets 
            }
            i++;            
        }
        temp = temp->next;
    }
}

void    show_alloc_large(t_alloc *alloc, char *name){
    t_alloc *temp;
    
    temp = alloc;
    ft_putstr(name);
    print_memory_addr(alloc);
    ft_putstr("\n");
    while (temp)
    {
        print_block((void*)temp + sizeof(t_alloc), temp->size); 
        temp = temp->next;
    }
}

void    show_alloc_mem()
{
    if (smalloc.tiny != NULL)
        show_alloc_small(smalloc.tiny, TINY_MAX, "TINY : ");
    if (smalloc.small != NULL)
        show_alloc_small(smalloc.small, SMALL_MAX, "SMALL : ");
    if (smalloc.large != NULL)
        show_alloc_large(smalloc.large, "LARGE : ");
}
