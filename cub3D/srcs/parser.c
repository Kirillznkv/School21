/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:49:26 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/25 01:37:43 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

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
	error_system(errno);
}

void				f_fill_map(char **map, char *line, int i)
{
	int				j;

	j = -1;
	while (line[++j])
		map[i][j] = line[j];
}

void				fill_map(char *filename, t_map_settings *tmp, int h)
{
	int				fd;
	int				i;
	int				flag;
	char			*line;

	flag = 1;
	if ((fd = open(filename, O_RDONLY)) == -1)
		error_system(errno);
	skip_settings_for_map(fd);
	i = 0;
	while (get_next_line(fd, &line) == 1 && (i < h))
	{
		if (skip_empty_line(line) && flag)
		{
			free(line);
			continue ;
		}
		flag = 0;
		if (skip_empty_line(line) != 2)
			f_fill_map(tmp->map, line, i++);
		free(line);
	}
	error_system(errno);
	if (skip_empty_line(line) == 0)
		f_fill_map(tmp->map, line, i);
	free(line);
	close(fd);
}

t_map_settings		*parser(char *filename, int *w, int *h)
{
	int				fd;
	int				i;
	t_map_settings	*tmp;

	i = -1;
	tmp = (t_map_settings*)malloc(sizeof(t_map_settings));
	error_system(errno);
	if ((fd = open(filename, O_RDONLY)) == -1)
		error_system(errno);
	skip_settings(fd, tmp);
	skip_map(fd, w, h);
	close(fd);
	tmp->map = (char**)malloc(sizeof(char*) * (*h));
	error_system(errno);
	while (++i < *h)
		if ((tmp->map[i] = (char*)malloc(sizeof(char) * (*w + 1))) == NULL)
			error_system(errno);
	spase_in_map(tmp, *w, *h);
	fill_map(filename, tmp, *h);
	check_map(tmp, *h);
	print_map2d(tmp);
	return (tmp);
}
