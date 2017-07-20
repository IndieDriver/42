/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_section.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:47:44 by amathias          #+#    #+#             */
/*   Updated: 2017/04/03 08:56:51 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

t_section64	*get_subsection64(t_section64 *section,
				struct segment_command_64 *seg_cmd, uint32_t *k, int endian)
{
	uint32_t j;

	j = 0;
	while (j < (endian ? swap_byte32_t(seg_cmd->nsects) : seg_cmd->nsects))
	{
		section[*k + j].sec = (struct section_64*)(((void*)seg_cmd +
			sizeof(struct segment_command_64)) +
			(sizeof(struct section_64) * j));
		j++;
	}
	*k += (endian ? swap_byte32_t(seg_cmd->nsects) : seg_cmd->nsects);
	return (section);
}

t_section64	*get_section64(struct load_command *lc, uint32_t ncmds, int en)
{
	uint32_t					i;
	uint32_t					k;
	struct segment_command_64	*seg_cmd;
	t_section64					*sections;

	i = 0;
	k = 1;
	sections = malloc(sizeof(t_section64*) * 256);
	ft_bzero(sections, sizeof(t_section64*) * 256);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			seg_cmd = (struct segment_command_64*)lc;
			get_subsection64(sections, seg_cmd, &k, en);
		}
		if (!sanity_check(lc, (en ? swap_byte32_t(lc->cmdsize) : lc->cmdsize)))
			return (NULL);
		lc = (void*)lc + (en ? swap_byte32_t(lc->cmdsize) : lc->cmdsize);
		i++;
	}
	return (sections);
}

t_section32	*get_subsection32(t_section32 *section,
				struct segment_command *seg_cmd, uint32_t *k, int endian)
{
	uint32_t j;

	j = 0;
	while (j < (endian ? swap_byte32_t(seg_cmd->nsects) : seg_cmd->nsects))
	{
		section[*k + j].sec = (struct section*)(((void*)seg_cmd +
			sizeof(struct segment_command)) +
			(sizeof(struct section) * j));
		j++;
	}
	*k += (endian ? swap_byte32_t(seg_cmd->nsects) : seg_cmd->nsects);
	return (section);
}

t_section32	*get_section32(struct load_command *lc, uint32_t ncmds, int en)
{
	uint32_t					i;
	uint32_t					k;
	struct segment_command		*seg_cmd;
	t_section32					*sections;

	i = 0;
	k = 1;
	sections = malloc(sizeof(t_section32*) * 256);
	ft_bzero(sections, sizeof(t_section32*) * 256);
	while (i < ncmds)
	{
		if ((en ? swap_byte32_t(lc->cmd) : lc->cmd) == LC_SEGMENT)
		{
			seg_cmd = (struct segment_command*)lc;
			get_subsection32(sections, seg_cmd, &k, en);
		}
		if (!sanity_check(lc, (en ? swap_byte32_t(lc->cmdsize) : lc->cmdsize)))
			return (NULL);
		lc = (void*)lc + (en ? swap_byte32_t(lc->cmdsize) : lc->cmdsize);
		i++;
	}
	return (sections);
}
