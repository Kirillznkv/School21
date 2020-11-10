/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:26:17 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/10 19:52:12 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *str)
{
	size_t		res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}

void			ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char*)s;
	while (n-- > 0)
		str[n] = '\0';
}

void			*ft_calloc(size_t n, size_t size)
{
	unsigned char	*s;

	if (n * size < 0)
		return (NULL);
	s = (unsigned char*)malloc(n * size);
	if (s != NULL)
		ft_bzero(s, n * size);
	return (void*)s;
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
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

char			*ft_strjoin_for_gnl(char *s1, char *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char*)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (str)
	{
		ft_strlcat(str, s1, ft_strlen(s1) + 1);
		ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	}
	free(s1);
	free(s2);
	return (str);
}
