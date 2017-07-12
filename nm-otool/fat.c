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
	(void)arch;

	ft_putstr("\n");
	ft_putstr(filename);
	ft_putstr(" (for architecture ");
	if (swap_byte32_t(arch->cputype == CPU_TYPE_X86_64))
		ft_putstr("x86_64");
	if (swap_byte32_t(arch->cputype) == CPU_TYPE_X86)
		ft_putstr("i386");
	else if (swap_byte32_t(arch->cputype) == CPU_TYPE_POWERPC)
		ft_putstr("ppc");
	else
		assert(0); //Arch non implemented
	ft_putstr("):\n");
}

void	fat(char *filename, void *ptr)
{
	uint32_t			magic_number;
	struct fat_header	*fheader;
	struct fat_arch		*farch;
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
				nm(filename, ptr + swap_byte32_t(farch[i].offset));
				return ;
			}
			i++;
		}
		i = 0;
		while (i < swap_byte32_t(fheader->nfat_arch))
		{
			dump_fat_arch(filename, &farch[i]);
			/*printf("offset: %d\nsize: %d\nalign: %d\n",
					swap_byte32_t(farch[i].offset),
					swap_byte32_t(farch[i].size),
					swap_byte32_t(farch[i].align)); */
			nm(filename, ptr + swap_byte32_t(farch[i].offset));
			i++;
		}
	}
}
