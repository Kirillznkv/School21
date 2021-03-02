/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:24:02 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/02 21:37:03 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

int		color_no(t_map_settings *tmp, int x, int y)
{
	int		res;

	x = abs(x);
	y = abs(y);
	res = 0;
	if (!tmp->text.img_no.h || !tmp->text.img_no.w)
		return (0);
	if (x > tmp->text.img_no.w || y > tmp->text.img_no.h)
		return (0);
	res = (*(int*)(tmp->text.img_no.addr + ((x + (y * tmp->text.img_no.w)) * (tmp->text.img_no.bits_per_pixel / 8))));
	return (res);
}

int		color_ea(t_map_settings *tmp, int x, int y)
{
	int		res;

	x = abs(x);
	y = abs(y);
	res = 0;
	if (!tmp->text.img_ea.h || !tmp->text.img_ea.w)
		return (0);
	if (x > tmp->text.img_ea.w || y > tmp->text.img_ea.h)
		return (0);
	res = (*(int*)(tmp->text.img_ea.addr + ((x + (y * tmp->text.img_ea.w)) * (tmp->text.img_ea.bits_per_pixel / 8))));
	return (res);
}

int		color_so(t_map_settings *tmp, int x, int y)
{
	int		res;

	x = abs(x);
	y = abs(y);
	res = 0;
	if (!tmp->text.img_so.h || !tmp->text.img_so.w)
		return (0);
	if (x > tmp->text.img_so.w || y > tmp->text.img_so.h)
		return (0);
	res = (*(int*)(tmp->text.img_so.addr + ((x + (y * tmp->text.img_so.w)) * (tmp->text.img_so.bits_per_pixel / 8))));
	return (res);
}

int		color_s(t_map_settings *tmp, int x, int y)
{
	int		res;

	x = abs(x);
	y = abs(y);
	res = 0;
	if (!tmp->text.img_s.h || !tmp->text.img_s.w)
		return (0);
	if (x > tmp->text.img_s.w || y > tmp->text.img_s.h)
		return (0);
	res = (*(int*)(tmp->text.img_s.addr + ((x + (y * tmp->text.img_s.w)) * (tmp->text.img_s.bits_per_pixel / 8))));
	return (res);
}

int		color_we(t_map_settings *tmp, int x, int y)
{
	int		res;

	x = abs(x);
	y = abs(y);
	res = 0;
	if (!tmp->text.img_we.h || !tmp->text.img_we.w)
		return (0);
	if (x > tmp->text.img_we.w || y > tmp->text.img_we.h)
		return (0);
	res = (*(int*)(tmp->text.img_we.addr + ((x + (y * tmp->text.img_we.w)) * (tmp->text.img_we.bits_per_pixel / 8))));
	return (res);
}