/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:35:37 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/05 12:50:10 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

void		ray_u1(t_map_settings *tmp, t_ray *ray, int x)
{
	ray->mapx = (int)tmp->plr.pos.x;
	ray->mapy = (int)tmp->plr.pos.y;
	ray->camerax = (2 - 2 * x / (double)tmp->width) - 1;
	ray->raydirx = tmp->plr.dir.x + tmp->planex * ray->camerax;
	ray->raydiry = tmp->plr.dir.y + tmp->planey * ray->camerax;
	ray->hit = 0;
	if (ray->raydiry == 0)
		ray->deltadistx = 0;
	else if (ray->raydirx == 0)
		ray->deltadistx = 1;
	else
		ray->deltadistx = fabs(1 / ray->raydirx);
	if (ray->raydirx == 0)
		ray->deltadisty = 0;
	else if (ray->raydiry == 0)
		ray->deltadisty = 1;
	else
		ray->deltadisty = fabs(1 / ray->raydiry);
}

void		ray_u2(t_map_settings *tmp, t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (tmp->plr.pos.x - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx - tmp->plr.pos.x + 1.0) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (tmp->plr.pos.y - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy - tmp->plr.pos.y + 1.0) * ray->deltadisty;
	}
}

void		ray_u3(t_map_settings *tmp, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx <= ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			if (tmp->plr.pos.x > ray->mapx)
				ray->side = 1;
			else
				ray->side = 2;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			if (tmp->plr.pos.y > ray->mapy)
				ray->side = 3;
			else
				ray->side = 4;
		}
		if (!ft_strchr("02NEWS", tmp->map[ray->mapy][ray->mapx]))
			ray->hit = 1;
	}
}

void		ray_u4(t_map_settings *tmp, t_ray *ray, t_line *line)
{
	if (ray->side < 3)
	{
		ray->perpwalldist = (ray->mapx - tmp->plr.pos.x + (1 - ray->stepx)
							/ 2) / ray->raydirx;
		tmp->text.wall_x = tmp->plr.pos.y + ray->perpwalldist * ray->raydiry;
	}
	else
	{
		ray->perpwalldist = (ray->mapy - tmp->plr.pos.y + (1 - ray->stepy)
							/ 2) / ray->raydiry;
		tmp->text.wall_x = tmp->plr.pos.x + ray->perpwalldist * ray->raydirx;
	}
	tmp->text.wall_x -= floor(tmp->text.wall_x);
	line->lineheight = tmp->height / ray->perpwalldist;
	line->drawstart = (tmp->height / 2) - (line->lineheight / 2);
	line->drawend = (tmp->height / 2) + (line->lineheight / 2);
	if (line->drawstart < 0)
		line->drawstart = 0;
	if (line->drawend >= tmp->height)
		line->drawend = tmp->height - 1;
}
