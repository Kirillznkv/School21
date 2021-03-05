/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:54:40 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/05 12:48:13 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

void				ckeck_contour(char **tmp, int h)
{
	int				i;
	int				j;

	i = -1;
	while (++i < h)
	{
		j = -1;
		if (tmp[i][0] != '1' && tmp[i][0] != ' ')
			error_control("map error");
		while (tmp[i][++j])
		{
			if ((i == 0 || (i == h - 1))
				&& (tmp[i][0] != '1' && tmp[i][0] != ' '))
				error_control("map error");
			if (!ft_strchr("WSNE 012", tmp[i][j]))
				error_control("invalid character");
		}
		if (tmp[i][j - 1] != '1' && tmp[i][j - 1] != ' ')
			error_control("map error");
	}
	i = -1;
	while (tmp[h - 1][++i])
		if (tmp[h - 1][i] != ' ' && tmp[h - 1][i] != '1')
			error_control("map error");
}

int					check_zero(char **tmp, int i, int j)
{
	if (tmp[i][j + 1] == ' ')
		return (1);
	if (tmp[i][j - 1] == ' ')
		return (1);
	if (tmp[i + 1][j] == ' ')
		return (1);
	if (tmp[i - 1][j] == ' ')
		return (1);
	return (0);
}

void				add_plr2(t_map_settings *tmp, int i, int j)
{
	if (tmp->map[i][j] == 'E')
	{
		tmp->planex = 0;
		tmp->planey = -0.66;
		tmp->plr.dir.x = 1;
		tmp->plr.dir.y = 0;
	}
	else if (tmp->map[i][j] == 'S')
	{
		tmp->planex = 0.66;
		tmp->planey = 0;
		tmp->plr.dir.x = 0;
		tmp->plr.dir.y = 1;
	}
	tmp->plr.pos.y = i + 0.001;
	tmp->plr.pos.x = j + 0.001;
}

void				add_plr(t_map_settings *tmp, int i, int j)
{
	if (tmp->plr.dir.x != -100)
		error_control("repeating player in map");
	if (tmp->map[i][j] == 'W')
	{
		tmp->planex = 0;
		tmp->planey = 0.66;
		tmp->plr.dir.x = -1;
		tmp->plr.dir.y = 0;
	}
	else if (tmp->map[i][j] == 'N')
	{
		tmp->planex = -0.66;
		tmp->planey = 0;
		tmp->plr.dir.x = 0;
		tmp->plr.dir.y = -1;
	}
	add_plr2(tmp, i, j);
}

void				check_map(t_map_settings *tmp, int h)
{
	int				i;
	int				j;

	i = 0;
	ckeck_contour(tmp->map, h);
	while (++i < h - 1)
	{
		j = 0;
		while (tmp->map[i][++j + 1])
			if ((tmp->map[i][j] == '0' || tmp->map[i][j] == '2') &&
				check_zero(tmp->map, i, j))
				error_control("0 or 2 is not surrounded by a wall");
			else if (ft_strchr("WSNE", tmp->map[i][j]))
			{
				if (check_zero(tmp->map, i, j))
					error_control("player is not surrounded by a wall");
				add_plr(tmp, i, j);
			}
	}
	if (tmp->plr.dir.x == -100)
		error_control("player dont found");
	tmp->color_c.color = (tmp->color_c.r << 16) + (tmp->color_c.g << 8)
						+ tmp->color_c.b;
	tmp->color_f.color = (tmp->color_f.r << 16) + (tmp->color_f.g << 8)
						+ tmp->color_f.b;
}
