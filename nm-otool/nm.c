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

struct symtab_command	*get_symtab_command(struct load_command *lc,
							uint32_t ncmds, int endian)
{
	uint32_t	i;

	i = 0;
	while (i < ncmds)
	{
		if ((endian ? swap_byte32_t(lc->cmd) : lc->cmd) == LC_SYMTAB)
			return ((struct symtab_command*)lc);
		sanity_check(lc, (endian ? swap_byte32_t(lc->cmdsize) : lc->cmdsize));
		lc = (void*)lc + (endian ? swap_byte32_t(lc->cmdsize) : lc->cmdsize);
		i++;
	}
	return (NULL);
}

void					handle_64(char *ptr, int endian)
{
	struct mach_header_64	*header;
	uint32_t				ncmds;
	struct load_command		*lc;
	struct symtab_command	*symcmd;
	t_nm64					snm;

	header = (struct mach_header_64 *)ptr;
	ncmds = endian ? swap_byte32_t(header->ncmds) : header->ncmds;
	lc = (void*)ptr + sizeof(struct mach_header_64);
	snm.sec = get_section64(lc, ncmds, endian);
	snm.dylib = get_dylib(lc, ncmds, endian);
	symcmd = get_symtab_command(lc, ncmds, endian);
	if (symcmd != NULL)
		print_output_64(symcmd, ptr, &snm, endian);
	free(snm.sec);
	free(snm.dylib);
}

void					handle_32(char *ptr, int endian)
{
	struct mach_header		*header;
	uint32_t				ncmds;
	struct load_command		*lc;
	struct symtab_command	*symcmd;
	t_nm32					snm;

	header = (struct mach_header*)ptr;
	ncmds = endian ? swap_byte32_t(header->ncmds) : header->ncmds;
	lc = (void*)ptr + sizeof(struct mach_header);
	snm.sec = get_section32(lc, ncmds, endian);
	snm.dylib = get_dylib(lc, ncmds, endian);
	symcmd = get_symtab_command(lc, ncmds, endian);
	if (symcmd != NULL)
		print_output_32(symcmd, ptr, &snm, endian);
	free(snm.sec);
	free(snm.dylib);
}

void					nm(char *filename, char *ptr, int should_print)
{
	uint32_t magic_number;

	sanity_check(ptr, sizeof(uint32_t));
	magic_number = *(uint32_t*)ptr;
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
	{
		if (should_print)
			print_filename(filename);
		magic_number == MH_MAGIC_64 ? handle_64(ptr, 0) : handle_64(ptr, 1);
	}
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
	{
		if (should_print)
			print_filename(filename);
		magic_number == MH_MAGIC ? handle_32(ptr, 0) : handle_32(ptr, 1);
	}
	else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		fat(filename, ptr);
	else
		archive(filename, ptr);
}

int						main(int argc, char **argv)
{
	int				fd;
	char			*ptr;
	struct stat		buf;
	int				i;

	i = 1;
	if (argc < 2)
		return (EXIT_FAILURE);
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
		close(fd);
		if (munmap(ptr, buf.st_size) < 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
