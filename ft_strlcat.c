/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:41:34 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/31 14:59:20 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned char	*str;

	str = (unsigned char*)src;
	i = ft_strlen(dst);
	j = 0;
	size -= i;
	while (--size && src[j] != '\0')
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (ft_strlen(dst));
}
