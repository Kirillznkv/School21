/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:13:40 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/12 20:19:34 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubheader.h"

int			main(int argc, char **argv)
{
	t_map_settings	*tmp;

	tmp = parser("firstmap.cub");
	printf("R %d %d\n", tmp->width, tmp->height);
	printf("F %d, %d, %d\n", tmp->color_f.r, tmp->color_f.g, tmp->color_f.b);
	printf("C %d, %d, %d\n", tmp->color_c.r, tmp->color_c.g, tmp->color_c.b);
	printf("SO %s\n", tmp->images.south);
	printf("NO %s\n", tmp->images.north);
	printf("WE %s\n", tmp->images.west);
	printf("EA %s\n", tmp->images.east);
	printf("S %s\n", tmp->images.sprite);
	return (0);
}