/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:14:54 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/11 18:15:31 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "get_next_line.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;
	size_t		i;
	size_t		j;

	i = ft_strlen(dst);
	j = 0;
	len = i + ft_strlen(src);
	if (size <= i)
		return (ft_strlen(src) + size);
	while (i < (size - 1) && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (len);
}

int			maybe_line(char **st_buff, char **line)
{
	char	*st;
	char	*newline;

	if (!st_buff)
		return (0);
	st = *st_buff;
	if (st && (newline = ft_strchr(st, '\n')))
	{
		*newline = '\0';
		*line = ft_strdup(st);
		*(newline++) = '\n';
		newline = ft_substr(newline, 0, -1);
		if (!newline)
			return (-1);
		free(st);
		st_buff = &newline;
		return (1);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*st_buff;
	int			size_read;
	int			ret;

	if (fd < 0)
		return (-2);
	buff = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (-3);
	size_read = BUFFER_SIZE;
	ret = 1;
	line = NULL;
	//if (st_buff && (ret = maybe_line(&st_buff, line)))
	//	return (ret);
	while (!(st_buff && (ret = maybe_line(&st_buff, line))))
	{
		if (ret == -1)
			return (-4);
		if (size_read != BUFFER_SIZE)
		{
			*line = ft_strdup(st_buff);
			if (*line == NULL)
				return (-5);
			free(st_buff);
			free(buff);
			return (0);
		}
		size_read = read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = '\0';
		if (!st_buff)
			st_buff = ft_strdup("");
		st_buff = ft_strjoin(&st_buff, &buff);
		printf("&&&&&%s&&&&&&", st_buff);
		if (!st_buff)
			return (-6);
	}
	return (1);
}
