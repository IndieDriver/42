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
	if (ft_strlen(str_table + nlist64->n_un.n_strx) == 0)
		return ;
	if (n_stab)
		return ;
	if (n_type == N_UNDF)
		ft_putstr("                 U ");
	else
	{
		ft_put_addr_64((size_t)nlist64->n_value);
		if (nlist64->n_sect == 4 || nlist64->n_sect == 5 ||
				nlist64->n_sect == 11 || nlist64->n_sect == 13 ||
				nlist64->n_sect == 14)
			n_ext ? ft_putstr(" S ") : ft_putstr(" s ");
		else if (nlist64->n_sect == 7 || nlist64->n_sect == 12)
			n_ext ? ft_putstr(" D ") : ft_putstr(" d ");
		else if (nlist64->n_sect == 8 || nlist64->n_sect == 15)
			ft_putstr(" b ");
		else if (nlist64->n_sect == 12)
			ft_putstr(" S ");
		else if (nlist64->n_sect == 17)
			ft_putstr(" S ");
		else if (n_type == N_ABS)
			ft_putstr(" A ");
		else {
			n_ext ? ft_putstr(" T ") : ft_putstr(" t ");
		}
	}
	ft_putstr("");
	ft_putstr(str_table + nlist64->n_un.n_strx);
	ft_putstr("\n");
}

void	dump_nlist_32(void *str_table, struct nlist *nlist, int endian)
{
	unsigned char n_stab;
	unsigned char n_pext;
	unsigned char n_type;
	unsigned char n_ext;


	n_stab = nlist->n_type & N_STAB;
	n_pext = nlist->n_type & N_PEXT;
	n_type = nlist->n_type & N_TYPE;
	n_ext = nlist->n_type & N_EXT;
	/*
	printf("nlist64!!!!!!!!!!!!\nn_un: %d\nn_type: %d\nn_sect: %d\nn_desc: %d\nn_value: %lld\n", nlist64->n_un.n_strx, nlist64->n_type, nlist64->n_sect, nlist64->n_desc, nlist64->n_value); */
	if (ft_strlen(str_table +
		(endian ? swap_byte32_t(nlist->n_un.n_strx) :
			nlist->n_un.n_strx)) == 0)
		return ;
	if (n_type == N_UNDF)
		ft_putstr("         U ");
	/*else if (n_type == N_PBUD)
		return ; */
	/*
	else if (n_type == N_SECT)
	{

		ft_put_addr_32((size_t)(endian ?
					swap_byte32_t(nlist->n_value) : nlist->n_value));
		if (swap_byte32_t(nlist->n_sect) == 4
				|| swap_byte32_t(nlist->n_sect) == 5)
			n_ext ? ft_putstr(" S ") : ft_putstr(" s ");
	} */
	else
	{
		ft_put_addr_32((size_t)(endian ?
					swap_byte32_t(nlist->n_value) : nlist->n_value));

		if ((nlist->n_sect) == 4 || (nlist->n_sect) == 5)
			n_ext || n_pext ? ft_putstr(" S ") : ft_putstr(" s ");
		else if ((nlist->n_sect) == 7 || (nlist->n_sect) == 12
				|| nlist->n_sect == 13)
			n_ext || n_pext ? ft_putstr(" D ") : ft_putstr(" d ");
		else if ((nlist->n_sect) == 8)
			ft_putstr(" b ");
		else if ((nlist->n_sect) == 12)
			ft_putstr(" S ");
		else if ((nlist->n_sect) == 17)
			ft_putstr(" S ");
		else if ((n_type) == N_ABS)
			ft_putstr(" A ");
		else {
			n_ext ? ft_putstr(" T ") : ft_putstr(" t ");
		}
	}
	ft_putstr(str_table +
			(endian ? swap_byte32_t(nlist->n_un.n_strx) : nlist->n_un.n_strx));
	ft_putstr("\n");
}
void	parse_nlist_64(t_symbol *head, void *str_table)
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

