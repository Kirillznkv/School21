/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:47:31 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/05 09:28:11 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

void			make_head(unsigned char *bmp_head, unsigned char *bmp_fhead, t_map_settings *tmp)
{
	int		size;

	size = 14 + 40 + tmp->width * tmp->height * tmp->img.bits_per_pixel / 8;
	bmp_head[0] = 'B';
	bmp_head[1] = 'M';
	bmp_head[2] = (unsigned char)(size);
	bmp_head[3] = (unsigned char)(size >> 8);
	bmp_head[4] = (unsigned char)(size >> 16);
	bmp_head[5] = (unsigned char)(size >> 24);
	bmp_head[10] = (unsigned char)(54);
	bmp_fhead[0] = (unsigned char)(40);
	bmp_fhead[4] = (unsigned char)(tmp->width);
	bmp_fhead[5] = (unsigned char)(tmp->width >> 8);
	bmp_fhead[6] = (unsigned char)(tmp->width >> 16);
	bmp_fhead[7] = (unsigned char)(tmp->width >> 24);
	bmp_fhead[8] = (unsigned char)(-tmp->height);
	bmp_fhead[9] = (unsigned char)(-tmp->height >> 8);
	bmp_fhead[10] = (unsigned char)(-tmp->height >> 16);
	bmp_fhead[11] = (unsigned char)(-tmp->height >> 24);
	bmp_fhead[12] = (unsigned char)(1);
	bmp_fhead[14] = (unsigned char)(tmp->img.bits_per_pixel);
}

void			make_file_scr(unsigned char *bmp_head, unsigned char *bmp_fhead, t_map_settings *tmp)
{
	int		fd;
	char	*filename;
	int		i;
	int		size;

	i = -1;
	filename = "screen.bmp";
	if ((fd = open(filename, O_RDWR | O_CREAT, 0777)) < 0)
		error_system(errno);
	write(fd, bmp_head, 14);
	write(fd, bmp_fhead, 40);
	size = tmp->img.bits_per_pixel / 8 * tmp->width;
	while (++i < tmp->height)
		write(fd, tmp->img.addr + i * tmp->img.line_length, size);
}

void			screen(t_map_settings *tmp)
{
	unsigned char	bmp_head[15];
	unsigned char	bmp_fhead[40];

	write(1, "Saving screenshot\n", 18);
	ft_bzero(bmp_head, 15);
	ft_bzero(bmp_fhead, 40);
	make_head(bmp_head, bmp_fhead, tmp);
	make_file_scr(bmp_head, bmp_fhead, tmp);
	mlx_destroy_window(tmp->mlx, tmp->win);
	exit(0);
}