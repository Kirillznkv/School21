/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:12:41 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/02 23:00:29 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		size_split(const char *s, char c)
{
	size_t	res;

	res = 1;
	while (*s == c)
		s++;
	if (*s == '\0')
		return (0);
	while (*s)
		if (*(s++) == c)
		{
			while (*s == c)
				s++;
			if (*s == '\0')
				res--;
			res++;
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

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	size_map;
	size_t	size_line;
	char	**map;

	if (s == NULL)
		return (NULL);
	size_map = size_split(s, c);
	if ((map = (char**)malloc((size_map + 1) * sizeof(char*))) == NULL)
		return (NULL);
	map[size_map] = NULL;
	i = 0;
	while (size_map--)
	{
		while (*s == c)
			s++;
		size_line = str_len_n(s, c);
		if ((map[i] = (char*)ft_calloc((size_line + 1), sizeof(char))) == NULL)
			return (NULL);
		ft_strlcpy(map[i], s, size_line + 1);
		while (*s != c)
			s++;
		while (*s == c)
			s++;
		i++;
	}
	return (map);
}
