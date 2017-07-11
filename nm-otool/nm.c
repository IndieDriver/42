/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:09:51 by amathias          #+#    #+#             */
/*   Updated: 2017/04/02 15:29:28 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

void	dump_nlist_64(void *str_table, struct nlist_64 *nlist64)
{
	unsigned char n_stab;
	unsigned char n_pext;
	unsigned char n_type;
	unsigned char n_ext;

	n_stab = nlist64->n_type & N_STAB;
	n_pext = nlist64->n_type & N_PEXT;
	n_type = nlist64->n_type & N_TYPE;
	n_ext = nlist64->n_type & N_EXT;
	/*
	printf("nlist64!!!!!!!!!!!!\nn_un: %d\nn_type: %d\nn_sect: %d\nn_desc: %d\nn_value: %lld\n", nlist64->n_un.n_strx, nlist64->n_type, nlist64->n_sect, nlist64->n_desc, nlist64->n_value); */
	if (n_stab)
		return ;
	if (n_type == N_UNDF)
		ft_putstr("                 U");
	else if (n_type == N_PBUD || n_type == N_ABS )
		return ;
	else
	{
		if (nlist64->n_sect == NO_SECT || nlist64->n_sect == 3)
			return ;
		//printf("section: %d\n", nlist64->n_sect);
		/*
		if (nlist64->n_sect == 3)
			return ; */
		if (ft_strlen(str_table + nlist64->n_un.n_strx) == 0)
			return ;
		ft_put_addr((size_t)nlist64->n_value);
		if (n_ext)
			ft_putstr(" T");
		else
			ft_putstr(" t");
	}
	ft_putstr("");
	ft_putstr(str_table + nlist64->n_un.n_strx);
	ft_putstr("\n");
}

void	parse_nlist(t_symbol *head, void *str_table)
{
	t_symbol *temp;

	temp = head;
	while (temp)
	{
		struct nlist_64 *nlist;
		nlist = temp->symbol;
		//printf("%s\n", str_table + nlist->n_un.n_strx);
		dump_nlist_64(str_table, (struct nlist_64*)temp->symbol);
		temp = temp->next;
	}
}

void	print_output(uint32_t nsyms, uint32_t symoff, uint32_t stroff,
			void *ptr)
{
	uint32_t		i;
	void			*string_table;
	struct nlist_64	*symlist;
	t_symbol		*head;

	head = NULL;
	symlist = (void*)ptr + symoff;
	string_table = (void*)ptr + stroff;
	i = 0;
	while (i < nsyms)
	{
		ft_lst_sorted_insert(&head,
				ft_new_symbol(string_table + symlist[i].n_un.n_strx,
					&symlist[i]));
		//printf("%s\n", string_table + symlist[i].n_un.n_strx);
		//dump_nlist_64(string_table, &symlist[i]);
		//TODO: Sort nlist by alpha
		i++;
	}

	parse_nlist(head, string_table);
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

void	nm(char *filename, char *ptr)
{
	uint32_t magic_number;

	magic_number = *(uint32_t*)ptr;
	if (magic_number == MH_MAGIC_64)
		handle_64(ptr);
	else
		archive(filename, ptr);
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
	nm(argv[1], ptr);
	if (munmap(ptr, buf.st_size) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
