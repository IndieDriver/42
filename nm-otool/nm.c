/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:09:51 by amathias          #+#    #+#             */
/*   Updated: 2017/03/18 15:20:06 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

void	dump_nlist_64(void *str_table, struct nlist_64 nlist64)
{
	unsigned char n_stab;
	unsigned char n_pext;
	unsigned char n_type;
	unsigned char n_ext;


	n_stab = nlist64.n_type & N_STAB;
	n_pext = nlist64.n_type & N_PEXT;
	n_type = nlist64.n_type & N_TYPE;
	n_ext = nlist64.n_type & N_EXT;
	//printf("%u %u %u %u\n", n_stab, n_pext, n_type, n_ext);
	if (n_type == N_UNDF)
		printf("                 U");
	else
	{
		ft_put_addr((size_t)nlist64.n_value);
		printf(" T");
	}
	printf(" ");
	printf("%s\n", str_table + nlist64.n_un.n_strx);


	/*
	printf("nlist64!!!!!!!!!!!!\nn_un: %d\nn_type: %d\nn_sect: %d\nn_desc: %d\nn_value: %lld\n",
			nlist64.n_un.n_strx, nlist64.n_type, nlist64.n_sect,
			nlist64.n_desc, nlist64.n_value); */
}

void	print_output(uint32_t nsyms, uint32_t symoff, uint32_t stroff,
			void *ptr)
{
	uint32_t		i;
	void			*string_table;
	struct nlist_64	*nlist;

	nlist = (void*)ptr + symoff;
	string_table = (void*)ptr + stroff;
	i = 0;
	printf("nsyms: %d\n", nsyms);
	while (i < nsyms)
	{
		//printf("%s\n", string_table + nlist[i].n_un.n_strx);
		dump_nlist_64(string_table, nlist[i]);
		//TODO: Sort nlist by alpha
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
