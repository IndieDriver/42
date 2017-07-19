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

void	parse_nlist_64(t_symbol *head, void *str_table, t_section64 *sections,
		int endian)
{
	t_symbol *temp;

	temp = head;
	while (temp)
	{
		struct nlist_64 *nlist;
		nlist = temp->symbol;
		dump_nlist_64(str_table, (struct nlist_64*)temp->symbol, sections, endian);
		temp = temp->next;
	}
}

void	parse_nlist_32(t_symbol *head, void *str_table, t_section32 *sections,
		int endian)
{
	t_symbol *temp;

	temp = head;
	while (temp)
	{
		struct nlist *nlist;
		nlist = temp->symbol;
		dump_nlist_32(str_table, (struct nlist*)temp->symbol, sections, endian);
		temp = temp->next;
	}
}

t_symbol	*print_output_64(struct symtab_command *symcmd, void *ptr, int en)
{
	uint32_t		i;
	void			*string_table;
	struct nlist_64	*nlist;
	t_symbol		*head;

	head = NULL;
	sanity_check(ptr, (en ? swap_byte32_t(symcmd->symoff) : symcmd->symoff));
	nlist = (void*)ptr + (en ? swap_byte32_t(symcmd->symoff) : symcmd->symoff);
	sanity_check(ptr, (en ? swap_byte32_t(symcmd->stroff) : symcmd->stroff));
	string_table = (void*)ptr +
		(en ? swap_byte32_t(symcmd->stroff) : symcmd->stroff);
	i = 0;
	while (i < (en ? swap_byte32_t(symcmd->nsyms) : symcmd->nsyms))
	{
		sanity_check(string_table, (en ? swap_byte32_t(nlist[i].n_un.n_strx) :
					 nlist[i].n_un.n_strx));
		ft_lst_sorted_insert(&head,
			ft_new_symbol(string_table +
				(en ? swap_byte32_t(nlist[i].n_un.n_strx) :
					 nlist[i].n_un.n_strx), &nlist[i]));
		i++;
	}
	//parse_nlist_64(head, string_table);
	return (head);
}

void	print_output_32(struct symtab_command *symcmd, void *ptr,
			t_section32 *sections, int en)
{
	uint32_t		i;
	void			*string_table;
	struct nlist	*nlist;
	t_symbol		*head;

	head = NULL;
	sanity_check(ptr, (en ? swap_byte32_t(symcmd->symoff) : symcmd->symoff));
	nlist = (void*)ptr +
		(en ? swap_byte32_t(symcmd->symoff) : symcmd->symoff);
	sanity_check(ptr, (en ? swap_byte32_t(symcmd->stroff) : symcmd->stroff));
	string_table = (void*)ptr +
		(en ? swap_byte32_t(symcmd->stroff) : symcmd->stroff);
	i = 0;
	while (i < (en ? swap_byte32_t(symcmd->nsyms) : symcmd->nsyms))
	{
		ft_lst_sorted_insert(&head,
			ft_new_symbol(string_table +
				(en ? swap_byte32_t(nlist[i].n_un.n_strx) :
					 nlist[i].n_un.n_strx), &nlist[i]));
		i++;
	}
	parse_nlist_32(head, string_table, sections, en);
	ft_lstdelsymbol(&head);
}

t_section64	*get_section64(struct load_command *lc, uint32_t ncmds, int endian)
{
	uint32_t					i;
	uint32_t					j;
	uint32_t					k;
	struct segment_command_64	*seg_cmd;
	t_section64					*section = NULL;

	i = 0;
	k = 1;
	section = malloc(sizeof(t_section64*) * 256);
	ft_bzero(section, sizeof(t_section64*) * 256);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			seg_cmd = (struct segment_command_64*)lc;
			j = 0;
			while (j < seg_cmd->nsects)
			{
				section[k + j].sec = (struct section_64*)(((void*)seg_cmd +
sizeof(struct segment_command_64)) + (sizeof(struct section_64) * j));
				j++;
			}
			k += seg_cmd->nsects;
		}
		sanity_check(lc, (endian ? swap_byte32_t(lc->cmdsize) : lc->cmdsize));
		lc = (void*)lc + (endian ? swap_byte32_t(lc->cmdsize) : lc->cmdsize);
		i++;
	}
	return (section);
}

