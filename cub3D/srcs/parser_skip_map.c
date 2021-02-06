/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_skip_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:51:10 by kshanti           #+#    #+#             */
/*   Updated: 2021/02/06 19:49:46 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

t_sprite				*lstnew(int i, int j)
{
	t_sprite	*tmp;

	if ((tmp = (t_sprite*)malloc(sizeof(t_sprite))) == NULL)
		error_system(errno);
	tmp->next = NULL;
	tmp->y = i;
	tmp->x = j;
	return (tmp);
}

void					addlst(t_map_settings *tmp, int i, int j)
{
	t_sprite	*first;

	if (!(tmp->sp))
	{
		tmp->sp = lstnew(i, j);
		return ;
	}
	first = tmp->sp;
	while (first->next)
		first = first->next;
	first->next = lstnew(i, j);
}

void					checkline_map(char *line, int *w, int *h)
{
	int			this_w;

	this_w = ft_strlen(line);
	if (!(*h) || (*w < this_w))
		*w = this_w;
	(*h)++;
}

int						skip_empty_line(char *line)
{
	char	*str;
	int		res;

	if (*line == '\0')
		return (2);
	if ((str = ft_strtrim(line, " ")) == NULL)
		error_system(errno);
	if (*str)
		res = 0;
	else
		res = 1;
	free(str);
	return (res);
}

void					skip_map(int fd, int *w, int *h)
{
	char	*line;
	int		flag;
	int		end;
	int		empty_line;
	int		check_gnl;

	flag = 0;
	end = 0;
	while ((check_gnl = get_next_line(fd, &line)) == 1)
	{
		if (((empty_line = skip_empty_line(line)) == 2 && flag))
			flag = 2;
		if (flag == 2 && !empty_line)
			error_control("end line inside map");
		if (empty_line == 0)
		{
			end = 0;
			flag = 1;
			checkline_map(line, w, h);
		}
		else if (empty_line == 1 && flag)
		{
			end++;
			(*h)++;
		}
		free(line);
	}
	if (check_gnl == -1)
		error_system(errno);
	if ((empty_line = skip_empty_line(line)) == 0)
		checkline_map(line, w, h);
	(*h) -= end;
	if (*h == 0)
		error_control("map was not found");
	free(line);
}
