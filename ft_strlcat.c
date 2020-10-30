/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:41:34 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/30 18:27:25 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	char	*str;

	str = (char*)src;
	i = ft_strlen(dst);
	size -= i;
	while (--size)
	{
		dst[i++] = *src;
		src++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst));
}
