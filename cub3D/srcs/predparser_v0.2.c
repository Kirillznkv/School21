/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predparser_v0.2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 16:16:56 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/10 18:08:24 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

int			is_settings(char *str)
{

	return (1);
}

int			checkline(char *line, int *spases, int *w, int *h)
{
	int		spases_line;
	int		column;
	char	*str;

	column = 0;
	if ((str = ft_strtrim(line, " ")) == NULL)
		return (-1);//error_malloc
	if (ft_isalpha(*str))
	{
		if (is_settings(str))//написать
			column++;
		else if (column != 8)
		{
			free(str);
			return (-1);//error_settings
		}
		else
		{
			free(str);
			return (-1);//error_input
		}
	}
	else if (*line == '\0')
		;
	else if (column != 8)
		return (-1);//error_settings
	else
	{
		while (*(line++) == ' ')//dont pointer chenge?
			spases_line++;
		*w = (*w < ft_strlen(str) + spases_line) ? (ft_strlen(str) + spases_line) : *w;
		if ((spases_line < *spases && h) || !h)
			*spases = spases_line;
		*h++;
	}
	free(str);
	return (1);
}

int			predparser_v2(char *filename, int *spases, int *w, int *h)
{
	int		fd;
	int		res;
	char	*line;

	res = 1;
	fd = open(filename, O_RDONLY);
	while (res == 1 && (res = get_next_line(fd, &line)) == 1)
	{
		res = checkline(line, spases, w, h);
		free(line);
	}
	if (res == 0)
	{
		res = checkline(line, spases, w, h);
		free(line);
	}
	if (res != 1)
	{
		close(fd);
		return (-1);//return_code_error
	}
	close(fd);
}