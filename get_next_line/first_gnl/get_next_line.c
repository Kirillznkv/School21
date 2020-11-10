/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:14:54 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/10 21:51:01 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = -1;
	str = (char*)ft_calloc((ft_strlen((char*)s) + 1), sizeof(char));
	while (str && s[++i])
		str[i] = s[i];
	return (str);
}

size_t		maybe_nextline(char *st_buff)
{
	char	*str;

	str = st_buff;
	while (*str && *str != '\n')
		str++;
	if (*str)
		return (1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	int			size_read;
	char		*buff;
	static char	*st_buff;

	*line = NULL;
	if (fd < 0)
		return (-1);
	if (!st_buff)
		st_buff = (char*)ft_calloc(1, sizeof(char));
	buff = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff || !st_buff)
		return (-1);
	size_read = read(fd, buff, BUFFER_SIZE);
	st_buff = ft_strjoin_for_gnl(st_buff, buff);
	if (!st_buff)
		return (-1);
	while (!maybe_nextline(st_buff) && size_read)
	{
		size_read = read(fd, buff, BUFFER_SIZE);
		st_buff = ft_strjoin_for_gnl(st_buff, buff);
		if (!st_buff)
			return (-1);
	}
	if (!maybe_nextline(st_buff))
	{
		*line = ft_strdup(st_buff);
		free(st_buff);
		return (0);
	}
	else
	{
		buff = st_buff;
		while (*buff != '\n')
			buff++;
		*(buff++) = '\0';
		*line = ft_strdup(st_buff);
		*(buff++) = '\n';
		buff = ft_strdup(buff);
		free(st_buff);
		st_buff = buff;
		return (1);
	}
}
