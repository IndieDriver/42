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
void			fat(char *filename, void *ptr);
void			archive(char *filename, char *ptr);
int				handle_ar(char *filename, void *file_ptr, void *ar_ptr);
void			dump_nlist_32(void *str_table, struct nlist *nlist,
					t_section32 *sec, int endian);
void			dump_nlist_64(void *str_table, struct nlist_64 *nlist,
					t_section64 *sec, int endian);

void 			otool(char *fn, char *ptr);
void			otool_nofilename(char *fn, char *ptr);
void			fat_otool(char *filename, void *ptr);
void			archive_otool(char *filename, char *ptr);
void			read_section64(void *ptr, struct load_command *lc, uint32_t ncmds,
					int endian);
void			read_section32(void *ptr, struct load_command *lc, uint32_t ncmds,
					int endian);

void			ft_put_addr_64(size_t n);
void			ft_put_addr_32(size_t n);
void			ft_put_hex(unsigned char n);
uint32_t		swap_byte32_t(uint32_t val);
void			print_symbol(t_symbol *symbol, void *string_table_ptr);
t_symbol		*ft_new_symbol(void *name, void *symbolptr);
int				ft_contain_symbol(t_symbol **head, t_symbol *sym);
void			ft_lst_sorted_insert(t_symbol **head, t_symbol *sym);
void			ft_lst_sorted_insert_addr(t_symbol **head, t_symbol *sym,
					void *string_table_ptr);
#endif
