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

void		dump_data64(void *ptr, void *vm_start, uint64_t size)
{
	uint64_t i;
	unsigned char c;

	i = 0;
	while (i < size)
	{
		if (i % 16 == 0)
		{
			ft_put_addr_64((size_t)vm_start + i);
			ft_putstr("\t");
		}
		c = *(unsigned char*)ptr;
		ft_put_hex(c);
		ft_putstr(" ");
		i += sizeof(unsigned char);
		ptr += sizeof(unsigned char);
	}
	ft_putstr("\n");
}

void		dump_data32(void *ptr, void *vm_start, uint64_t size)
{
	void *ptr_start;
	uint64_t i;
	unsigned char c;

	i = 0;
	ptr_start = ptr;
	while (i < size)
	{
		if (i % 16 == 0)
		{
			if (i != 0)
				ft_putstr("\n");
			ft_put_addr_32((size_t)vm_start + (ptr - ptr_start));
			ft_putstr("\t");
		}
		c = *(unsigned char*)ptr;
		ft_put_hex(c);
		if ((i + 1) % 4 == 0)
			ft_putstr(" ");
		i += sizeof(unsigned char);
		ptr += sizeof(unsigned char);
	}
	ft_putstr("\n");
}

void		read_section64(void *ptr, struct load_command *lc, uint32_t ncmds,
				int endian)
{
	uint32_t					i;
	uint32_t					j;
	struct segment_command_64	*seg_cmd;
	struct section_64			*section;

	i = 0;
	while (i < ncmds)
	{
		if ((endian ? swap_byte32_t(lc->cmd) : lc->cmd) == LC_SEGMENT_64)
		{
			seg_cmd = (struct segment_command_64*)lc;
			j = 0;
			while (j < (endian ?
					swap_byte32_t(seg_cmd->nsects) : seg_cmd->nsects))
			{
				section = (struct section_64*)
					(((void*)seg_cmd + sizeof(struct segment_command_64))
					 + (sizeof(struct section_64) * j));
				if (ft_strcmp(section->segname, "__TEXT") == 0
					&& ft_strcmp(section->sectname, "__text") == 0)
				{
					dump_data64(ptr + section->offset,
							(void*)0 + section->addr, section->size);
				}
				j++;
			}
		}
		lc = (void*)lc + (endian ? swap_byte32_t(lc->cmdsize) : lc->cmdsize);
		i++;
	}
}

void		read_section32(void *ptr, struct load_command *lc, uint32_t ncmds,
				int endian)
{
	uint32_t					i;
	uint32_t					j;
	struct segment_command		*seg_cmd;
	struct section				*section;

	i = 0;
	while (i < ncmds)
	{
		if ((endian ? swap_byte32_t(lc->cmd) : lc->cmd) == LC_SEGMENT)
		{
			seg_cmd = (struct segment_command*)lc;
			j = 0;
			while (j < (endian ?
					swap_byte32_t(seg_cmd->nsects) : seg_cmd->nsects))
			{
				section = (struct section*)
					(((void*)seg_cmd + sizeof(struct segment_command))
					 + (sizeof(struct section) * j));
				if (ft_strcmp(section->segname, "__TEXT") == 0
					&& ft_strcmp(section->sectname, "__text") == 0)
				{
					dump_data32(ptr + (endian ? swap_byte32_t(section->offset) :
						section->offset), (void*)0 +
						(endian ? swap_byte32_t(section->addr) : section->addr),
						section->size);
				}
				j++;
			}
		}
		lc = (void*)lc + (endian ? swap_byte32_t(lc->cmdsize) : lc->cmdsize);
		i++;
	}
}

void	handle_64(char *ptr, char *filename, int endian)
{
	struct mach_header_64 	*header;
	uint32_t				ncmds;
	struct load_command		*lc;

	ft_putstr(filename);
	ft_putstr(":\nContents of (__TEXT,__text) section\n");
	header = (struct mach_header_64 *)ptr;
	ncmds = endian ? swap_byte32_t(header->ncmds) : header->ncmds;
	lc = (void*)ptr + sizeof(struct mach_header_64);
	read_section64(ptr, lc, ncmds, endian);

}

void	handle_32(char *ptr, char *filename, int endian)
{
	struct mach_header		*header;
	uint32_t				ncmds;
	struct load_command		*lc;

	ft_putstr(filename);
	ft_putstr(":\nContents of (__TEXT,__text) section\n");
	header = (struct mach_header*)ptr;
	ncmds = endian ? swap_byte32_t(header->ncmds) : header->ncmds;
	lc = (void*)ptr + sizeof(struct mach_header);
	read_section32(ptr, lc, ncmds, endian);
}

void 	otool(char *fn, char *ptr)
{
	(void)ptr;
	uint32_t magic_number;

	magic_number = *(uint32_t*)ptr;
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		magic_number == MH_MAGIC_64 ? handle_64(ptr, fn, 0) : handle_64(ptr, fn, 1);
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
		magic_number == MH_MAGIC ? handle_32(ptr, fn,0) : handle_32(ptr, fn, 1);
	else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		fat_otool(fn, ptr);
	/*else
		archive(filename, ptr); */
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
