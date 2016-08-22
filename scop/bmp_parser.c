/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 17:01:07 by amathias          #+#    #+#             */
/*   Updated: 2016/08/22 17:28:38 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	read_header(int fd)
{
	unsigned char header[54];
	
	read(fd, &header, 54);
	if (header[0] != 'B' || header[1] != 'M')
		ft_putstr("Invalid BMP file");
}
char	*parse_bmp(char *filename)
{
	int fd;
	
	if ((fd = open(file_name, 0_RDONLY)) == -1)
		return (NULL);
	read_hearder(fd);
	
}
