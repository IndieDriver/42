/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:09:51 by amathias          #+#    #+#             */
/*   Updated: 2017/04/02 15:29:28 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

void	print_section_character_64(t_section64 *sec, int index,
			unsigned char n_type, unsigned char n_ext)
{
	if (index > 255 || index < 0)
		return ;
	if (n_type == N_ABS)
		ft_putstr(" A ");
	else if (n_type == N_INDR)
		ft_putstr(" I ");
	else if (ft_strcmp(sec[index].sec->segname, "__DATA") == 0)
	{
		if (ft_strcmp(sec[index].sec->sectname, "__data") == 0)
			n_ext ? ft_putstr(" D ") : ft_putstr(" d ");
		else if (ft_strcmp(sec[index].sec->sectname, "__bss") == 0)
			n_ext ? ft_putstr(" B ") : ft_putstr(" b ");
		else
			n_ext ? ft_putstr(" S ") : ft_putstr(" s ");
	}
	else if (ft_strcmp(sec[index].sec->segname, "__TEXT") == 0)
	{
		if (ft_strcmp(sec[index].sec->sectname, "__text") == 0)
			n_ext ? ft_putstr(" T ") : ft_putstr(" t ");
		else
			n_ext ? ft_putstr(" S ") : ft_putstr(" s ");
	}
	else
		n_ext ? ft_putstr(" S ") : ft_putstr(" s ");
}

void	print_section_character_32(t_section32 *sec, int index,
			unsigned char n_type, unsigned char n_ext)
{
	if (index > 255 || index < 0)
		return ;
	if (n_type == N_ABS)
		ft_putstr(" A ");
	else if (n_type == N_INDR)
		ft_putstr(" I ");
	else if (ft_strcmp(sec[index].sec->segname, "__DATA") == 0)
	{
		if (ft_strcmp(sec[index].sec->sectname, "__data") == 0)
			n_ext ? ft_putstr(" D ") : ft_putstr(" d ");
		else if (ft_strcmp(sec[index].sec->sectname, "__bss") == 0)
			n_ext ? ft_putstr(" B ") : ft_putstr(" b ");
		else
			n_ext ? ft_putstr(" S ") : ft_putstr(" s ");
	}
	else if (ft_strcmp(sec[index].sec->segname, "__TEXT") == 0)
	{
		if (ft_strcmp(sec[index].sec->sectname, "__text") == 0)
			n_ext ? ft_putstr(" T ") : ft_putstr(" t ");
		else
			n_ext ? ft_putstr(" S ") : ft_putstr(" s ");
	}
	else
		n_ext ? ft_putstr(" S ") : ft_putstr(" s ");
}

void	dump_nlist_64(void *str_table, struct nlist_64 *nlist64,
			t_section64 *sec, int endian)
{
	unsigned char n_stab;
	unsigned char n_type;
	unsigned char n_ext;

	n_stab = nlist64->n_type & N_STAB;
	n_type = nlist64->n_type & N_TYPE;
	n_ext = nlist64->n_type & N_EXT;
	sanity_check(str_table,
		(endian ? swap_byte32_t(nlist64->n_un.n_strx) : nlist64->n_un.n_strx));
	if (ft_strlen(str_table + (endian ? swap_byte32_t(nlist64->n_un.n_strx) :
			nlist64->n_un.n_strx)) == 0)
		return ;
	if (n_stab)
		return ;
	if (n_type == N_UNDF)
		ft_putstr("                 U ");
	else
	{
		ft_put_addr_64((size_t)(endian ?
					swap_byte32_t(nlist64->n_value) : nlist64->n_value));
		print_section_character_64(sec, nlist64->n_sect, n_type, n_ext);
	}
	ft_putstr("");
	ft_putstr(str_table + nlist64->n_un.n_strx);
	ft_putstr("\n");
}

void	dump_nlist_32(void *str_table, struct nlist *nlist,
			t_section32 *sec, int endian)
{
	unsigned char n_stab;
	unsigned char n_type;
	unsigned char n_ext;

	n_stab = nlist->n_type & N_STAB;
	n_type = nlist->n_type & N_TYPE;
	n_ext = nlist->n_type & N_EXT;
	sanity_check(str_table,
			(endian ? swap_byte32_t(nlist->n_un.n_strx) : nlist->n_un.n_strx));
	if (ft_strlen(str_table + (endian ? swap_byte32_t(nlist->n_un.n_strx) :
			nlist->n_un.n_strx)) == 0)
		return ;
	if (n_stab)
		return ;
	if (n_type == N_UNDF)
		ft_putstr("         U ");
	else
	{
		ft_put_addr_32((size_t)(endian ?
					swap_byte32_t(nlist->n_value) : nlist->n_value));
		print_section_character_32(sec, nlist->n_sect, n_type, n_ext);
	}
	ft_putstr(str_table +
			(endian ? swap_byte32_t(nlist->n_un.n_strx) : nlist->n_un.n_strx));
	ft_putstr("\n");
}
