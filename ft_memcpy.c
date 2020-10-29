/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:27:40 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/29 19:33:58 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void*		ft_memcpy(void* s1, const void* s2, size_t n)
{
	int		i;
	char*	str1;
	char*	str2;

	i = -1;
	str1 = (char*)s1;
	str2 = (char*)s2;
	if (n > ft_strlen(s2))
		n = ft_strlen(s2);
	if (n > ft_strlen(s1))
		n = ft_strlen(s1);
	while (++i < n)
		str1[i] = str2[i];
	return str1; 
}
