/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:08:13 by kshanti           #+#    #+#             */
/*   Updated: 2021/02/17 22:30:12 by kshanti          ###   ########.fr       */
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

void		ver_line(t_map_settings *tmp, int x, t_line line, int color)
{
	while (line.drawStart <= line.drawEnd)
		my_mlx_pixel_put(tmp->img.img, x, line.drawStart++, color);
}

void		raycasting(t_map_settings *tmp)
{
	t_ray		ray;
	t_line		line;
	int			x;

	ray.planeX = 0;/////////////
	ray.planeY = 0.66;//////////
	x = -1;
	while (++x < tmp->w)
	{
		ray.mapX = (int)tmp->plr.pos.x;////
		ray.mapY = (int)tmp->plr.pos.y;////
		ray.cameraX = 2 * x / (double)tmp->w - 1;
		ray.rayDirX = tmp->plr.dir.x + ray.planeX * ray.cameraX;
		ray.rayDirY = tmp->plr.dir.y + ray.planeY * ray.cameraX;
		ray.hit = 0;
		ray.deltaDistX = abs(1 / ray.rayDirX);
		ray.deltaDistY = abs(1 / ray.rayDirY);
		if (ray.rayDirX < 0)
		{
			ray.stepX = -1;
			ray.sideDistX = (tmp->plr.pos.x - ray.mapX) * ray.deltaDistX;
		}
		else
		{
			ray.stepX = 1;
			ray.sideDistX = (tmp->plr.pos.x + 1.0 - ray.mapX) * ray.deltaDistX;
		}
		if (ray.rayDirY < 0)
		{
			ray.stepY = -1;
			ray.sideDistY = (tmp->plr.pos.y - ray.mapY) * ray.deltaDistY;
		}
		else
		{
			ray.stepY = 1;
			ray.sideDistY = (tmp->plr.pos.y + 1.0 - ray.mapY) * ray.deltaDistY;
		}
		while (ray.hit == 0)
		{
			if (ray.sideDistX < ray.sideDistY)
			{
				ray.sideDistX += ray.deltaDistX;
				ray.mapX += ray.stepX;
				ray.side = 0;
			}
			else
			{
				ray.sideDistY += ray.deltaDistY;
				ray.mapY += ray.stepY;
				ray.side = 1;
			}
			if (tmp->map[ray.mapY][ray.mapX] != '0')
				ray.hit = 1;
		}
		if (ray.side == 0)
			ray.perpWallDist = (ray.mapX - tmp->plr.pos.x + (1 - ray.stepX) / 2) / ray.rayDirX;
		else
			ray.perpWallDist = (ray.mapY - tmp->plr.pos.y + (1 - ray.stepY) / 2) / ray.rayDirY;
		if (!ray.side)
			printf("mapX = %4d posX = %4lf step = %d dirX = %lf\t------>%lf\n", ray.mapX, tmp->plr.pos.x, ray.stepX, ray.rayDirX, ray.perpWallDist);
		else
			printf("mapY = %4d posY = %4lf step = %d dirY = %lf\t------>%lf\n", ray.mapY, tmp->plr.pos.y, ray.stepY, ray.rayDirY, ray.perpWallDist);
		line.lineHeight = (int)(tmp->height / ray.perpWallDist);
		line.drawStart = (int)((tmp->height / 2) - (line.lineHeight / 2));
		line.drawEnd = (int)((tmp->height / 2) + (line.lineHeight / 2));
		if (line.drawStart < 0)
			line.drawStart = 0;
		if (line.drawEnd >= tmp->height)
			line.drawEnd = tmp->height - 1;
		if (ray.side)
			ver_line(tmp, x, line, 0x808080);
		else
			ver_line(tmp, x, line, 0x808080 / 2);
	}
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img, 0, 0);
}