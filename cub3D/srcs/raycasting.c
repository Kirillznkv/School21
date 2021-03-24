/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:08:13 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/17 22:53:05 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		fvl(t_map_settings *tmp, int side)
{
	tmp->text.tex_y = (int)tmp->text.tex_p;
	if (side == 1 && tmp->text.tex_y >= tmp->text.img_ea.h)
		tmp->text.tex_y = tmp->text.img_ea.h - 1;
	else if (side == 2 && tmp->text.tex_y >= tmp->text.img_so.h)
		tmp->text.tex_y = tmp->text.img_so.h - 1;
	else if (side == 3 && tmp->text.tex_y >= tmp->text.img_no.h)
		tmp->text.tex_y = tmp->text.img_no.h - 1;
	else if (side == 4 && tmp->text.tex_y >= tmp->text.img_we.h)
		tmp->text.tex_y = tmp->text.img_we.h - 1;
	tmp->text.tex_p += tmp->text.s;
}

void		ver_line(t_map_settings *tmp, int x, t_line line, int side)
{
	int		color;
	int		i;

	i = -1;
	while (++i < line.drawstart)
		my_mlx_pixel_put(&tmp->img, x, i, tmp->color_c.color);
	while (line.drawstart <= line.drawend)
	{
		fvl(tmp, side);
		if (side == 1)
			color = color_ea(tmp, tmp->text.tex_x, tmp->text.tex_y);
		else if (side == 2)
			color = color_so(tmp, tmp->text.tex_x, tmp->text.tex_y);
		else if (side == 3)
			color = color_no(tmp, tmp->text.tex_x, tmp->text.tex_y);
		else if (side == 4)
			color = color_we(tmp, tmp->text.tex_x, tmp->text.tex_y);
		my_mlx_pixel_put(&tmp->img, x, line.drawstart++, color);
	}
	i = line.drawend;
	while (++i < tmp->height)
		my_mlx_pixel_put(&tmp->img, x, i, tmp->color_f.color);
}

void		textur(t_map_settings *t, t_line l, int side)
{
	if (side == 1)
	{
		t->text.tex_x = (int)(t->text.wall_x * (double)t->text.img_ea.w);
		t->text.tex_x = t->text.img_ea.w - t->text.tex_x - 1;
		t->text.s = (double)t->text.img_ea.h / l.lineheight;
	}
	if (side == 2)
	{
		t->text.tex_x = (int)(t->text.wall_x * (double)t->text.img_so.w);
		t->text.tex_x = t->text.img_so.w - t->text.tex_x - 1;
		t->text.s = (double)t->text.img_so.h / l.lineheight;
	}
	if (side == 3)
	{
		t->text.tex_x = (int)(t->text.wall_x * (double)t->text.img_no.w);
		t->text.tex_x = t->text.img_no.w - t->text.tex_x - 1;
		t->text.s = (double)t->text.img_no.h / l.lineheight;
	}
	if (side == 4)
	{
		t->text.tex_x = (int)(t->text.wall_x * (double)t->text.img_we.w);
		t->text.tex_x = t->text.img_we.w - t->text.tex_x - 1;
		t->text.s = (double)t->text.img_we.h / l.lineheight;
	}
	t->text.tex_p = t->text.s * (l.drawstart - (t->height - l.lineheight) / 2);
}

void		raycasting(t_map_settings *tmp)
{
	t_ray		ray;
	t_line		line;
	double		dist[tmp->width];
	int			x;

	x = -1;
	while (++x < tmp->width)
	{
		ray_u1(tmp, &ray, x);
		ray_u2(tmp, &ray);
		ray_u3(tmp, &ray);
		ray_u4(tmp, &ray, &line);
		dist[x] = ray.perpwalldist;
		textur(tmp, line, ray.side);
		ver_line(tmp, x, line, ray.side);
	}
	sprite(tmp, dist);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img, 0, 0);
}
