/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_v1.0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:49:26 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/16 03:03:49 by kshanti          ###   ########.fr       */
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

int			set_color(char *str, t_color *color)
{
	int		i;
	int		a;

	i = -1;
	if (color->r != -1)
		return (0);
	while (++i < 3)
	{
		while (*str == ' ')
			str++;
		if (!(ft_isdigit(*str)))
			return (0);
		a = ft_atoi(str);
		if (a < 0 || a > 255)
			return (0);
		while (ft_isdigit(*str))
			str++;
		if (i == 0)
			color->r = a;
		else if (i == 1)
			color->g = a;
		else
			color->b = a;
		while (*str == ' ' && i < 2)
			str++;
		if (*str == ',' && i < 2)
			str++;
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
	if ((*image = ft_strdup(str)) == NULL)
		error_system(errno);
	return (1);
}

int			is_settings(char *str, t_map_settings *tmp)
{
	int		res;
	char	*pointer;
	char	ch;

	res = 1;
	if (!(pointer = ft_strchr(str, ' ')))
		return (0);
	if (*(pointer + 1) == '\0')
		return (0);
	ch = *(pointer + 1);
	*(pointer + 1) = '\0';
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

	if ((str = ft_strtrim(line, " ")) == NULL)
		error_system(errno);
	if (ft_isalpha(*str))
	{
		if (is_settings(str, tmp))
			(*column)++;
		else
		{
			free(str);
			error_control("error input");
		}
	}
	else if (*line != '\0')
			error_control("error input");
	free(str);
}

void					skip_settings(int fd, t_map_settings *tmp)
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
	if (errno)
		error_system(errno);
}

void					checkline_map(char *line, int *w, int *h)
{
	int		this_w;
	char	*str;

	if ((str = ft_strtrim(line, " ")) == NULL)
		error_system(errno);
	if (*str)
	{
		this_w = ft_strlen(line);
		if (!(*h) || (*w < this_w))
			*w = this_w;
		(*h)++;
	}
	else if (*h)
	{
		free(str);
		error_control("error input");
	}
	free(str);
}

void					skip_map(int fd, int *w, int *h)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		checkline_map(line, w, h);
		free(line);
	}
	if (errno)
		error_system(errno);
	checkline_map(line, w, h);
	free(line);
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
}

void				skip_settings_for_map(int fd)
{
	int				column;
	char			*line;

	column = 0;
	while (column < 8 && get_next_line(fd, &line) == 1)
	{
		while (*line == ' ')
			line++;
		if (*line)
			column++;
		free(line);
	}
	if (errno)
		error_system(errno);
}

void				fill_map(char *filename, t_map_settings *tmp)
{
	int				fd;
	int				i;
	int				j;
	char			*line;

	if ((fd = open(filename, O_RDONLY)) == -1)
		error_system(errno);
	skip_settings_for_map(fd);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		while (line[j] == ' ')
			j++;
		if (line[j] == '\0')
		{
			free(line);
			continue ;
		}
		j = -1;
		while (line[++j])
			tmp->map[i][j] = line[j];
		i++;
		free(line);
	}
	if (errno)
		error_system(errno);
	j = -1;
	while (line[++j])
		tmp->map[i][j] = line[j];
	free(line);
	close(fd);
}

t_map_settings		*parser(char *filename, int *w, int *h)
{
	int				fd;
	int				i;
	t_map_settings	*tmp;

	i = -1;
	if ((tmp = (t_map_settings*)malloc(sizeof(t_map_settings))) == NULL)
		error_system(errno);
	if ((fd = open(filename, O_RDONLY)) == -1)
		error_system(errno);
	skip_settings(fd, tmp);
	skip_map(fd, w, h);
	close(fd);
	if ((tmp->map = (char**)malloc(sizeof(char*) * (*h))) == NULL)
		error_system(errno);
	while (++i < *h)
		if ((tmp->map[i] = (char*)malloc(sizeof(char) * (*w + 1))) == NULL)
			error_system(errno);
	spase_in_map(tmp, *w, *h);
	fill_map(filename, tmp);
	return (tmp);
}