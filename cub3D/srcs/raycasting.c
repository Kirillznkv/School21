/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:08:13 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/05 08:14:59 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"
#include "stdio.h"////

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		ver_line(t_map_settings *tmp, int x, t_line line, int side)
{
	int		color;
	int		i;

	i = -1;
	while (++i < line.drawStart)
		my_mlx_pixel_put(&tmp->img, x, i, tmp->color_c.color);
	while (line.drawStart <= line.drawEnd)
	{
		if (side == 1)//ea
			tmp->text.tex_y = (int)tmp->text.tex_pos & (tmp->text.img_ea.h - 1);
		else if (side == 2)//so
			tmp->text.tex_y = (int)tmp->text.tex_pos & (tmp->text.img_so.h - 1);
		else if (side == 3)//no
			tmp->text.tex_y = (int)tmp->text.tex_pos & (tmp->text.img_no.h - 1);
		else if (side == 4)//we
			tmp->text.tex_y = (int)tmp->text.tex_pos & (tmp->text.img_we.h - 1);
		tmp->text.tex_pos += tmp->text.step;
		if (side == 1)//ea
			color = color_ea(tmp, tmp->text.tex_x, tmp->text.tex_y);
		else if (side == 2)//so
			color = color_so(tmp, tmp->text.tex_x, tmp->text.tex_y);
		else if (side == 3)//no
			color = color_no(tmp, tmp->text.tex_x, tmp->text.tex_y);
		else if (side == 4)//we
			color = color_we(tmp, tmp->text.tex_x, tmp->text.tex_y);
		my_mlx_pixel_put(&tmp->img, x, line.drawStart++, color);
	}
	i = line.drawEnd;
	while (++i < tmp->height)
		my_mlx_pixel_put(&tmp->img, x, i, tmp->color_f.color);
}

void		textur(t_map_settings *tmp, t_line line, int side)
{//////////////////////////////////////////////////////////////////////////////     Поменять стороны
	if (side == 1)
	{
		tmp->text.tex_x = (int)(tmp->text.wall_x * (double)tmp->text.img_ea.w);
		tmp->text.tex_x = tmp->text.img_ea.w - tmp->text.tex_x - 1;
		tmp->text.step = (double)tmp->text.img_ea.h / line.lineHeight;
	}
	if (side == 2)
	{
		tmp->text.tex_x = (int)(tmp->text.wall_x * (double)tmp->text.img_so.w);
		tmp->text.tex_x = tmp->text.img_so.w - tmp->text.tex_x - 1;
		tmp->text.step = (double)tmp->text.img_so.h / line.lineHeight;
	}
	if (side == 3)
	{
		tmp->text.tex_x = (int)(tmp->text.wall_x * (double)tmp->text.img_no.w);
		tmp->text.tex_x = tmp->text.img_no.w - tmp->text.tex_x - 1;
		tmp->text.step = (double)tmp->text.img_no.h / line.lineHeight;
	}
	if (side == 4)
	{
		tmp->text.tex_x = (int)(tmp->text.wall_x * (double)tmp->text.img_we.w);
		tmp->text.tex_x = tmp->text.img_we.w - tmp->text.tex_x - 1;
		tmp->text.step = (double)tmp->text.img_we.h / line.lineHeight;
	}
	tmp->text.tex_pos = tmp->text.step * (line.drawStart - tmp->height / 2 + line.lineHeight / 2);
}

void		raycasting(t_map_settings *tmp)
{
	t_ray		ray;
	t_line		line;
	double		dist[tmp->width];
	int			x;

	x = -1;
	// black_display(tmp);
	while (++x < tmp->width)
	{
		ray.mapX = (int)tmp->plr.pos.x;////
		ray.mapY = (int)tmp->plr.pos.y;////
		ray.cameraX = (2 - 2 * x / (double)tmp->width) - 1;
		ray.rayDirX = tmp->plr.dir.x + tmp->planeX * ray.cameraX;
		ray.rayDirY = tmp->plr.dir.y + tmp->planeY * ray.cameraX;
		ray.hit = 0;
		ray.deltaDistX = (ray.rayDirY == 0) ? 0 : ((ray.rayDirX == 0) ? 1 : fabs(1 / ray.rayDirX));
		ray.deltaDistY = (ray.rayDirX == 0) ? 0 : ((ray.rayDirY == 0) ? 1 : fabs(1 / ray.rayDirY));
		if (ray.rayDirX < 0)
		{
			ray.stepX = -1;
			ray.sideDistX = (tmp->plr.pos.x - ray.mapX) * ray.deltaDistX;
		}
		else
		{
			ray.stepX = 1;
			ray.sideDistX = (ray.mapX - tmp->plr.pos.x + 1.0) * ray.deltaDistX;
		}
		if (ray.rayDirY < 0)
		{
			ray.stepY = -1;
			ray.sideDistY = (tmp->plr.pos.y - ray.mapY) * ray.deltaDistY;
		}
		else
		{
			ray.stepY = 1;
			ray.sideDistY = (ray.mapY - tmp->plr.pos.y + 1.0) * ray.deltaDistY;
		}
		while (ray.hit == 0)
		{
			if (ray.sideDistX <= ray.sideDistY)
			{
				ray.sideDistX += ray.deltaDistX;
				ray.mapX += ray.stepX;
				if (tmp->plr.pos.x > ray.mapX)
					ray.side = 1;
				else
					ray.side = 2;
			}
			else
			{
				ray.sideDistY += ray.deltaDistY;
				ray.mapY += ray.stepY;
				if (tmp->plr.pos.y > ray.mapY)
					ray.side = 3;
				else
					ray.side = 4;
			}
			if (!ft_strchr("02NEWS", tmp->map[ray.mapY][ray.mapX]))
				ray.hit = 1;
		}
		if (ray.side < 3)
		{
			ray.perpWallDist = (ray.mapX - tmp->plr.pos.x + (1 - ray.stepX) / 2) / ray.rayDirX;
			tmp->text.wall_x = tmp->plr.pos.y + ray.perpWallDist * ray.rayDirY;
		}
		else
		{
			ray.perpWallDist = (ray.mapY - tmp->plr.pos.y + (1 - ray.stepY) / 2) / ray.rayDirY;
			tmp->text.wall_x = tmp->plr.pos.x + ray.perpWallDist * ray.rayDirX;
		}
		tmp->text.wall_x -= floor(tmp->text.wall_x);
		line.lineHeight = tmp->height / ray.perpWallDist;
		line.drawStart = (tmp->height / 2) - (line.lineHeight / 2);
		line.drawEnd = (tmp->height / 2) + (line.lineHeight / 2);
		if (line.drawStart < 0)
				line.drawStart = 0;
		if (line.drawEnd >= tmp->height)
			line.drawEnd = tmp->height - 1;
		dist[x] = ray.perpWallDist;
		textur(tmp, line, ray.side);
		ver_line(tmp, x, line, ray.side);
	}
	sprite(tmp, dist);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img, 0, 0);
}