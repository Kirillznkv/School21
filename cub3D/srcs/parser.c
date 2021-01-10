/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:39:35 by kshanti           #+#    #+#             */
/*   Updated: 2020/12/13 19:48:30 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubheader.h"

int			ft_column_settings(int fd)
{
	int		k;
	char	*delstr;
	char	*str;

	k = 0;
	while (k < 8 && get_next_line(fd, &str) != -1)
	{
		delstr = str;
		if ((str = ft_strtrim(str, " ")) == NULL)
		{
			free(delstr);
			return (-1);
		}
		free(delstr);
		if (ft_isalpha(*str))
			k++;
		else if (*str)
		{
			free(str);
			return (-1);
		}
		free(str);
	}
	if (k != 8)
		return (-1);
	return (k);
}

int			linework(char *str, int *len, int *spases)
{
	char	*delstr;

	*spases = 0;
	while (*str == ' ' && str++)
		(*spases)++;
	if ((str = ft_strtrim(str, ' ')) == NULL)
		return (-1);
	*len = ft_strlen(str);
	if (!ft_isdigit(*str))
	{
		free(str);
		return (-1);
	}
	free(str);
	return (1);
}

int			parsing_map(int fd, int *spases, int *w, int *h)
{
	char	*str;
	char	*delstr;
	int		len;
	int		width;

	while (get_next_line(fd, &str) == 1)
	{
		delstr = str;
		if ((str = ft_strtrim(str, ' ')) == NULL)
		{
			free(delstr);
			return (-1);
		}
		if (*str)
		{
			free(str);
			str = delstr;
			break ;
		}
		free(delstr);
		free(str);
	}
}

int			predparser(char *filename,int *spases, int *w, int *h)
{
	int		fd;
	int		column_settings;
	char	*str;

	fd = open(filename, O_RDONLY);
	if ((column_settings = ft_column_settings(fd)) == -1)
	{
		close(fd);
		return (-1);
	}
	column_settings = parsing_map(fd, spases, w, h);
}