/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:50:04 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/05 11:50:38 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

int					ffm(char **line, int *flag)
{
	int				res;

	res = 0;
	if (skip_empty_line(*line) && *flag)
	{
		free(*line);
		res++;
	}
	return (res);
}

void				spase_in_map(t_map_settings *tmp, int w, int h)
{
	int				i;
	int				j;

	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < w)
			tmp->map[i][j] = ' ';
		tmp->map[i][j] = '\0';
	}
	tmp->plr.dir.x = -100;
}
