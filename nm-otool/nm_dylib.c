/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_dylib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:47:44 by amathias          #+#    #+#             */
/*   Updated: 2017/04/03 08:56:51 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

t_dylib		*get_dylib(struct load_command *lc, uint32_t ncmds, int en)
{
	uint32_t					i;
	uint32_t					k;
	t_dylib						*dylibs;

	i = 0;
	k = 1;
	dylibs = malloc(sizeof(t_section32*) * MAX_LIBRARY_ORDINAL);
	ft_bzero(dylibs, sizeof(t_section32*) * MAX_LIBRARY_ORDINAL);
	while (i < ncmds && k < MAX_LIBRARY_ORDINAL)
	{
		if ((en ? swap_byte32_t(lc->cmd) : lc->cmd) == LC_LOAD_DYLIB
	|| (en ? swap_byte32_t(lc->cmd) : lc->cmd) == LC_LOAD_WEAK_DYLIB
	|| (en ? swap_byte32_t(lc->cmd) : lc->cmd) == LC_REEXPORT_DYLIB
	|| (en ? swap_byte32_t(lc->cmd) : lc->cmd) == LC_LOAD_UPWARD_DYLIB
	|| (en ? swap_byte32_t(lc->cmd) : lc->cmd) == LC_LAZY_LOAD_DYLIB)
		{
			dylibs[k].is_lib = 1;
			k++;
		}
		if (!sanity_check(lc, (en ? swap_byte32_t(lc->cmdsize) : lc->cmdsize)))
			return (NULL);
		lc = (void*)lc + (en ? swap_byte32_t(lc->cmdsize) : lc->cmdsize);
		i++;
	}
	return (dylibs);
}
