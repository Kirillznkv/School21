/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:08:13 by kshanti           #+#    #+#             */
/*   Updated: 2021/02/27 16:26:36 by kshanti          ###   ########.fr       */
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

	if (side == 1)
		color = 0xDE5D83;
	else if (side == 2)
		color = 0x199EBD;
	else if (side == 3)
		color = 0x33FF33;
	else if (side == 4)
		color = 0xCCFF33;
	while (line.drawStart <= line.drawEnd)
		my_mlx_pixel_put(&(tmp->img.img), x, line.drawStart++, color);
}

void		black_display(t_map_settings *tmp)
{
	int		i;
	int		j;

	i = -1;
	while (++i < tmp->width)
	{
		j = -1;
		while (++j < tmp->height)
			my_mlx_pixel_put(&(tmp->img.img), i, j, 0x000000);
	}
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img, 0, 0);
}

void		raycasting(t_map_settings *tmp)
{
	t_ray		ray;
	t_line		line;
	int			x;

	x = -1;
	black_display(tmp);
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
			ray.perpWallDist = (ray.mapX - tmp->plr.pos.x + (1 - ray.stepX) / 2) / ray.rayDirX;
		else
			ray.perpWallDist = (ray.mapY - tmp->plr.pos.y + (1 - ray.stepY) / 2) / ray.rayDirY;
		line.lineHeight = tmp->height / ray.perpWallDist;
		line.drawStart = (tmp->height / 2) - (line.lineHeight / 2);
		line.drawEnd = (tmp->height / 2) + (line.lineHeight / 2);
		if (line.drawStart < 0)
				line.drawStart = 0;
		if (line.drawEnd >= tmp->height)
			line.drawEnd = tmp->height - 1;
		ver_line(tmp, x, line, ray.side);
	}
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img, 0, 0);
}