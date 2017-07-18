/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:09:51 by amathias          #+#    #+#             */
/*   Updated: 2017/04/02 15:29:28 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

void	handle_64(char *ptr, int endian)
{
	struct mach_header_64 	*header;
	uint32_t				ncmds;
	struct load_command		*lc;

	ft_putstr("Contents of (__TEXT,__text) section\n");
	header = (struct mach_header_64 *)ptr;
	ncmds = endian ? swap_byte32_t(header->ncmds) : header->ncmds;
	lc = (void*)ptr + sizeof(struct mach_header_64);
	read_section64(ptr, lc, ncmds, endian);
}

void	handle_32(char *ptr, int endian)
{
	struct mach_header		*header;
	uint32_t				ncmds;
	struct load_command		*lc;

	ft_putstr("Contents of (__TEXT,__text) section\n");
	header = (struct mach_header*)ptr;
	ncmds = endian ? swap_byte32_t(header->ncmds) : header->ncmds;
	lc = (void*)ptr + sizeof(struct mach_header);
	read_section32(ptr, lc, ncmds, endian);
}

void	otool_nofilename(char *fn, char *ptr)
{
	uint32_t magic_number;

	magic_number = *(uint32_t*)ptr;
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		magic_number == MH_MAGIC_64 ? handle_64(ptr, 0) : handle_64(ptr, 1);
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
		magic_number == MH_MAGIC ? handle_32(ptr, 0) : handle_32(ptr, 1);
	else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		fat_otool(fn, ptr);
	else
		archive_otool(fn, ptr);
}

void 	otool(char *fn, char *ptr)
{
	uint32_t magic_number;

	magic_number = *(uint32_t*)ptr;
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
	{
		ft_putstr(fn);
		ft_putstr(":\n");
		magic_number == MH_MAGIC_64 ? handle_64(ptr, 0) : handle_64(ptr, 1);
	}
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
	{
		ft_putstr(fn);
		ft_putstr(":\n");
		magic_number == MH_MAGIC ? handle_32(ptr, 0) : handle_32(ptr, 1);
	}
	else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		fat_otool(fn, ptr);
	else
		archive_otool(fn, ptr);
}

int	main(int argc, char **argv)
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
	otool(argv[1], ptr);
	if (munmap(ptr, buf.st_size) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