t_section32	*get_section32(struct load_command *lc, uint32_t ncmds, int endian)
{
	uint32_t					i;
	uint32_t					j;
	uint32_t					k;
	struct segment_command		*seg_cmd;
	t_section32					*section;

	i = 0;
	k = 1;
	section = malloc(sizeof(t_section32*) * 256);
	ft_bzero(section, sizeof(t_section32*) * 256);
	while (i < ncmds)
	{
		if ((endian ? swap_byte32_t(lc->cmd) : lc->cmd) == LC_SEGMENT)
		{
			seg_cmd = (struct segment_command*)lc;
			j = 0;
			while (j < (endian ?
					swap_byte32_t(seg_cmd->nsects) : seg_cmd->nsects))
			{
				section[k + j].sec = (struct section*)(((void*)seg_cmd +
sizeof(struct segment_command)) + (sizeof(struct section) * j));
				j++;
			}
			k += (endian ? swap_byte32_t(seg_cmd->nsects) : seg_cmd->nsects);
		}
		sanity_check(lc, (endian ? swap_byte32_t(lc->cmdsize) : lc->cmdsize));
		lc = (void*)lc + (endian ? swap_byte32_t(lc->cmdsize) : lc->cmdsize);
		i++;
	}
	return (section);
}

void	handle_64(char *ptr, int endian)
{
	struct mach_header_64 	*header;
	uint32_t				ncmds;
	struct load_command		*lc;
	uint32_t				i;
	struct symtab_command	*symcmd;
	t_symbol		*head;

	header = (struct mach_header_64 *)ptr;
	ncmds = endian ? swap_byte32_t(header->ncmds) : header->ncmds;
	lc = (void*)ptr + sizeof(struct mach_header_64);
	i = 0;
	t_section64 *section = get_section64(lc, ncmds, endian);
	symcmd = NULL;
	while (i < ncmds)
	{
		if ((endian ? swap_byte32_t(lc->cmd) : lc->cmd) == LC_SYMTAB)
		{
			symcmd = (struct symtab_command*)lc;
			head = print_output_64(symcmd, ptr, endian);
			//break ;
		}
		sanity_check(lc, (endian ? swap_byte32_t(lc->cmdsize) : lc->cmdsize));
		lc = (void*)lc + (endian ? swap_byte32_t(lc->cmdsize) : lc->cmdsize);
		i++;
	}
	if (symcmd != NULL) {
		void *string_table = (void*)ptr + symcmd->stroff;
		parse_nlist_64(head, string_table, section, endian);
	}
	ft_lstdelsymbol(&head);
	free(section);
}

void	handle_32(char *ptr, int endian)
{
	struct mach_header		*header;
	uint32_t				ncmds;
	struct load_command		*lc;
	uint32_t				i;
	struct symtab_command	*symcmd;
	t_section32				*sections;

	header = (struct mach_header*)ptr;
	ncmds = endian ? swap_byte32_t(header->ncmds) : header->ncmds;
	lc = (void*)ptr + sizeof(struct mach_header);
	sections = get_section32(lc, ncmds, endian);
	i = 0;
	while (i < ncmds)
	{
		if ((endian ? swap_byte32_t(lc->cmd) : lc->cmd) == LC_SYMTAB)
		{
			symcmd = (struct symtab_command*)lc;
			print_output_32(symcmd, ptr, sections, endian);
			break ;
		}
		lc = (void*)lc + (endian ? swap_byte32_t(lc->cmdsize) : lc->cmdsize);
		i++;
	}
	free(sections);
}

void	nm(char *filename, char *ptr, int should_print)
{
	uint32_t magic_number;

	magic_number = *(uint32_t*)ptr;
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
	{
		if (should_print)
		{
			ft_putstr("\n");
			ft_putstr(filename);
			ft_putstr(":\n");
		}
		magic_number == MH_MAGIC_64 ? handle_64(ptr, 0) : handle_64(ptr, 1);
	}
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
	{
		if (should_print)
		{
			ft_putstr("\n");
			ft_putstr(filename);
			ft_putstr(":\n");
		}
		magic_number == MH_MAGIC ? handle_32(ptr, 0) : handle_32(ptr, 1);
	}
	else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		fat(filename, ptr);
	else
		archive(filename, ptr);
}

int		main(int argc, char **argv)
{
	int				fd;
	char			*ptr;
	struct	stat	buf;
	int				i;

	i = 1;
	if (argc < 2)
		return (EXIT_FAILURE);
	/*
	if (argc != 2)
		ft_putstr("\n"); */
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) < 0)
			return (EXIT_FAILURE);
		if (fstat(fd, &buf) < 0)
			return (EXIT_FAILURE);
		if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
				== MAP_FAILED)
			return (EXIT_FAILURE);
		g_filelimit = ptr + buf.st_size;
		nm(argv[i], ptr, argc != 2);
		if (munmap(ptr, buf.st_size) < 0)
			return (EXIT_FAILURE);
		i++;
		/*
		if (i != argc)
			ft_putstr("\n"); */
	}
	return (EXIT_SUCCESS);
}
