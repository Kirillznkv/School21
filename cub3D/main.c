/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:13:40 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/05 09:27:25 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubheader.h"
#include "stdio.h"///

void				init_images(t_map_settings	*tmp)
{
	if (!(tmp->text.img_ea.img = mlx_xpm_file_to_image(tmp->mlx, tmp->images.east, &(tmp->text.img_ea.w), &(tmp->text.img_ea.h))))
		error_system(errno);
	tmp->text.img_ea.addr = mlx_get_data_addr(tmp->text.img_ea.img, &(tmp->text.img_ea.bits_per_pixel), &(tmp->text.img_ea.line_length), &(tmp->text.img_ea.endian));

	if (!(tmp->text.img_no.img = mlx_xpm_file_to_image(tmp->mlx, tmp->images.north, &(tmp->text.img_no.w), &(tmp->text.img_no.h))))
		error_system(errno);
	tmp->text.img_no.addr = mlx_get_data_addr(tmp->text.img_no.img, &(tmp->text.img_no.bits_per_pixel), &(tmp->text.img_no.line_length), &(tmp->text.img_no.endian));

	if (!(tmp->text.img_s.img = mlx_xpm_file_to_image(tmp->mlx, tmp->images.sprite, &(tmp->text.img_s.w), &(tmp->text.img_s.h))))
		error_system(errno);
	tmp->text.img_s.addr = mlx_get_data_addr(tmp->text.img_s.img, &(tmp->text.img_s.bits_per_pixel), &(tmp->text.img_s.line_length), &(tmp->text.img_s.endian));

	if (!(tmp->text.img_so.img = mlx_xpm_file_to_image(tmp->mlx, tmp->images.south, &(tmp->text.img_so.w), &(tmp->text.img_so.h))))
		error_system(errno);
	tmp->text.img_so.addr = mlx_get_data_addr(tmp->text.img_so.img, &(tmp->text.img_so.bits_per_pixel), &(tmp->text.img_so.line_length), &(tmp->text.img_so.endian));

	if (!(tmp->text.img_we.img = mlx_xpm_file_to_image(tmp->mlx, tmp->images.west, &(tmp->text.img_we.w), &(tmp->text.img_we.h))))
		error_system(errno);
	tmp->text.img_we.addr = mlx_get_data_addr(tmp->text.img_we.img, &(tmp->text.img_we.bits_per_pixel), &(tmp->text.img_we.line_length), &(tmp->text.img_we.endian));
}

void				file(char *filename)
{
	int		i;

	while (*filename != '\0' && *filename != '.')
		filename++;
	if (*filename == '\0')
		error_control("Неверное название файла");
	i = 0;
	filename++;
	while (*filename != '\0')
	{
		if (i == 0 && *filename == 'c')
			i++;
		else if (i == 1 && *filename == 'u')
			i++;
		else if (i == 2 && *filename == 'b')
			i++;
		else
			error_control("Неверное название файла");
		filename++;
	}
}

t_map_settings		*cub_init(char *filename, int scr)
{
	t_map_settings	*tmp;

	file(filename);
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
	init_images(tmp);
	raycasting(tmp);
	if (scr)
		screen(tmp);
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
		exit(1);
	if (key == 13)//W 13
	{
		if (ft_strchr("0WESN", tmp->map[(int)tmp->plr.pos.y][(int)(tmp->plr.pos.x + tmp->plr.dir.x * 0.1)]))
			tmp->plr.pos.x += tmp->plr.dir.x * 0.1;
		if (ft_strchr("0WESN", tmp->map[(int)(tmp->plr.pos.y + tmp->plr.dir.y * 0.1)][(int)tmp->plr.pos.x]))
			tmp->plr.pos.y += tmp->plr.dir.y * 0.1;
		raycasting(tmp);
	}
	else if (key == 0)//A
	{
		if (ft_strchr("0WESN", tmp->map[(int)tmp->plr.pos.y][(int)(tmp->plr.pos.x + tmp->planeX * 0.1)]))
			tmp->plr.pos.x += tmp->planeX * 0.1;
		if (ft_strchr("0WESN", tmp->map[(int)(tmp->plr.pos.y + tmp->planeY * 0.1)][(int)tmp->plr.pos.x]))
			tmp->plr.pos.y += tmp->planeY * 0.1;
		raycasting(tmp);
	}
	else if (key == 1)//S
	{
		if (ft_strchr("0WESN", tmp->map[(int)tmp->plr.pos.y][(int)(tmp->plr.pos.x - tmp->plr.dir.x * 0.1)]))
			tmp->plr.pos.x -= tmp->plr.dir.x * 0.1;
		if (ft_strchr("0WESN", tmp->map[(int)(tmp->plr.pos.y - tmp->plr.dir.y * 0.1)][(int)tmp->plr.pos.x]))
			tmp->plr.pos.y -= tmp->plr.dir.y * 0.1;
		raycasting(tmp);
	}
	else if (key == 2)//D
	{
		if (ft_strchr("0WESN", tmp->map[(int)tmp->plr.pos.y][(int)(tmp->plr.pos.x - tmp->planeX * 0.1)]))
			tmp->plr.pos.x -= tmp->planeX * 0.1;
		if (ft_strchr("0WESN", tmp->map[(int)(tmp->plr.pos.y - tmp->planeY * 0.1)][(int)tmp->plr.pos.x]))
			tmp->plr.pos.y -= tmp->planeY * 0.1;
		raycasting(tmp);
	}
	else if (key == 123)//  <-
	{
		double old;
		old = tmp->plr.dir.x;
		tmp->plr.dir.x = tmp->plr.dir.x * cos(-0.05) - tmp->plr.dir.y * sin(-0.05);
		tmp->plr.dir.y = old * sin(-0.05) + tmp->plr.dir.y * cos(-0.05);
		old = tmp->planeX;
		tmp->planeX = tmp->planeX * cos(-0.05) - tmp->planeY * sin(-0.05);
		tmp->planeY = old * sin(-0.05) + tmp->planeY * cos(-0.05);
		raycasting(tmp);
	}
	else if (key == 124)//  ->
	{
		double old;
		old = tmp->plr.dir.x;
		tmp->plr.dir.x = tmp->plr.dir.x * cos(0.05) - tmp->plr.dir.y * sin(0.05);
		tmp->plr.dir.y = old * sin(0.05) + tmp->plr.dir.y * cos(0.05);
		old = tmp->planeX;
		tmp->planeX = tmp->planeX * cos(0.05) - tmp->planeY * sin(0.05);
		tmp->planeY = old * sin(0.05) + tmp->planeY * cos(0.05);
		raycasting(tmp);
	}
	return (0);
}

int					main(int argc, char **argv)
{
	t_map_settings	*tmp;
	int				scr;

	scr = 0;
	if (argc == 2 || argc == 3)
	{
		if (argc == 3)
		{
			if (ft_strncmp("--save", argv[2], 6) || ft_strlen(argv[2]) != 6)
				error_control("Неверный второй аргумент");
			scr++;
		}
		tmp = cub_init(argv[1], scr);
		mlx_hook(tmp->win, 2, 0, keybord_manager, tmp);
		mlx_hook(tmp->win, 17, 0, my_exit, NULL);
		mlx_loop(tmp->mlx);
		free(tmp);
	}
	error_control("Неверное количество параметров программы");
	return (0);
}