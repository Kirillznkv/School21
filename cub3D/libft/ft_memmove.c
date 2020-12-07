/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:51:03 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/01 16:24:58 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *s1, const void *s2, size_t n)
{
	int				i;
	int				h;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	h = 1;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if (n == 0 || str1 == str2)
		return (str1);
	if (str2 < str1)
	{
		i = n - 1;
		h = -1;
	}
	while (n--)
	{
		str1[i] = str2[i];
		i += h;
	}
	return (str1);
}
