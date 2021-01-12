/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_v1.0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:49:26 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/12 20:30:59 by kshanti          ###   ########.fr       */
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
		return (0);/////////////////////////////////проверить
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
		else
			color->g = a;
		while (*str == ' ' && i < 2)
			str++;
		if (*str == ',' && i < 2)
			str++;
	}
	if (*str)
		return (0);/////////////////////////////////проверить
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
		return (0);///error_malloc but in input error
	return (1);
}

int			is_settings(char *str, t_map_settings *tmp)
{
	int		res;
	char	*pointer;
	char	*del_pointer;
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

int			checkline(char *line, t_map_settings *tmp)
{
	int		column;
	int		res;
	char	*str;

	column = 0;
	if ((str = ft_strtrim(line, " ")) == NULL)
		return (-1);//error_malloc
	if (ft_isalpha(*str))
	{
		if (is_settings(str, tmp))//написать
			column++;
		else
		{
			free(str);
			return (-1);//error_input
		}
	}
	else if (*line == '\0')
		;
	else if (column != 8)
		return (-1);//error_input
	free(str);
	return (1);
}

int					skip_settings(int fd, t_map_settings *tmp)
{
	int		res;
	char	*line;

	res = 1;
	tmp->color_c.r = -1;
	tmp->color_f.r = -1;
	tmp->width = -1;
	tmp->images.east = NULL;
	tmp->images.north = NULL;
	tmp->images.south = NULL;
	tmp->images.sprite = NULL;
	tmp->images.west = NULL;
	while (res == 1 && (res = get_next_line(fd, &line)) == 1)
	{
		res = checkline(line, tmp);
		free(line);
	}
	if (!res)
	{
		res = checkline(line, tmp);
		free(line);
	}
	return (res);
}

t_map_settings		*parser(char *filename)//, int *spases, int *w, int *h)
{
	int				res;
	int				fd;
	t_map_settings	*tmp;

	if ((tmp = (t_map_settings*)malloc(sizeof(t_map_settings))) == NULL)
		return (tmp);//return_error_code
	fd = open(filename, O_RDONLY);
	res = skip_settings(fd, tmp);
	//res = skip_map(fd, spases, w, h);
	close(fd);
	return (tmp);
}