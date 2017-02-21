#include "malloc.h"

static int      size_hex(size_t n)                                                                    
{                                                                                                     
    int i;                                                                                        

    i = 1;                                                                                        
    while (n > 16)                                                                                
    {                                                                                             
        i++;                                                                                  
        n = n / 16;                                                                           
    }                                                                                             
    return (i);                                                                                   
}                                                                                                     

void            ft_put_addr(size_t n)                                                               
{                                                                                                   
    char            buf[64];                                                                                 
    int             ntmp;                                                                       
    int             len;
    int             i;                                                                            

    len = size_hex(n);
    i = len - 1;
    buf[i] = '\0';                                                                       
    while (n != 0)                                                                                
    {                                                                                             
        ntmp = (n % 16);                                                                      
        buf[i] = (ntmp > 9) ? (ntmp - 10) + 'a' : ntmp + '0';                                       
        n = n / 16;                                                                           
        i--;
    }                                                                                             
    write(1, buf, len); 
}



/*
static void    print_memory_addr(void *ptr)                                                                  
{                                                                                                     
    size_t addr = (size_t) ptr;                                                                       
    ft_putstr("0x");                                                                                  
    ft_putstr(ft_sizet_to_hex(addr));                                                                    
}   */
