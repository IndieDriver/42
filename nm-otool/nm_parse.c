/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:09:51 by amathias          #+#    #+#             */
/*   Updated: 2017/04/02 15:29:28 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

void	parse_nlist_64(t_symbol *head, void *str_table, t_nm64 *nm, int endian)
{
	t_symbol		*temp;
	struct n_list64	*nlist;

	temp = head;
	while (temp)
	{
		nlist = temp->symbol;
		dump_nlist_64(str_table, (struct nlist_64*)temp->symbol,
				nm, endian);
		temp = temp->next;
	}
}

void	parse_nlist_32(t_symbol *head, void *str_table, t_nm32 *nm, int endian)
{
	t_symbol		*temp;
	struct nlist	*nlist;

	temp = head;
	while (temp)
	{
		nlist = temp->symbol;
		dump_nlist_32(str_table, (struct nlist*)temp->symbol,
				nm, endian);
		temp = temp->next;
	}
}

void	print_output_64(struct symtab_command *symcmd, void *ptr,
			t_nm64 *nm, int en)
{
	uint32_t		i;
	void			*string_table;
	struct nlist_64	*nlist;
	t_symbol		*head;

	head = NULL;
	sanity_check(ptr, (en ? swap_byte32_t(symcmd->symoff) : symcmd->symoff));
	nlist = (void*)ptr + (en ? swap_byte32_t(symcmd->symoff) : symcmd->symoff);
	sanity_check(ptr, (en ? swap_byte32_t(symcmd->stroff) : symcmd->stroff));
	string_table = (void*)ptr +
		(en ? swap_byte32_t(symcmd->stroff) : symcmd->stroff);
	i = 0;
	while (i < (en ? swap_byte32_t(symcmd->nsyms) : symcmd->nsyms))
	{
		sanity_check(string_table, (en ? swap_byte32_t(nlist[i].n_un.n_strx) :
			nlist[i].n_un.n_strx));
		ft_lst_sorted_insert(&head,
			ft_new_symbol(string_table +
				(en ? swap_byte32_t(nlist[i].n_un.n_strx) :
				nlist[i].n_un.n_strx), &nlist[i]));
		i++;
	}
	parse_nlist_64(head, string_table, nm, en);
	ft_lstdelsymbol(&head);
}

void	print_output_32(struct symtab_command *symcmd, void *ptr,
			t_nm32 *nm, int en)
{
	uint32_t		i;
	void			*string_table;
	struct nlist	*nlist;
	t_symbol		*head;

	head = NULL;
	sanity_check(ptr, (en ? swap_byte32_t(symcmd->symoff) : symcmd->symoff));
	nlist = (void*)ptr +
		(en ? swap_byte32_t(symcmd->symoff) : symcmd->symoff);
	sanity_check(ptr, (en ? swap_byte32_t(symcmd->stroff) : symcmd->stroff));
	string_table = (void*)ptr +
		(en ? swap_byte32_t(symcmd->stroff) : symcmd->stroff);
	i = 0;
	while (i < (en ? swap_byte32_t(symcmd->nsyms) : symcmd->nsyms))
	{
		ft_lst_sorted_insert(&head,
			ft_new_symbol(string_table +
				(en ? swap_byte32_t(nlist[i].n_un.n_strx) :
				nlist[i].n_un.n_strx), &nlist[i]));
		i++;
	}
	parse_nlist_32(head, string_table, nm, en);
	ft_lstdelsymbol(&head);
}

void	print_filename(char *filename)
{
	ft_putstr("\n");
	ft_putstr(filename);
	ft_putstr(":\n");
}
