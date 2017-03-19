/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstatic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:38:19 by amathias          #+#    #+#             */
/*   Updated: 2017/03/19 11:44:31 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

void	handle_data(struct ar_hdr *header, void *data_start, uint32_t data_size)
{
	(void)header;
	(void)data_start;
	(void)data_size;
	//TODO: read data from archive entry
	//printf("handle_data");
	/*
		lib = (void *)header + sizeof(struct ar_hdr);
		if (ft_strncmp((char*)lib, SYMDEF_SORTED, ft_strlen(SYMDEF_SORTED)) == 0)
			lib = (void*)lib + ft_strlen(SYMDEF_SORTED);
		else if (ft_strncmp((char*)lib, SYMDEF, ft_strlen(SYMDEF)) == 0)
			lib = (void*)lib + ft_strlen(SYMDEF);
		lib_size = *(uint32_t*)lib;
		lib = (void*)lib + sizeof(uint32_t);
		i = 0;
		ar_size = ft_atoi(header->ar_size);
		printf("ran_strx: %d\n", lib->ran_un.ran_strx);
		printf("ran_off: %d\n", lib->ran_off);
		while (i < ar_size){
			write(1, (void*)lib + lib->ran_off + i , 1);
			i++;
		}
		lib = (void*)lib + sizeof(struct ranlib);
		i += sizeof(struct ranlib); */
}

void	handle_ranlib(char *ptr)
{
	void			*archive_ptr;
	struct ar_hdr	*header;
	uint32_t		ar_size;

	archive_ptr = ptr + SARMAG;
	while (archive_ptr)
	{
		header = (struct ar_hdr*)((void*)archive_ptr);
		if (ft_strncmp(header->ar_fmag, ARFMAG, 2) == 0){
			ar_size = ft_atoi(header->ar_size);
			handle_data(header, (void *)header + sizeof(struct ar_hdr), ar_size);
			archive_ptr = (void*)header + sizeof(struct ar_hdr) + ar_size;
		} else
			archive_ptr = NULL;
	}
}

void	archive(char *ptr)
{
	//TODO: Min size ? (to avoid sigv ?)
	if (ft_strncmp(ptr, ARMAG, SARMAG) == 0
			|| ft_strncmp(ptr, (char*)OARMAG1, SARMAG) == 0
			|| ft_strncmp(ptr, (char*)OARMAG2, SARMAG) == 0)
	{
		handle_ranlib(ptr);
	}
}
