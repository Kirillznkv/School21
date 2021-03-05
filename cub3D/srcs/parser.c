/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:49:26 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/05 12:48:28 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

void				skip_settings_for_map(int fd)
{
	int				column;
	int				check_gnl;
	char			*line;

	column = 0;
	while (column < 8 && (check_gnl = get_next_line(fd, &line)) == 1)
	{
		while (*line == ' ')
			line++;
		if (*line)
			column++;
		free(line);
	}
	if (check_gnl == -1)
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
	int				check_gnl;
	char			*line;

	flag = 1;
	if ((fd = open(filename, O_RDONLY)) == -1)
		error_system(errno);
	skip_settings_for_map(fd);
	i = 0;
	while ((check_gnl = get_next_line(fd, &line)) == 1 && (i < h))
	{
		if (ffm(&line, &flag))
			continue ;
		flag = 0;
		if (skip_empty_line(line) != 2)
			f_fill_map(tmp->map, line, i++);
		free(line);
	}
	fsm4(&check_gnl);
	if (skip_empty_line(line) == 0)
		f_fill_map(tmp->map, line, i);
	free(line);
	close(fd);
}

t_map_settings		*parser(char *filename)
{
	int				fd;
	int				i;
	t_map_settings	*tmp;

	i = -1;
	if ((tmp = (t_map_settings*)malloc(sizeof(t_map_settings))) == NULL)
		error_system(errno);
	if ((fd = open(filename, O_RDONLY)) == -1)
		error_system(errno);
	tmp->w = 0;
	tmp->h = 0;
	skip_settings(fd, tmp);
	skip_map(fd, &tmp->w, &tmp->h);
	close(fd);
	if ((tmp->map = (char**)malloc(sizeof(char*) * (tmp->h + 1))) == NULL)
		error_system(errno);
	while (++i < tmp->h)
		if ((tmp->map[i] = (char*)malloc(sizeof(char) * (tmp->w + 1))) == NULL)
			error_system(errno);
	spase_in_map(tmp, tmp->w, tmp->h);
	fill_map(filename, tmp, tmp->h);
	check_map(tmp, tmp->h);
	return (tmp);
}
