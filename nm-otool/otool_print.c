/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:47:44 by amathias          #+#    #+#             */
/*   Updated: 2017/04/03 08:56:51 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

void		dump_data64(void *ptr, void *vm_start, uint64_t size)
{
	void			*ptr_start;
	uint64_t		i;
	unsigned char	c;

	i = 0;
	ptr_start = ptr;
	while (i < size)
	{
		if (i % 16 == 0)
		{
			if (i != 0)
				ft_putstr("\n");
			ft_put_addr_64((size_t)vm_start + (ptr - ptr_start));
			ft_putstr("\t");
		}
		c = *(unsigned char*)ptr;
		ft_put_hex(c);
		ft_putstr(" ");
		i += sizeof(unsigned char);
		ptr += sizeof(unsigned char);
	}
	if (size != 0)
		ft_putstr("\n");
}

void		dump_data32(void *ptr, void *vm_start, uint64_t size, int endian)
{
	void			*ptr_start;
	uint64_t		i;
	unsigned char	c;

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
		if (!endian || (i + 1) % 4 == 0)
			ft_putstr(" ");
		i += sizeof(unsigned char);
		ptr += sizeof(unsigned char);
	}
	if (size != 0)
		ft_putstr("\n");
}

void		read_section64(void *ptr, struct load_command *lc, uint32_t ncmds,
				int en)
{
	struct segment_command_64	*cmd;
	struct section_64			*sec;
	uint32_t					i;
	uint32_t					j;

	i = 0;
	while (i < ncmds)
	{
		if (!(j = 0) && (en ? swap_byte32_t(lc->cmd) : lc->cmd)
				== LC_SEGMENT_64)
		{
			cmd = (struct segment_command_64*)lc;
			while (j < (en ? swap_byte32_t(cmd->nsects) : cmd->nsects))
			{
				sec = (struct section_64*)(((void*)cmd +
sizeof(struct segment_command_64)) + (sizeof(struct section_64) * j));
				if (is_text_section((struct section*)sec))
					dump_data64(ptr + sec->offset, (void*)sec->addr, sec->size);
				j++;
			}
		}
		lc = (void*)lc + (en ? swap_byte32_t(lc->cmdsize) : lc->cmdsize);
		i++;
	}
}

void		read_section32(void *ptr, struct load_command *lc, uint32_t ncmds,
				int en)
{
	struct segment_command		*cmd;
	struct section				*sec;
	uint32_t					i;
	uint32_t					j;

	i = 0;
	while (i < ncmds)
	{
		if (!(j = 0) && (en ? swap_byte32_t(lc->cmd) : lc->cmd) == LC_SEGMENT)
		{
			cmd = (struct segment_command*)lc;
			while (j < (en ? swap_byte32_t(cmd->nsects) : cmd->nsects))
			{
				sec = (struct section*)
(((void*)cmd + sizeof(struct segment_command)) + (sizeof(struct section) * j));
				if (is_text_section(sec))
					dump_data32(ptr + (en ? swap_byte32_t(sec->offset) :
sec->offset), (void*)0 + (en ? swap_byte32_t(sec->addr) : sec->addr),
(en ? swap_byte32_t(sec->size) : sec->size), en);
				j++;
			}
		}
		lc = (void*)lc + (en ? swap_byte32_t(lc->cmdsize) : lc->cmdsize);
		i++;
	}
}
