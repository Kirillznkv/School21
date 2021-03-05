/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:02:29 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/05 12:02:57 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

int			col_sprite(t_map_settings *tmp)
{
	int		i;
	int		j;
	int		res;

	res = 0;
	j = -1;
	while (++j < tmp->h)
	{
		i = -1;
		while (++i < tmp->w)
			if (tmp->map[j][i] == '2')
				res++;
	}
	return (res);
}

void		cast_sprite_arr(t_sprite_arr sp[], t_map_settings *tmp)
{
	int		i_sp;
	int		x;
	int		y;

	y = -1;
	i_sp = -1;
	while (++y < tmp->h)
	{
		x = -1;
		while (++x < tmp->w)
			if (tmp->map[y][x] == '2')
			{
				sp[++i_sp].x = x + 0.5;
				sp[i_sp].y = y + 0.5;
			}
	}
}

void		swap_sprt(t_sprite_arr *a, t_sprite_arr *b)
{
	t_sprite_arr	c;

	c = *a;
	*a = *b;
	*b = c;
}

void		sort_sprite(t_sprite_arr sp[], int n)
{
	int		i;
	int		j;

	i = -1;
	while (++i < n)
	{
		j = n;
		while (--j > i)
			if (sp[j - 1].dist < sp[j].dist)
				swap_sprt(&sp[j], &sp[j - 1]);
	}
}
