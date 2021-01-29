/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_skip_s_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:47:55 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/30 02:37:31 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

void			set_r(char *str, t_map_settings *tmp)
{
	int		i;
	int		a;

	i = -1;
	if (tmp->width != -1)
		error_control("repeating settings R");
	while (++i < 2)
	{
		while (*str == ' ')
			str++;
		if (!(ft_isdigit(*str)))
			error_control("error input R line");
		a = ft_atoi(str);
		if (a <= 0)
			error_control("a negative number in R");
		while (ft_isdigit(*str))
			str++;
		if (i == 0)
			tmp->width = a;
		else
			tmp->height = a;
	}
	if (*str)
		error_control("symbols after line in R");
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

void			set_color(char *str, t_color *color)
{
	int		i;
	int		a;

	i = -1;
	if (color->r != -1)
		error_control("repeating settings color");
	while (++i < 3)
	{
		a = ft_atoi(str);
		if (a < 0 || a > 255)
			error_control("color numder is not rgb number");
		while (*str == ' ')
			str++;
		while (ft_isdigit(*str) || (*str == ' ' && !ft_isdigit((*str + 1))))
			str++;
		f_set_color(color, i, a);
		if (*str == ',' && i < 2)
			str++;
		else if (i < 2)
			error_control("error input color line");
	}
	if (*str)
		error_control("symbols after line in color");
}

void			set_path(char *str, char **image)
{
	if (*image != NULL)
		error_control("repeating settings path");
	while (*str == ' ')
		str++;
	if (ft_strchr(str, ' '))
		error_control("spases in path");
	if ((*image = ft_strdup(str)) == NULL)
		error_system(errno);
}
