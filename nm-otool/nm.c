/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:09:51 by amathias          #+#    #+#             */
/*   Updated: 2017/03/11 15:25:17 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	print_output(uint32_t nsyms, uint32_t symoff, uint32_t stroff,
			void *ptr)
{
	uint32_t		i;
	char			*str;
	struct nlist_64	*nlist;


	nlist = (void*)ptr + symoff;
	str = (void*)ptr + stroff;
	i = 0;
	printf("nsyms: %d\n", nsyms);
	while (i < nsyms)
	{
		printf("%s\n", str + nlist[i].n_un.n_strx);
		i++;
	}
}

void	handle_64(char *ptr)
{
	struct mach_header_64 	*header;
	uint32_t				ncmds;
	struct load_command		*lc;
	uint32_t				i;
	struct symtab_command	*symcmd;

	header = (struct mach_header_64 *)ptr;	
	ncmds = header->ncmds;
	lc = (void *)ptr + sizeof(struct mach_header_64);
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			symcmd = (struct symtab_command *)lc;
			print_output(symcmd->nsyms, symcmd->symoff, symcmd->stroff, ptr);
		//	printf("nb symboles %d\n", symcmd->nsyms);
			break ;	
		}
		lc = (void *) lc + lc->cmdsize;
		i++;
	}
	
}

void	nm(char *ptr)
{
	uint32_t magic_number;

	magic_number = *(uint32_t*)ptr;
	if (magic_number == MH_MAGIC_64)
		handle_64(ptr);
}

int main(int argc, char **argv)
{
	int				fd;
	char			*ptr;
	struct	stat	buf;

	if (argc != 2)
		return (EXIT_FAILURE);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (EXIT_FAILURE);
	if (fstat(fd, &buf) < 0)
		return (EXIT_FAILURE);
	if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
			== MAP_FAILED)
		return (EXIT_FAILURE);
	nm(ptr);
	if (munmap(ptr, buf.st_size) < 0)
		return (EXIT_FAILURE);	
	return (EXIT_SUCCESS);
}
