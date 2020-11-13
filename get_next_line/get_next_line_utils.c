/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:26:17 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/13 18:45:37 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

size_t		ft_strlen(const char *str)
{
	size_t		res;

	res = 0;
	while (str[res])
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

char		*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = -1;
	str = (char*)malloc(ft_strlen((char*)s) + 1);
	if (str)
	{
		while (s[++i])
			str[i] = s[i];
		str[ft_strlen((char*)s)] = '\0';
	}
	return (str);
}

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

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str)
	{
		str[0] = '\0';
		str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
		ft_strlcat(str, s1, ft_strlen(s1) + 1);
		ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	}
	return (str);
}
