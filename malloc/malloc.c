#include "malloc.h"

/*
TINY: 1 at 512 bytes (65536 bytes)
SMALL: 513 at 4096 bytes (409600 bytes)
*/
void init_malloc()
{
  size_t tiny_size;
  size_t small_size;

  tiny_size = 128 * 512;
  small_size = 100 * 4096;
  void *tiny = mmap(NULL, tiny_size, PROT_WRITE | PROT_EXEC | PROT_READ,
                MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  void *small = mmap(NULL, small_size, PROT_WRITE | PROT_EXEC | PROT_READ,
                MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  (void)tiny;
  (void)small;
}

void *malloc(size_t size)
{
    
    init_malloc();
    ft_putstr("call malloc\n");
    void *ptr = mmap(NULL, size,PROT_WRITE | PROT_EXEC | PROT_READ,
                MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (!ptr)
      ft_putstr("NULL\n");
    else
      ft_putstr("NOT NULL\n");
  return (ptr);
}
