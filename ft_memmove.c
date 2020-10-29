/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:51:03 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/29 19:35:00 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void*		ft_memmove(void* s1, const void* s2, size_t  n)
{
	int		i;
	int		h;
	char*	str1;
	char*	str2;

	str1 = (char*)s1;
	str2 = (char*)s2;
	i = 0;
	h = 1;
	if (n > ft_strlen(s2))
		n = ft_strlen(s2);
	if (n > ft_strlen(s1))
		n = ft_strlen(s1);
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
	return str1;
}
