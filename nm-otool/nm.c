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

void	dump_nlist_64(void *str_table, struct nlist_64 *nlist64,
			t_section64 *sec, int endian)
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
	(void) endian;
	(void)sec;
	if (ft_strlen(str_table + nlist64->n_un.n_strx) == 0)
		return ;
	if (n_stab)
		return ;
	if (n_type == N_UNDF)
		ft_putstr("                 U ");
	else
	{
		ft_put_addr_64((size_t)nlist64->n_value);
		if (n_type == N_ABS)
			ft_putstr(" A ");
		else if (ft_strcmp(sec[nlist64->n_sect].sec->segname, "__DATA") == 0)
		{
			if (ft_strcmp(sec[nlist64->n_sect].sec->sectname, "__data") == 0)
				n_ext ? ft_putstr(" D ") : ft_putstr(" d ");
			else if (ft_strcmp(sec[nlist64->n_sect].sec->sectname, "__bss") == 0)
				n_ext ? ft_putstr(" B ") : ft_putstr(" b ");
			else
				n_ext ? ft_putstr(" S ") : ft_putstr(" s ");
		}
		else if (ft_strcmp(sec[nlist64->n_sect].sec->segname, "__TEXT") == 0)
		{
			if (ft_strcmp(sec[nlist64->n_sect].sec->sectname, "__text") == 0)
				n_ext ? ft_putstr(" T ") : ft_putstr(" t ");
			else
				n_ext ? ft_putstr(" S ") : ft_putstr(" s ");
		}
		else
			n_ext ? ft_putstr(" S ") : ft_putstr(" s ");
	}
	ft_putstr("");
	ft_putstr(str_table + nlist64->n_un.n_strx);
	ft_putstr("\n");
}

void	dump_nlist_32(void *str_table, struct nlist *nlist,
			t_section32 *sec, int endian)
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
	if (n_stab)
		return ;
	if (n_type == N_UNDF)
		ft_putstr("         U ");
	else
	{
		ft_put_addr_32((size_t)(endian ?
					swap_byte32_t(nlist->n_value) : nlist->n_value));

		if (n_type == N_ABS)
			ft_putstr(" A ");
		else if (ft_strcmp(sec[nlist->n_sect].sec->segname, "__DATA") == 0)
		{
			if (ft_strcmp(sec[nlist->n_sect].sec->sectname, "__data") == 0)
				n_ext ? ft_putstr(" D ") : ft_putstr(" d ");
			else if (ft_strcmp(sec[nlist->n_sect].sec->sectname, "__bss") == 0)
				n_ext ? ft_putstr(" B ") : ft_putstr(" b ");
			else
				n_ext ? ft_putstr(" S ") : ft_putstr(" s ");
		}
		else if (ft_strcmp(sec[nlist->n_sect].sec->segname, "__TEXT") == 0)
		{
			if (ft_strcmp(sec[nlist->n_sect].sec->sectname, "__text") == 0)
				n_ext ? ft_putstr(" T ") : ft_putstr(" t ");
			else
				n_ext ? ft_putstr(" S ") : ft_putstr(" s ");
		}
		else
			n_ext ? ft_putstr(" S ") : ft_putstr(" s ");
	}
	ft_putstr(str_table +
			(endian ? swap_byte32_t(nlist->n_un.n_strx) : nlist->n_un.n_strx));
	ft_putstr("\n");
}
void	parse_nlist_64(t_symbol *head, void *str_table, t_section64 *sections,
		int endian)
{
	t_symbol *temp;

	temp = head;
	while (temp)
	{
		struct nlist_64 *nlist;
		nlist = temp->symbol;
		//printf("%s\n", str_table + nlist->n_un.n_strx);
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
		//printf("%s\n", str_table + nlist->n_un.n_strx);
		dump_nlist_32(str_table, (struct nlist*)temp->symbol, sections, endian);
		temp = temp->next;
	}
}

t_symbol	*print_output_64(struct symtab_command *symcmd, void *ptr, int endian)
{
	uint32_t		i;
	void			*string_table;
	struct nlist_64	*symlist;
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
	//parse_nlist_64(head, string_table);
	return (head);
}

void	print_output_32(struct symtab_command *symcmd, void *ptr,
			t_section32 *sections, int endian)
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
	parse_nlist_32(head, string_table, sections, endian);
}

t_section64	*get_section64(struct load_command *lc, uint32_t ncmds)
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
			//printf("%s\n", seg_cmd->segname);
			j = 0;
			while (j < seg_cmd->nsects)
			{
				section[k + j].sec = (struct section_64*)
					(((void*)seg_cmd + sizeof(struct segment_command_64))
					 + (sizeof(struct section_64) * j));
			/*	printf("%d : %s|%s\n", k + j, section[k + j].section->sectname,
						section[k + j].section->segname); */
				j++;
			}
			k += seg_cmd->nsects;
		}
		lc = (void*)lc + lc->cmdsize;
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
			//printf("%s\n", seg_cmd->segname);
			j = 0;
			while (j < (endian ?
					swap_byte32_t(seg_cmd->nsects) : seg_cmd->nsects))
			{
				section[k + j].sec = (struct section*)
					(((void*)seg_cmd + sizeof(struct segment_command))
					 + (sizeof(struct section) * j));
		/*		printf("%d : %s|%s\n", k + j, section[k + j].sec->sectname,
						section[k + j].sec->segname); */
				j++;
			}
			k += (endian ? swap_byte32_t(seg_cmd->nsects) : seg_cmd->nsects);
		}
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
	t_section64 *section = get_section64(lc, ncmds);
	while (i < ncmds)
	{
		if ((endian ? swap_byte32_t(lc->cmd) : lc->cmd) == LC_SYMTAB)
		{
			symcmd = (struct symtab_command*)lc;
			head = print_output_64(symcmd, ptr, endian);
			//break ;
		}
		lc = (void*)lc + (endian ? swap_byte32_t(lc->cmdsize) : lc->cmdsize);
		i++;
	}
	void *string_table = (void*)ptr + symcmd->stroff;
	parse_nlist_64(head, string_table, section, endian);

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
}

void	nm(char *filename, char *ptr)
{
	uint32_t magic_number;

	magic_number = *(uint32_t*)ptr;
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		magic_number == MH_MAGIC_64 ? handle_64(ptr, 0) : handle_64(ptr, 1);
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
