/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 03:48:48 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/05 12:51:53 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

void		sprt_screen(t_map_settings *tmp, t_sprite_arr sp[], int i)
{
	tmp->sp.x = sp[i].x - tmp->plr.pos.x;
	tmp->sp.y = sp[i].y - tmp->plr.pos.y;
	tmp->sp.inv = 1.0 / (tmp->planex * tmp->plr.dir.y -
					tmp->plr.dir.x * tmp->planey);
	tmp->sp.transx = tmp->sp.inv * (tmp->plr.dir.y * tmp->sp.x -
					tmp->plr.dir.x * tmp->sp.y);
	tmp->sp.transy = tmp->sp.inv * (tmp->planex * tmp->sp.y -
					tmp->planey * tmp->sp.x);
	tmp->sp.sp_screenx = (int)(tmp->width - tmp->width / 2 *
					(1 + tmp->sp.transx / tmp->sp.transy));
}

void		sprt_h_w(t_map_settings *tmp)
{
	tmp->sp.sp_hight = abs((int)(tmp->height / tmp->sp.transy));
	tmp->sp.sp_width = abs((int)(tmp->width / tmp->sp.transy));
	tmp->sp.start_y = tmp->height / 2 - tmp->sp.sp_hight / 2;
	tmp->sp.end_y = tmp->height / 2 + tmp->sp.sp_hight / 2;
	tmp->sp.start_x = tmp->sp.sp_screenx - tmp->sp.sp_width / 2;
	tmp->sp.end_x = tmp->sp.sp_screenx + tmp->sp.sp_width / 2;
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
		tmp->sp.tex_x = (int)((tmp->sp.stripe + tmp->sp.sp_width / 2 -
					tmp->sp.sp_screenx) * tmp->text.img_s.w / tmp->sp.sp_width);
		if (tmp->sp.transy > 0 && tmp->sp.transy < dist[tmp->sp.stripe])
		{
			tmp->sp.y = tmp->sp.start_y;
			while (tmp->sp.y < tmp->sp.end_y)
			{
				tmp->sp.tex_y = 128 * (tmp->sp.y * 2 - tmp->height +
				tmp->sp.sp_hight) * tmp->text.img_s.h / tmp->sp.sp_hight / 256;
				clr = color_s(tmp, tmp->sp.tex_x, tmp->sp.tex_y);
				if (clr)
					my_mlx_pixel_put(&tmp->img, tmp->sp.stripe, tmp->sp.y, clr);
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
		sprites[i].dist = (pow((tmp->plr.pos.x - sprites[i].x), 2) +
							pow((tmp->plr.pos.y - sprites[i].y), 2));
	sort_sprite(sprites, col_sprite(tmp));
	i = -1;
	while (++i < col_sprite(tmp))
	{
		sprt_screen(tmp, sprites, i);
		sprt_h_w(tmp);
		draw_sprt(tmp, dist);
	}
}
