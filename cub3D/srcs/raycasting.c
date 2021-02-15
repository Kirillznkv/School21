/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:08:13 by kshanti           #+#    #+#             */
/*   Updated: 2021/02/12 18:18:22 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

void		raycasting(t_map_settings *tmp)
{
	t_ray		ray;
	int			x;

	ray.planeX = 0;/////////////
	ray.planeY = 0.66;//////////
	ray.mapX = tmp->plr.pos.x;
	ray.mapY = tmp->plr.pos.y;
	ray.hit = 0;
	x = -1;
	while (++x < tmp->w)
	{
		ray.cameraX = 2 * x / (double)tmp->w - 1;
		ray.rayDirX = tmp->plr.dir.x + ray.planeX * ray.cameraX;
		ray.rayDirY = tmp->plr.dir.y + ray.planeY * ray.cameraX;
		ray.deltaDistX = abs(1 / ray.rayDirX);
		ray.deltaDistY = abs(1 / ray.rayDirY);
		if (ray.rayDirX <0)
		{
			ray.stepX = -1;
			ray.sideDistX = (tmp->plr.pos.x - ray.mapX) * ray.deltaDistX;
		}
		else
		{
			ray.stepX = 1;
			ray.sideDistX = (tmp->plr.pos.x + 1.0 - ray.mapX) * ray.deltaDistX;
		}
		if (ray.rayDirY <0)
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
			if (tmp->map[ray.mapX] [ray.mapY] > 0)
				ray.hit = 1;
		}
	}
}