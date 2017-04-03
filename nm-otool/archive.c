/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:54:42 by amathias          #+#    #+#             */
/*   Updated: 2017/04/03 09:32:14 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

void 	dump_data(void *data, uint32_t data_size)
{
	char		*str;
	uint32_t	i;

	i = 0;
	str = (char*)data;
	printf("\n######## data_size: %u\n", data_size);
	while (i < data_size)
	{
		printf("%c", str[i]);
		i++;
	}
}

void	handle_symdef(void *ptr, uint32_t data_size)
{
	struct ranlib	*lib;
	void			*data_start;
	(void)			data_size;

	if (ft_strncmp((char*)ptr, SYMDEF_SORTED, ft_strlen(SYMDEF_SORTED)) == 0)
		data_start = (void*)ptr + ft_strlen(SYMDEF_SORTED);
	else if (ft_strncmp((char*)ptr, SYMDEF, ft_strlen(SYMDEF)) == 0)
		data_start = (void*)ptr + ft_strlen(SYMDEF);
	else
		return ;
	dump_data(ptr, data_size);
	lib = (struct ranlib*)data_start;
	printf("%u %u\n", lib->ran_un.ran_strx, lib->ran_off);
	lib = (void*)data_start + sizeof(struct ranlib);
	printf("%u %u\n", lib->ran_un.ran_strx, lib->ran_off);
	/*
	while ((void*)lib < (void*)data_start + data_size)
	{
		printf("%u %u\n", lib->ran_un.ran_strx, lib->ran_off);
		lib = (void*)lib + sizeof(struct ranlib);
		i++;
	} */
	lib = (void*)lib + sizeof(struct ranlib);
}


void	handle_data(struct ar_hdr *header, void *data_start, uint32_t data_size)
{
	void *lib;
	//uint32_t lib_size;

	(void)header;
	(void)data_start;
	(void)data_size;
	//TODO: read data from archive entry
	lib = (void *)header + sizeof(struct ar_hdr);
	if (ft_strncmp((char*)lib, SYMDEF_SORTED, ft_strlen(SYMDEF_SORTED)) == 0)
		lib = (void*)lib + ft_strlen(SYMDEF_SORTED);
	else if (ft_strncmp((char*)lib, SYMDEF, ft_strlen(SYMDEF)) == 0)
		lib = (void*)lib + ft_strlen(SYMDEF);
	printf("%ld\n", (void*)lib - (void*)header);
	/*
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
			//handle_data(header, (void *)header + sizeof(struct ar_hdr), ar_size);
			handle_symdef((void*)header + sizeof(struct ar_hdr), ar_size);
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
