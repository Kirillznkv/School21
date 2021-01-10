/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:14:54 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/15 19:52:24 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ps;

	i = 0;
	ps = (char *)s;
	while (ps[i] != c && ps[i])
		i++;
	if (ps[i] != c)
		return (NULL);
	return (&ps[i]);
}

int			maybe_line(char **static_buff, char **line)
{
	char	*p_endline;
	char	*str;

	str = *static_buff;
	if (str)
	{
		if ((p_endline = ft_strchr(str, '\n')))
		{
			*p_endline = '\0';
			*line = ft_strdup(str);
			if (!(*line))
				return (-1);
			*p_endline = '\n';
			p_endline++;
			*static_buff = ft_strdup(p_endline);
			if (!(*static_buff))
				return (-1);
			free(str);
			return (1);
		}
	}
	return (0);
}

int			add_to_static(int fd, int *size_buff, char *buff, char **st_buff)
{
	char	*p_for_st_buff;

	*size_buff = read(fd, buff, BUFFER_SIZE);
	if (buff && *size_buff)
	{
		buff[*size_buff] = '\0';
		p_for_st_buff = *st_buff;
		*st_buff = ft_strjoin(p_for_st_buff, buff);
		free(p_for_st_buff);
	}
	if (!buff)
		return (-1);
	return (1);
}

char		*return_last_line_and_free(char **st_buff)
{
	char	*line;

	if (**st_buff)
		line = ft_strdup(*st_buff);
	else
		line = ft_strdup("");
	free(*st_buff);
	*st_buff = NULL;
	return (line);
}

int			get_next_line(int fd, char **line)
{
	static char	*st_buff;
	char		*buff;
	int			size_buff;
	int			res;

	if (!(buff = (char*)malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (line == NULL || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
	{
		free(buff);
		return (-1);
	}
	if (!st_buff)
		st_buff = ft_strdup("");
	*line = NULL;
	size_buff = BUFFER_SIZE;
	while (size_buff && !(res = maybe_line(&st_buff, line)))
		res = add_to_static(fd, &size_buff, buff, &st_buff);
	if (!size_buff && res != -1)
	{
		*line = return_last_line_and_free(&st_buff);
		res = 0;
	}
	free(buff);
	return (res);
}
