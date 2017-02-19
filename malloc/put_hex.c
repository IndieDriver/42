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

char            *ft_sizet_to_hex(size_t n)                                                               
{                                                                                                   
    char    *tmp;                                                                                 
    int             ntmp;                                                                         
    int             i;                                                                            

    i = 0;                                                                                        
    if ((tmp = malloc(sizeof(char) * size_hex(n) + 1)) == NULL)                                   
        return (NULL);                                                                        
    if (n == 0)                                                                                   
        tmp[i++] = '0';                                                                       
    while (n != 0)                                                                                
    {                                                                                             
        ntmp = (n % 16);                                                                      
        tmp[i++] = (ntmp > 9) ? (ntmp - 10) + 'a' : ntmp + '0';                                       
        n = n / 16;                                                                           
    }                                                                                             
    tmp[i] = '\0';                                                                                
    return (ft_strrev(tmp));                                                                      
}                                                                                                     
/*
static void    print_memory_addr(void *ptr)                                                                  
{                                                                                                     
    size_t addr = (size_t) ptr;                                                                       
    ft_putstr("0x");                                                                                  
    ft_putstr(ft_sizet_to_hex(addr));                                                                    
}   */
