/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:12:41 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/02 21:15:05 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		size_split(const char *s, char c)
{
	size_t	res;

	res = 1;
	while (*s)
		if (*(s++) == c)
			res++;
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
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char*)s;
	size_map = size_split(str, c);
	if ((map = (char**)malloc((size_map + 1) * sizeof(char*))) == NULL)
		return (NULL);
	map[size_map] = NULL;
	i = 0;
	while (size_map--)
	{
		size_line = str_len_n(str, c);
		map[i] = (char*)malloc((size_line + 1) * sizeof(char));
		ft_strlcpy(map[i], str, size_line + 1);
		str = ft_strchr(str, c);
		i++;
	}
	return (map);
}
