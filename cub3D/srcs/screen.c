/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 08:47:31 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/05 11:56:33 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

void	make_h(unsigned char *bmp_h, unsigned char *bmp_f, t_map_settings *tmp)
{
	int		size;

	size = 14 + 40 + tmp->width * tmp->height * tmp->img.bits_per_pixel / 8;
	bmp_h[0] = 'B';
	bmp_h[1] = 'M';
	bmp_h[2] = (unsigned char)(size);
	bmp_h[3] = (unsigned char)(size >> 8);
	bmp_h[4] = (unsigned char)(size >> 16);
	bmp_h[5] = (unsigned char)(size >> 24);
	bmp_h[10] = (unsigned char)(54);
	bmp_f[0] = (unsigned char)(40);
	bmp_f[4] = (unsigned char)(tmp->width);
	bmp_f[5] = (unsigned char)(tmp->width >> 8);
	bmp_f[6] = (unsigned char)(tmp->width >> 16);
	bmp_f[7] = (unsigned char)(tmp->width >> 24);
	bmp_f[8] = (unsigned char)(-tmp->height);
	bmp_f[9] = (unsigned char)(-tmp->height >> 8);
	bmp_f[10] = (unsigned char)(-tmp->height >> 16);
	bmp_f[11] = (unsigned char)(-tmp->height >> 24);
	bmp_f[12] = (unsigned char)(1);
	bmp_f[14] = (unsigned char)(tmp->img.bits_per_pixel);
}

void	make_f(unsigned char *bmp_h, unsigned char *bmp_f, t_map_settings *tmp)
{
	int		fd;
	char	*filename;
	int		i;
	int		size;

	i = -1;
	filename = "screen.bmp";
	if ((fd = open(filename, O_RDWR | O_CREAT, 0777)) < 0)
		error_system(errno);
	write(fd, bmp_h, 14);
	write(fd, bmp_f, 40);
	size = tmp->img.bits_per_pixel / 8 * tmp->width;
	while (++i < tmp->height)
		write(fd, tmp->img.addr + i * tmp->img.line_length, size);
}

void	screen(t_map_settings *tmp)
{
	unsigned char	bmp_h[15];
	unsigned char	bmp_f[40];

	write(1, "Saving screenshot\n", 18);
	ft_bzero(bmp_h, 15);
	ft_bzero(bmp_f, 40);
	make_h(bmp_h, bmp_f, tmp);
	make_f(bmp_h, bmp_f, tmp);
	mlx_destroy_window(tmp->mlx, tmp->win);
	exit(0);
}
