/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:13:40 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/05 12:52:30 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubheader.h"

int					my_exit(int key)
{
	exit(1);
	return (1);
}

void				keybord2(int key, t_map_settings *tmp)
{
	if (key == 1)
	{
		if (ft_strchr("0WESN", tmp->map[(int)tmp->plr.pos.y]
			[(int)(tmp->plr.pos.x - tmp->plr.dir.x * 0.1)]))
			tmp->plr.pos.x -= tmp->plr.dir.x * 0.1;
		if (ft_strchr("0WESN", tmp->map[(int)(tmp->plr.pos.y -
			tmp->plr.dir.y * 0.1)][(int)tmp->plr.pos.x]))
			tmp->plr.pos.y -= tmp->plr.dir.y * 0.1;
		raycasting(tmp);
	}
	else if (key == 2)
	{
		if (ft_strchr("0WESN", tmp->map[(int)tmp->plr.pos.y]
			[(int)(tmp->plr.pos.x - tmp->planex * 0.1)]))
			tmp->plr.pos.x -= tmp->planex * 0.1;
		if (ft_strchr("0WESN", tmp->map[(int)(tmp->plr.pos.y -
			tmp->planey * 0.1)][(int)tmp->plr.pos.x]))
			tmp->plr.pos.y -= tmp->planey * 0.1;
		raycasting(tmp);
	}
}

void				keybord3(int key, t_map_settings *tmp)
{
	double			old;

	if (key == 123)
	{
		old = tmp->plr.dir.x;
		tmp->plr.dir.x = tmp->plr.dir.x * cos(-0.05) -
							tmp->plr.dir.y * sin(-0.05);
		tmp->plr.dir.y = old * sin(-0.05) +
							tmp->plr.dir.y * cos(-0.05);
		old = tmp->planex;
		tmp->planex = tmp->planex * cos(-0.05) - tmp->planey * sin(-0.05);
		tmp->planey = old * sin(-0.05) + tmp->planey * cos(-0.05);
		raycasting(tmp);
	}
	else if (key == 124)
	{
		old = tmp->plr.dir.x;
		tmp->plr.dir.x = tmp->plr.dir.x * cos(0.05) -
							tmp->plr.dir.y * sin(0.05);
		tmp->plr.dir.y = old * sin(0.05) + tmp->plr.dir.y * cos(0.05);
		old = tmp->planex;
		tmp->planex = tmp->planex * cos(0.05) - tmp->planey * sin(0.05);
		tmp->planey = old * sin(0.05) + tmp->planey * cos(0.05);
		raycasting(tmp);
	}
}

int					keybord_manager(int key, t_map_settings *tmp)
{
	if (key == 53)
		exit(1);
	if (key == 13)
	{
		if (ft_strchr("0WESN", tmp->map[(int)tmp->plr.pos.y]
			[(int)(tmp->plr.pos.x + tmp->plr.dir.x * 0.1)]))
			tmp->plr.pos.x += tmp->plr.dir.x * 0.1;
		if (ft_strchr("0WESN", tmp->map[(int)(tmp->plr.pos.y +
			tmp->plr.dir.y * 0.1)][(int)tmp->plr.pos.x]))
			tmp->plr.pos.y += tmp->plr.dir.y * 0.1;
		raycasting(tmp);
	}
	else if (key == 0)
	{
		if (ft_strchr("0WESN", tmp->map[(int)tmp->plr.pos.y]
			[(int)(tmp->plr.pos.x + tmp->planex * 0.1)]))
			tmp->plr.pos.x += tmp->planex * 0.1;
		if (ft_strchr("0WESN", tmp->map[(int)(tmp->plr.pos.y +
			tmp->planey * 0.1)][(int)tmp->plr.pos.x]))
			tmp->plr.pos.y += tmp->planey * 0.1;
		raycasting(tmp);
	}
	keybord2(key, tmp);
	keybord3(key, tmp);
	return (0);
}

int					main(int argc, char **argv)
{
	t_map_settings	*tmp;
	int				scr;

	scr = 0;
	if (argc == 2 || argc == 3)
	{
		if (argc == 3)
		{
			if (ft_strncmp("--save", argv[2], 6) || ft_strlen(argv[2]) != 6)
				error_control("Неверный второй аргумент");
			scr++;
		}
		tmp = cub_init(argv[1], scr);
		mlx_hook(tmp->win, 2, 0, keybord_manager, tmp);
		mlx_hook(tmp->win, 17, 0, my_exit, NULL);
		mlx_loop(tmp->mlx);
		free(tmp);
	}
	error_control("Неверное количество параметров программы");
	return (0);
}
