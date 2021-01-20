/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_skip_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:51:10 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/20 13:01:09 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

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
	str = ft_strtrim(line, " ");
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
	int		empty_line;

	flag = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (((empty_line = skip_empty_line(line)) && flag))
			flag = 2;
		if (flag == 2 && !empty_line)
			error_control("error input");
		if (empty_line == 0)
		{
			flag = 1;
			checkline_map(line, w, h);
		}
		free(line);
	}
	error_system(errno);
	if ((empty_line = skip_empty_line(line)) == 0)
		checkline_map(line, w, h);
	free(line);
}
