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
	printf("\ndata_size: %u\n", data_size);
	while (i < data_size)
	{
		printf("%d: %c", i, str[i]);
		i++;
	}
	printf("\nEND_DUMP\n");
}

void	handle_symbol_table(void *ptr, void *ptr_string, void *ptr_symbol) {
	//printf("string_offset: %#010lx\n", ptr_string - ptr);
	//printf("string: %s\n", ptr_string);
	//printf("ptr_symbol: %#010lx\n", ptr_symbol- ptr);
	(void) ptr_string;
	handle_ar(ptr, ptr_symbol);
}

int		handle_symdef(void *ptr, void *symdef_start, uint32_t data_size)
{
	struct ranlib	*lib;
	void			*data_start;
	void			*temp_ptr;
	void			*string_table_start;
	uint32_t		string_table_size;

	(void)data_size;
	if (ft_strncmp((char*)symdef_start, SYMDEF_SORTED, ft_strlen(SYMDEF_SORTED)) == 0)
		data_start = (void*)symdef_start + ft_strlen(SYMDEF_SORTED);
	else if (ft_strncmp((char*)symdef_start, SYMDEF, ft_strlen(SYMDEF)) == 0)
		data_start = (void*)symdef_start + ft_strlen(SYMDEF);
	else
		return (0);
	lib = (struct ranlib*)data_start;
	temp_ptr = (void*)data_start + sizeof(data_start);
	string_table_start = (void*) temp_ptr + lib->ran_off;
	string_table_size = (uint32_t)string_table_start;
	string_table_start += sizeof(uint32_t);

	while (temp_ptr + sizeof(struct ranlib) < string_table_start)
	{
		lib = (struct ranlib*)temp_ptr;
		handle_symbol_table(ptr, string_table_start + lib->ran_un.ran_strx, ptr + lib->ran_off);
		//printf("\nstrx: %u ran_off: %u\n", lib->ran_un.ran_strx, lib->ran_off);
		temp_ptr += sizeof(struct ranlib);
	}
	lib = (void*)lib + sizeof(struct ranlib);
	return (1);
}

void	handle_ar(void *file_ptr, void *ar_ptr)
{
	struct ar_hdr	*ar_header;
	uint32_t		ar_size;

	ar_header = (struct ar_hdr*)((void*)ar_ptr);
	if (ft_strncmp(ar_header->ar_fmag, ARFMAG, 2) == 0)
	{
		ar_size = ft_atoi(ar_header->ar_size);

		if (handle_symdef(file_ptr, (void*)ar_ptr + sizeof(struct ar_hdr), ar_size)) {

		} else {
			printf("%s\n", (void*)ar_ptr + sizeof(struct ar_hdr));
			uint32_t magic_number;
			ar_ptr += sizeof(struct ar_hdr);
			magic_number = *(uint32_t*)ar_ptr;
			while ((magic_number = *(uint32_t*)ar_ptr) != MH_MAGIC_64) //TODO: seems weird, fix it ?
				ar_ptr++;
			nm((void*)ar_ptr);
		}
	}
}

void	archive(char *ptr)
{
	//TODO: Min size ? (to avoid sigv ?)
	if (ft_strncmp(ptr, ARMAG, SARMAG) == 0
			|| ft_strncmp(ptr, (char*)OARMAG1, SARMAG) == 0
			|| ft_strncmp(ptr, (char*)OARMAG2, SARMAG) == 0)
	{
		handle_ar(ptr, ptr + SARMAG);
		//handle_ranlib(ptr);
	}
}
