/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstatic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:38:19 by amathias          #+#    #+#             */
/*   Updated: 2017/03/18 16:45:58 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

void	handle_ranlib(:char *ptr)
{
	struct ranlib *lib;

	lib = (void *)ptr + sizeof(struct ar_hdr);

}

void	archive(char *ptr)
{
	struct ar_hdr *header;

	//TODO: Min size ? (to avoid sigv ?)
	header = (struct ar_hdr*)ptr;
	if (ft_strncmp(header->ar_name, ARMAG, SARMAG) == 0
			|| ft_strncmp(header->ar_name, (char*)OARMAG1, SARMAG) == 0
			|| ft_strncmp(header->ar_name, (char*)OARMAG2, SARMAG) == 0){
		printf("ARCHIVE FILE\n");
		printf("ar_size: %s\n", header->ar_size);

	}
}
