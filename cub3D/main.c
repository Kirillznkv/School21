/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:13:40 by kshanti           #+#    #+#             */
/*   Updated: 2021/02/25 02:50:10 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubheader.h"
#include "stdio.h"///

t_map_settings		*cub_init(char *filename)
{
	t_map_settings	*tmp;

	tmp = parser(filename);
	if (tmp->width > 2560)
		tmp->width = 2560;
	if (tmp->height > 1390)
		tmp->height = 1390;
	tmp->mlx = mlx_init();
	tmp->win = mlx_new_window(tmp->mlx, tmp->width, tmp->height, "MyCub3D");
	tmp->img.img = mlx_new_image(tmp->mlx, tmp->width, tmp->height);
	tmp->img.addr = mlx_get_data_addr(tmp->img.img,
		&tmp->img.bits_per_pixel, &tmp->img.line_length,
		&tmp->img.endian);
	tmp->planeX = 0;////////////
	tmp->planeY = 0.66;/////////
	raycasting(tmp);
	return (tmp);
}

int				my_exit(int key)
{
	exit(1);
	return (1);
}

int				keybord_manager(int key, t_map_settings *tmp)
{
	if (key == 53)//esc
	{
		tmp->images.west[0] = ' ';
		raycasting(tmp);
	}
		//exit(1);
	if (key == 13)//W 13
	{
		tmp->plr.pos.x -= 0.1;
		raycasting(tmp);
	}
	else if (key == 0)//A
	{
		tmp->plr.pos.y += 0.1;
		raycasting(tmp);
	}
	else if (key == 1)//S
	{
		tmp->plr.pos.x += 0.1;
		raycasting(tmp);
	}
	else if (key == 2)//D
	{
		tmp->plr.pos.y -= 0.1;
		raycasting(tmp);
	}
	else if (key == 123)//  <-
	{
		double old;
		old = tmp->plr.dir.x;
		tmp->plr.dir.x = tmp->plr.dir.x * cos(-0.05) - tmp->plr.dir.y * sin(-0.05);
		tmp->plr.dir.y = old * sin(-0.05) + old * cos(-0.05);
		old = tmp->planeX;
		tmp->planeX = tmp->planeX * cos(-0.05) - tmp->planeY * sin(-0.05);
		tmp->planeY = old * sin(-0.05) + old * cos(-0.05);
		raycasting(tmp);
	}
	else if (key == 124)//  ->
	{
		double old;
		old = tmp->plr.dir.x;
		tmp->plr.dir.x = tmp->plr.dir.x * cos(0.05) - tmp->plr.dir.y * sin(0.05);
		tmp->plr.dir.y = old * sin(0.05) + old * cos(0.05);
		old = tmp->planeX;
		tmp->planeX = tmp->planeX * cos(0.05) - tmp->planeY * sin(0.05);
		tmp->planeY = old * sin(0.05) + old * cos(0.05);
		raycasting(tmp);
	}
	return (0);
}

int					main(int argc, char **argv)
{
	t_map_settings	*tmp;

	tmp = cub_init("map.cub");
	mlx_hook(tmp->win, 2, 0, keybord_manager, tmp);
	mlx_hook(tmp->win, 17, 0, my_exit, NULL);
	mlx_loop(tmp->mlx);
	free(tmp);
	return (1);
}