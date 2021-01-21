/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:13:40 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/22 01:15:14 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubheader.h"

int			main(int argc, char **argv)
{
	t_map_settings	*tmp;
	int				w;
	int				h;

	if (argc == 1 || argv[0][0] == '9')
		;
	h = 0;
	w = 0;
	tmp = parser("firstmap.cub", &w, &h);
	printf("R %d %d\n", tmp->width, tmp->height);
	printf("F %d, %d, %d\n", tmp->color_f.r, tmp->color_f.g, tmp->color_f.b);
	printf("C %d, %d, %d\n", tmp->color_c.r, tmp->color_c.g, tmp->color_c.b);
	printf("SO %s\n", tmp->images.south);
	printf("NO %s\n", tmp->images.north);
	printf("WE %s\n", tmp->images.west);
	printf("EA %s\n", tmp->images.east);
	printf("S %s\n", tmp->images.sprite);
	printf("\nw = %d\n", w);
	printf("h = %d\n", h);

	printf("\n->>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
			printf("%c", tmp->map[i][j]);
		printf("\n");
	}
	printf("\n->>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("player: %c (%d, %d)\n", tmp->plr.direction, tmp->plr.i, tmp->plr.j);
	printf("Sprite--------\n");
	while (tmp->sp)
	{
		printf("      (%d, %d)\n", tmp->sp->i, tmp->sp->j);
		tmp->sp = tmp->sp->next;
	}
	return (0);
}
    //игрок, спрайты вне карты
    //двойная карта
    //спрайн на стене
    //атой защита