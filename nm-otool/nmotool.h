/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmotool.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:47:44 by amathias          #+#    #+#             */
/*   Updated: 2017/04/03 08:56:51 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NMOTOOL_H
# define NMOTOOL_H

# include <sys/stat.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/ranlib.h>
# include <mach-o/fat.h>
# include <ar.h>
# include <sys/mman.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
#include <assert.h>

typedef struct			s_symbol
{
	void				*sym_name;
	void				*symbol;
	struct s_symbol		*next;
}						t_symbol;

typedef struct			s_section32
{
	struct section		*sec;
}						t_section32;

typedef struct			s_section64
{
	struct section_64	*sec;
}						t_section64;

void			nm(char *filename, char *ptr);
void			ft_put_addr_64(size_t n);
void			ft_put_addr_32(size_t n);
void			archive(char *filename, char *ptr);
void			handle_ar(char *filename, void *file_ptr, void *ar_ptr);
void			fat(char *filename, void *ptr);
void			dump_nlist_32(void *str_table, struct nlist *nlist,
					t_section32 *sec, int endian);
void			dump_nlist_64(void *str_table, struct nlist_64 *nlist,
					t_section64 *sec, int endian);

uint32_t		swap_byte32_t(uint32_t val);
void			print_symbol(t_symbol *symbol, void *string_table_ptr);
t_symbol		*ft_new_symbol(void *name, void *symbolptr);
void			ft_lst_sorted_insert(t_symbol **head, t_symbol *sym);
void			ft_lst_sorted_insert_addr(t_symbol **head, t_symbol *sym,
					void *string_table_ptr);
#endif
