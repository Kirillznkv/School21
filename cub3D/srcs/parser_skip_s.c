/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_skip_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:46:01 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/20 13:55:31 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

int				f_is_settings(char **pointer, char *str, char *ch)
{
	if (!(*pointer = ft_strchr(str, ' ')))
		return (0);
	if (*(*pointer + 1) == '\0')
		return (0);
	*ch = *(*pointer + 1);
	*(*pointer + 1) = '\0';
	return (1);
}

int				is_settings(char *str, t_map_settings *tmp)
{
	int		res;
	char	*pointer;
	char	ch;

	if (!(res = f_is_settings(&pointer, str, &ch)))
		return (0);
	if (!(ft_strncmp(str, "R ", 4)) && (*(pointer + 1) = ch))
		res = set_r(++pointer, tmp);
	else if (!(ft_strncmp(str, "F ", 4)) && (*(pointer + 1) = ch))
		res = set_color(++pointer, &(tmp->color_f));
	else if (!(ft_strncmp(str, "C ", 4)) && (*(pointer + 1) = ch))
		res = set_color(++pointer, &(tmp->color_c));
	else if (!(ft_strncmp(str, "S ", 4)) && (*(pointer + 1) = ch))
		res = set_path(++pointer, &(tmp->images.sprite));
	else if (!(ft_strncmp(str, "NO ", 4)) && (*(pointer + 1) = ch))
		res = set_path(++pointer, &(tmp->images.north));
	else if (!(ft_strncmp(str, "SO ", 4)) && (*(pointer + 1) = ch))
		res = set_path(++pointer, &(tmp->images.south));
	else if (!(ft_strncmp(str, "WE ", 4)) && (*(pointer + 1) = ch))
		res = set_path(++pointer, &(tmp->images.west));
	else if (!(ft_strncmp(str, "EA ", 4)) && (*(pointer + 1) = ch))
		res = set_path(++pointer, &(tmp->images.east));
	else
		return (0);
	return (res);
}

void			checkline(char *line, t_map_settings *tmp, int *column)
{
	char	*str;

	str = ft_strtrim(line, " ");
	error_system(errno);
	if (ft_isalpha(*str))
	{
		if (is_settings(str, tmp))
			(*column)++;
		else
			error_control("error input");
	}
	else if (*line != '\0')
		error_control("error input");
	free(str);
}

void			skip_settings(int fd, t_map_settings *tmp)
{
	int		column;
	char	*line;

	column = 0;
	tmp->color_c.r = -1;
	tmp->color_f.r = -1;
	tmp->width = -1;
	tmp->images.east = NULL;
	tmp->images.north = NULL;
	tmp->images.south = NULL;
	tmp->images.sprite = NULL;
	tmp->images.west = NULL;
	while (column < 8 && get_next_line(fd, &line) == 1)
	{
		checkline(line, tmp, &column);
		free(line);
	}
	if (column != 8)
		error_control("error input");
	error_system(errno);
}
