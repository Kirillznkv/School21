/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_skip_s_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:47:55 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/20 13:41:49 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

int			set_r(char *str, t_map_settings *tmp)
{
	int		i;
	int		a;

	i = -1;
	if (tmp->width != -1)
		return (0);
	while (++i < 2)
	{
		while (*str == ' ')
			str++;
		if (!(ft_isdigit(*str)))
			return (0);
		a = ft_atoi(str);
		if (a <= 0)
			return (0);
		while (ft_isdigit(*str))
			str++;
		if (i == 0)
			tmp->width = a;
		else
			tmp->height = a;
	}
	if (*str)
		return (0);
	return (1);
}

void		f_set_color(t_color *color, int i, int a)
{
	if (i == 0)
		color->r = a;
	else if (i == 1)
		color->g = a;
	else
		color->b = a;
}

int			set_color(char *str, t_color *color)
{
	int		i;
	int		a;

	i = -1;
	if (color->r != -1)
		return (0);
	while (++i < 3)
	{
		a = ft_atoi(str);
		if (a < 0 || a > 255)
			return (0);
		while (*str == ' ')
			str++;
		while (ft_isdigit(*str) || (*str == ' ' && !ft_isdigit((*str + 1))))
			str++;
		f_set_color(color, i, a);
		if (*str == ',' && i < 2)
			str++;
		else if (i < 2)
			return (0);
	}
	if (*str)
		return (0);
	return (1);
}

int			set_path(char *str, char **image)
{
	if (*image != NULL)
		return (0);
	while (*str == ' ')
		str++;
	if (ft_strchr(str, ' '))
		return (0);
	*image = ft_strdup(str);
	error_system(errno);
	return (1);
}
