/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:25:25 by kshanti           #+#    #+#             */
/*   Updated: 2021/02/06 20:16:58 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		ray(t_map_settings *tmp, t_data *img, double x, double y)
{
	int			step;
	double		dy;
	double		dx;

	dy = tmp->plr.y - y - 1;
	dx = tmp->plr.x - x - 1;
	step = (abs(dy) > abs(dx)) ? abs(dy) : abs(dx);
	my_mlx_pixel_put(img, x, y, (int)0xFF0000);
	my_mlx_pixel_put(img, tmp->plr.x, tmp->plr.y, (int)0xFF0000);
	dx = abs(dx) / (double)step;
	dy = abs(dy) / (double)step;
	while (step--)
	{
		x += dx;
		y += dy;
		my_mlx_pixel_put(img, round(x), round(y), (int)0xFF0000);
	}
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
	if (ch == '1')
		return (0xFFFFFF);
	else if (ch == '2')
		return (0xDC5B57);
	return (0x000000);
}

void		put_map(t_map_settings *tmp, t_data *img)
{
	int		x;
	int		y;
	int		color;
	int		i;
	int		j;

	y = 0;
	i = -1;
	while (tmp->map[++i])
	{
		x = 0;
		j = -1;
		while (tmp->map[i][++j])
		{
			color = get_color(tmp->map[i][j]);
			put_square(img, x, y, color);
			x += 10;
		}
		y += 10;
	}
	put_square(img, tmp->plr.x, tmp->plr.y, 0x00FF00);
}

void		print_map2d(t_map_settings *tmp)
{
	put_map(tmp, &tmp->img);
	ray(tmp, &tmp->img, 0, 0);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img, 0, 0);
}
