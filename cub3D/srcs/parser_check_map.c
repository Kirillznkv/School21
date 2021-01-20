/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:54:40 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/20 17:37:32 by kshanti          ###   ########.fr       */
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
			error_control("map error1");
		while (tmp[i][++j])
		{
			if ((i == 0 || (i == h - 1))
				&& (tmp[i][0] != '1' && tmp[i][0] != ' '))
				error_control("map error2");
			if (!ft_strchr("WSNE 012", tmp[i][j]))
				error_control("map error3");
		}
		if (tmp[i][j - 1] != '1' && tmp[i][j - 1] != ' ')
			error_control("map error4");
	}
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

void				add_plr(t_map_settings *tmp, int i, int j)
{
	if (tmp->plr.direction != 0)
		error_control("error player in map");
	tmp->plr.direction = tmp->map[i][j];
	tmp->plr.i = i;
	tmp->plr.j = j;
}

void				check_map(t_map_settings *tmp, int h)
{
	int				i;
	int				j;

	i = 0;
	ckeck_contour(tmp->map, h);
	tmp->plr.direction = 0;
	tmp->sp = NULL;
	while (++i < h - 1)
	{
		j = 0;
		while (tmp->map[i][++j + 1])
		{
			if (tmp->map[i][j] == '0' && check_zero(tmp->map, i, j))
				error_control("map_error5");
			else if (tmp->map[i][j] == '2')
				addlst(tmp, i, j);
			else if (ft_strchr("WSNE", tmp->map[i][j]))
				add_plr(tmp, i, j);
		}
	}
}
