/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 17:01:07 by amathias          #+#    #+#             */
/*   Updated: 2016/09/15 13:31:55 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_bmp	read_header(int fd)
{
	unsigned char	header[54];
	t_bmp			bmp;

	if (read(fd, &header, 54) != 54)
	{
		ft_putstr("Invalid header size");
		exit(0);
	}
	if (header[0] != 'B' || header[1] != 'M')
	{
		ft_putstr("Invalid BMP file");
		exit(0);
	}
	bmp.data_start = *(int*)&(header[0xA]);
	bmp.img_size = *(int*)&(header[0x22]);
	bmp.width = *(int*)&(header[0x12]);
	bmp.height = *(int*)&(header[0x16]);
	bmp.data_start = bmp.data_start == 0 ? 54 : bmp.data_start;
	bmp.img_size = bmp.img_size == 0 ? bmp.width * bmp.height * 3
		: bmp.img_size;
	bmp.data = malloc(sizeof(char) * bmp.img_size);
	return (bmp);
}

t_bmp	parse_bmp(char *filename)
{
	t_bmp	bmp;
	int		fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("Cannot open BMP file");
		exit(0);
	}
	bmp = read_header(fd);
	read(fd, bmp.data, bmp.img_size);
	close(fd);
	return (bmp);
}
