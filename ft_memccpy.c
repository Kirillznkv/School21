/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:03:17 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/29 21:19:13 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void*		ft_memccpy(void* s1, const void* s2, int c, size_t n)
{
	int		i;
	char*	str1;
	char*	str2;

	i = -1;
	str1 = (char*)s1;
	str2 = (char*)s2;
	while (++i < n && str2[i] != c)
		str1[i] = str2[i];
	if (str2[i] == c)
		str1[i] = str2[i];
	return str1;
}