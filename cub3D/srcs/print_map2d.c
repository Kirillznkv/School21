/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:25:25 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/27 09:59:40 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		put_square(t_data *img, int x, int y, int color)
{
	int		i;
	int		j;
	int		n;

	i = x - 1;
	n = 10;
	while (++i < x + n)
	{
		j = y - 1;
		while (++j < y + n)
			my_mlx_pixel_put(img, i, j, color);
	}
}

int			get_color(char ch)
{
	if (ch == ' ' || ch == '2' || ch == '0')
		return (0x000000);
	if (ch == '1')
		return (0xFFFFFF);
	if (ft_strchr("WSNE", ch))
		return (0x00FF00);
	return (0);
}

void		put_map(t_map_settings *map, t_data *img)
{
	int		x;
	int		y;
	int		color;
	int		i;
	int		j;

	y = 0;
	i = -1;
	while (map->map[++i])
	{
		x = 0;
		j = -1;
		while (map->map[i][++j])
		{
			color = get_color(map->map[i][j]);
			put_square(img, x, y, color);
			x += 10;
		}
		y += 10;
	}
}

void		print_map2d(t_map_settings *tmp)
{
	void		*mlx;
	void		*win;
	t_data		img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "test");
	img.img = mlx_new_image(mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	put_map(tmp, &img);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
}