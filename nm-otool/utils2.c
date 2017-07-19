/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:54:42 by amathias          #+#    #+#             */
/*   Updated: 2017/04/03 09:32:14 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

int		is_ar(void *ar_start)
{
	struct ar_hdr	*ar_header;

	ar_header = (struct ar_hdr*)((void*)ar_start);
	if (ft_strlen(ar_header->ar_fmag)
			&& ft_strncmp(ar_header->ar_fmag, ARFMAG, 2) == 0)
	{
		return (ft_atoi(ar_header->ar_size));
	}
	return (0);
}

int		is_symdef(void *symdef_start)
{
	if (sanity_check(symdef_start, ft_strlen(SYMDEF_SORTED))
			&& ft_strncmp((char*)symdef_start, SYMDEF_SORTED,
				ft_strlen(SYMDEF_SORTED)) == 0)
		return (ft_strlen(SYMDEF_SORTED));
	else if (sanity_check(symdef_start, ft_strlen(SYMDEF))
			&& ft_strncmp((char*)symdef_start, SYMDEF,
				ft_strlen(SYMDEF)) == 0)
		return (ft_strlen(SYMDEF));
	else
		return (0);
}

int		is_text_section(struct section *sec)
{
	if (ft_strcmp(sec->segname, "__TEXT") == 0
			&& ft_strcmp(sec->sectname, "__text") == 0)
		return (1);
	return (0);
}

void	ft_lstdelsymbol(t_symbol **alst)
{
	t_symbol *current;
	t_symbol *next;

	current = *alst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*alst = NULL;
}

int		sanity_check(void *ptr, size_t offset)
{
	if (ptr + offset >= g_filelimit)
	{
		ft_putstr("Oops something's wrong with this binary file\n");
		exit(EXIT_FAILURE);
		return (0);
	}
	return (1);
}
