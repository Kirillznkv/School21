/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:19:25 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/01 16:55:02 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = -1;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (++i < n)
	{
		str1[i] = str2[i];
		if (str2[i] == (unsigned char)c)
			return (&str1[++i]);
	}
	return (NULL);
}
