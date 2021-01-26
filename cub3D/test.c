/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:24:17 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/26 15:26:43 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "stdio.h"

int		main()
{
	
	void *mlx = NULL;
	void *win = NULL;
	int x = 100;
	int y = 100;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "test");
	while (y++ < 200)
	{
		x = 100;
		while (x++ < 200)
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
	}
	mlx_loop(mlx);
	printf("its work!\n");
	return (0);
}