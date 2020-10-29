/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:27:40 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/29 19:50:33 by kshanti          ###   ########.fr       */
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
	if (n > ft_strlen(str2))
		n = ft_strlen(str2);
	if (n > ft_strlen(str1))
		n = ft_strlen(str1);
	while (++i < n)
		str1[i] = str2[i];
	return str1; 
}
