/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:09:51 by amathias          #+#    #+#             */
/*   Updated: 2017/04/02 15:29:28 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

void	dump_fat_arch(char *filename, struct fat_arch *arch)
{
	ft_putstr("\n");
	ft_putstr(filename);
	ft_putstr(" (for architecture ");
	if (swap_byte32_t(arch->cputype) == CPU_TYPE_X86_64)
		ft_putstr("x86_64");
	else if (swap_byte32_t(arch->cputype) == CPU_TYPE_X86)
		ft_putstr("i386");
	else if (swap_byte32_t(arch->cputype) == CPU_TYPE_POWERPC)
		ft_putstr("ppc");
	else
		assert(0);
	ft_putstr("):\n");
}

void	parse_fat_arch(void *ptr, char *filename, struct fat_header *fheader,
			struct fat_arch *farch)
{
	uint32_t i;

	i = 0;
	if (swap_byte32_t(fheader->nfat_arch) == 1)
	{
		ft_putstr(filename);
		ft_putstr(":\n");
		nm(filename, ptr + swap_byte32_t(farch[i].offset), 0);
		return ;
	}
	while (i < swap_byte32_t(fheader->nfat_arch))
	{
		dump_fat_arch(filename, &farch[i]);
		sanity_check(ptr, swap_byte32_t(farch[i].offset));
		nm(filename, ptr + swap_byte32_t(farch[i].offset), 0);
		i++;
	}
}

void	fat(char *filename, void *ptr)
{
	struct fat_header	*fheader;
	struct fat_arch		*farch;
	uint32_t			magic_number;
	uint32_t			i;

	magic_number = *(uint32_t*)ptr;
	if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
	{
		fheader = (struct fat_header*)ptr;
		i = 0;
		farch = (struct fat_arch*)(ptr + sizeof(struct fat_header));
		while (i < swap_byte32_t(fheader->nfat_arch))
		{
			if (swap_byte32_t(farch[i].cputype) == CPU_TYPE_X86_64)
			{
				sanity_check(ptr, swap_byte32_t(farch[i].offset));
				nm(filename, ptr + swap_byte32_t(farch[i].offset), 0);
				return ;
			}
			i++;
		}
		parse_fat_arch(ptr, filename, fheader, farch);
	}
}
