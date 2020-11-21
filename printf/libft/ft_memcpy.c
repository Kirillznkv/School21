/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:27:40 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/01 16:05:11 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = -1;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if (!n || str1 == str2)
		return (str1);
	while (++i < n)
		str1[i] = str2[i];
	return (str1);
}
