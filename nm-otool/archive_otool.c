/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_otool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:54:42 by amathias          #+#    #+#             */
/*   Updated: 2017/04/03 09:32:14 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

void	parse_empty(char *filename, void *ptr, void *string_table_ptr)
{
	int				ret;

	ft_putstr("\n");
	while (1)
	{
		if (!is_ar(string_table_ptr))
			return ;
		ft_putstr(filename);
		ft_putstr("(");
		if ((ret = handle_ar(filename, ptr, string_table_ptr)) == 0)
			return ;
		if (!sanity_check(string_table_ptr, ret + sizeof(struct ar_hdr)))
			return ;
		string_table_ptr += (ret + sizeof(struct ar_hdr));
	}
}

void	parse_symbols(char *filename, void *ptr, t_symbol *symbol,
			void *string_table_ptr)
{
	t_symbol		*temp;

	temp = symbol;
	if (symbol == NULL)
	{
		parse_empty(filename, ptr, string_table_ptr);
	}
	while (temp)
	{
		if (temp == symbol)
			ft_putstr("\n");
		ft_putstr(filename);
		ft_putstr("(");
		handle_ar(filename, ptr, temp->symbol);
		temp = temp->next;
	}
}

int		handle_symdef(char *filename, void *ptr, void *symdef_start)
{
	struct ranlib	*lib;
	void			*data_start;
	void			*temp_ptr;
	void			*string_table_start;
	t_symbol		*head;

	head = NULL;
	if (!is_symdef(symdef_start))
		return (0);
	data_start = (void*)symdef_start + is_symdef(symdef_start);
	lib = (struct ranlib*)data_start;
	temp_ptr = (void*)data_start + sizeof(data_start);
	string_table_start = (void*)temp_ptr + (lib->ran_off + sizeof(uint32_t));
	while (temp_ptr + sizeof(struct ranlib) < string_table_start)
	{
		lib = (struct ranlib*)temp_ptr;
		ft_lst_sorted_insert_addr(&head,
		ft_new_symbol(string_table_start + lib->ran_un.ran_strx,
			ptr + lib->ran_off), string_table_start);
		temp_ptr += sizeof(struct ranlib);
	}
	parse_symbols(filename, ptr, head, string_table_start);
	lib = (void*)lib + sizeof(struct ranlib);
	ft_lstdelsymbol(&head);
	return (1);
}

int		handle_ar(char *filename, void *file_ptr, void *ar_ptr)
{
	struct ar_hdr	*ar_header;
	uint32_t		ar_size;
	uint32_t		magic_number;

	ar_header = (struct ar_hdr*)((void*)ar_ptr);
	if (ft_strlen(ar_header->ar_fmag)
			&& ft_strncmp(ar_header->ar_fmag, ARFMAG, 2) == 0)
	{
		ar_size = ft_atoi(ar_header->ar_size);
		if (!sanity_check(ar_ptr, ar_size))
			return (0);
		if (!handle_symdef(filename, file_ptr,
					(void*)ar_ptr + sizeof(struct ar_hdr)))
		{
			ft_putstr(ar_ptr + sizeof(struct ar_hdr));
			ft_putstr("):\n");
			ar_ptr += sizeof(struct ar_hdr);
			while ((magic_number = *(uint32_t*)ar_ptr) != MH_MAGIC_64)
				ar_ptr++;
			otool_nofilename(filename, (void*)ar_ptr);
			return (ar_size);
		}
	}
	return (0);
}

void	archive_otool(char *filename, char *ptr)
{
	if (!sanity_check((void*)ptr, SARMAG))
		return ;
	if (ft_strncmp(ptr, ARMAG, SARMAG) == 0)
	{
		ft_putstr("Archive : ");
		ft_putstr(filename);
		handle_ar(filename, ptr, ptr + SARMAG);
	}
}