void	parse_nlist_32(t_symbol *head, void *str_table, int endian)
{
	t_symbol *temp;

	temp = head;
	while (temp)
	{
		struct nlist *nlist;
		nlist = temp->symbol;
		//printf("%s\n", str_table + nlist->n_un.n_strx);
		dump_nlist_32(str_table, (struct nlist*)temp->symbol, endian);
		temp = temp->next;
	}
}

t_symbol	*print_output_64(uint32_t nsyms, uint32_t symoff, uint32_t stroff, void *ptr)
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
		i++;
	}
	//parse_nlist_64(head, string_table);
	return (head);
}

void	print_output_32(struct symtab_command *symcmd, void *ptr, int endian)
{
	uint32_t		i;
	void			*string_table;
	struct nlist	*symlist;
	t_symbol		*head;

	head = NULL;
	symlist = (void*)ptr +
		(endian ? swap_byte32_t(symcmd->symoff) : symcmd->symoff);
	string_table = (void*)ptr +
		(endian ? swap_byte32_t(symcmd->stroff) : symcmd->stroff);
	i = 0;
	while (i < (endian ? swap_byte32_t(symcmd->nsyms) : symcmd->nsyms))
	{
		ft_lst_sorted_insert(&head,
			ft_new_symbol(string_table +
				(endian ? swap_byte32_t(symlist[i].n_un.n_strx) :
					 symlist[i].n_un.n_strx), &symlist[i]));
		i++;
	}
	parse_nlist_32(head, string_table, endian);
}

void	handle_64(char *ptr)
{
	struct mach_header_64 	*header;
	uint32_t				ncmds;
	struct load_command		*lc;
	uint32_t				i;
	struct symtab_command	*symcmd;
	t_symbol		*head;
	struct segment_command_64 *seg_cmd;
	//t_symbol		*segment;

	header = (struct mach_header_64 *)ptr;
	ncmds = header->ncmds;
	lc = (void*)ptr + sizeof(struct mach_header_64);
	i = 0;
	printf("ncmds: %d\n", ncmds);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			printf("LC_SYMTAB\n");
			symcmd = (struct symtab_command*)lc;
			head = print_output_64(symcmd->nsyms, symcmd->symoff, symcmd->stroff, ptr);
			//break ;
		}
		else if (lc->cmd == LC_SEGMENT_64)
		{
			printf("LC_SEGMENT\n");
			seg_cmd = (struct segment_command_64*)lc;
			printf("segname: %s\n", seg_cmd->segname);
			/*ft_lst_sorted_insert(&head,
				ft_new_symbol(string_table + symlist[i].n_un.n_strx,
					&symlist[i])); */

			//head = print_output_64(symcmd->nsyms, symcmd->symoff, symcmd->stroff, ptr);
			//break ;
		}
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
	void *string_table = (void*)ptr + symcmd->stroff;
	parse_nlist_64(head, string_table);

}

void	handle_32(char *ptr, int endian)
{
	struct mach_header		*header;
	uint32_t				ncmds;
	struct load_command		*lc;
	uint32_t				i;
	struct symtab_command	*symcmd;

	header = (struct mach_header*)ptr;
	ncmds = endian ? swap_byte32_t(header->ncmds) : header->ncmds;
	lc = (void*)ptr + sizeof(struct mach_header);
	i = 0;
	while (i < ncmds)
	{
		if ((endian ? swap_byte32_t(lc->cmd) : lc->cmd) == LC_SYMTAB)
		{
			symcmd = (struct symtab_command*)lc;
			print_output_32(symcmd, ptr, endian);
			break ;
		}
		lc = (void*)lc + (endian ? swap_byte32_t(lc->cmdsize) : lc->cmdsize);
		i++;
	}
}

void	nm(char *filename, char *ptr)
{
	uint32_t magic_number;

	magic_number = *(uint32_t*)ptr;
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		handle_64(ptr);
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
		magic_number == MH_MAGIC ? handle_32(ptr, 0) : handle_32(ptr, 1);
	else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		fat(filename, ptr);
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
