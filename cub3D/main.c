/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:13:40 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/30 04:13:18 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubheader.h"

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
	print_map2d(tmp);
	return (tmp);
}

void				my_exit(int key_press)
{
	exit(1);
}

int					main(int argc, char **argv)
{
	t_map_settings	*tmp;

	tmp = cub_init("map.cub");
	//mlx_hook(tmp->win, 2, 0, keybord_manager, tmp);
	mlx_hook(tmp->win, 17, 0, my_exit, NULL);
	mlx_loop(tmp->mlx);
	free(tmp);
	return (1);
}
    //написать проверку открытия файлов

	// // если указывается огромный размер экрана то все подводится под дисплэй а save делается по этому формату