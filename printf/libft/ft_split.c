/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:12:41 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/10 17:01:13 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		size_split(const char *s, char c)
{
	size_t	res;

	res = 0;
	if (s == NULL)
		return (res);
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			res++;
		s++;
	}
	return (res);
}

size_t		str_len_n(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char		**del_split(char **map, int i)
{
	if (map == NULL)
		return (NULL);
	while (--i)
		free(map[i]);
	free(map);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	size_map;
	size_t	size_line;
	char	**map;

	size_map = size_split(s, c);
	if (s == NULL ||
	(map = (char**)malloc((size_map + 1) * sizeof(char*))) == NULL)
		return (NULL);
	map[size_map] = NULL;
	i = 0;
	while (size_map--)
	{
		while (*s == c)
			s++;
		size_line = str_len_n(s, c);
		if ((map[i] = (char*)ft_calloc((size_line + 1), sizeof(char))) == NULL)
			return (del_split(map, i));
		ft_strlcpy(map[i++], s, size_line + 1);
		while (*s && *s != c)
			s++;
	}
	return (map);
}
