/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 03:48:48 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/05 07:27:59 by kshanti          ###   ########.fr       */
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

void		sprt_screen(t_map_settings *tmp, t_sprite_arr sp[], int i)
{
	tmp->sp.x = sp[i].x - tmp->plr.pos.x;
	tmp->sp.y = sp[i].y - tmp->plr.pos.y;
	tmp->sp.inv = 1.0 / (tmp->planeX * tmp->plr.dir.y - tmp->plr.dir.x * tmp->planeY);
	tmp->sp.transX = tmp->sp.inv * (tmp->plr.dir.y * tmp->sp.x - tmp->plr.dir.x * tmp->sp.y);
	tmp->sp.transY = tmp->sp.inv * (tmp->planeX * tmp->sp.y - tmp->planeY * tmp->sp.x);
	tmp->sp.sp_screenX = (int)(tmp->width / 2 * (1 + tmp->sp.transX / tmp->sp.transY));
}

void		sprt_h_w(t_map_settings *tmp)
{
	tmp->sp.sp_hight = abs((int)(tmp->height / tmp->sp.transY));
	tmp->sp.sp_width = abs((int)(tmp->width / tmp->sp.transY));
	tmp->sp.start_y = tmp->height / 2 - tmp->sp.sp_hight / 2;
	tmp->sp.end_y = tmp->height / 2 + tmp->sp.sp_hight / 2;
	tmp->sp.start_x = tmp->sp.sp_screenX - tmp->sp.sp_width / 2;
	tmp->sp.end_x = tmp->sp.sp_screenX + tmp->sp.sp_width / 2;
	if (tmp->sp.start_y < 0)
		tmp->sp.start_y = 0;
	if (tmp->sp.start_x < 0)
		tmp->sp.start_x = 0;
	if (tmp->sp.end_y >= tmp->height)
		tmp->sp.end_y = tmp->height - 1;
	if (tmp->sp.end_x >= tmp->width)
		tmp->sp.end_x = tmp->width - 1;
	tmp->sp.stripe = tmp->sp.start_x;
}

void		draw_sprt(t_map_settings *tmp, double dist[])
{
	int		clr;

	while (tmp->sp.stripe < tmp->sp.end_x)
	{
		tmp->sp.tex_x = (int)((tmp->sp.stripe + tmp->sp.sp_width / 2 - tmp->sp.sp_screenX) * tmp->text.img_s.w / tmp->sp.sp_width);
		if (tmp->sp.transY > 0 && tmp->sp.transY < dist[tmp->sp.stripe])
		{
			tmp->sp.y = tmp->sp.start_y;
			while (tmp->sp.y < tmp->sp.end_y)
			{
				// printf("%d  ", (int)tmp->sp.y);
				// printf("%d\n", tmp->sp.end_y);
				tmp->sp.d = 128 * (tmp->sp.y * 2 - tmp->height + tmp->sp.sp_hight);
				tmp->sp.tex_y = tmp->sp.d * tmp->text.img_s.h / tmp->sp.sp_hight / 256;
				clr = color_s(tmp, tmp->sp.tex_x, tmp->sp.tex_y);
				printf("%d %d ---> %d\n", tmp->sp.stripe, (int)tmp->sp.y, clr);
				if (!clr)
					my_mlx_pixel_put(tmp, tmp->sp.stripe, (int)tmp->sp.y, 0);
				tmp->sp.y += 1;
			}
		}
		(tmp->sp.stripe)++;
	}
}

void		sprite(t_map_settings *tmp, double dist[])
{
	t_sprite_arr	sprites[col_sprite(tmp)];
	int				i;

	i = -1;
	cast_sprite_arr(sprites, tmp);
	while (++i < col_sprite(tmp))
		sprites[i].dist = (pow((tmp->plr.pos.x - sprites[i].x), 2) + pow((tmp->plr.pos.y - sprites[i].y), 2));
	sort_sprite(sprites, col_sprite(tmp));
	i = -1;
	while (++i < col_sprite(tmp))
	{
		sprt_screen(tmp, sprites, i);
		sprt_h_w(tmp);
		draw_sprt(tmp, dist);
	}
}