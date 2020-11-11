/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:26:17 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/11 18:00:48 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "get_next_line.h"

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

char		*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = -1;
	str = (char*)malloc(ft_strlen((char*)s) + 1);
	while (str && s[++i])
		str[i] = s[i];
	str[ft_strlen((char*)s) + 1] = '\0';
	return (str);
}

size_t		ft_strlen(const char *str)
{
	size_t		res;

	res = 0;
	while (str && str[res])
		res++;
	return (res);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char*)malloc(len + 1);
	if (str && start <= ft_strlen(s))
	{
		while (s[start] && i < len)
			str[i++] = s[start++];
		str[len] = '\0';
	}
	return (str);
}

char		*ft_strjoin(char **s1, char **s2)
{
	char	*str;

	str = (char*)malloc(ft_strlen(*s1) + ft_strlen(*s2) + 1);
	if (str)
	{
		ft_strlcat(str, *s1, ft_strlen(*s1) + 1);
		ft_strlcat(str, *s2, ft_strlen(*s1) + ft_strlen(*s2) + 1);
		str[ft_strlen(*s1) + ft_strlen(*s2)] = '\0';
	}
	free(*s1);
	free(*s2);
	return (str);
}
