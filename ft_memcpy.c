/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:27:40 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/30 19:30:21 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*str1;
	char		*str2;

	i = -1;
	str1 = (char*)s1;
	str2 = (char*)s2;
	n = n > ft_strlen(str2) ? ft_strlen(str2) : n;
	n = n > ft_strlen(str1) ? ft_strlen(str1) : n;
	while (++i < n)
		str1[i] = str2[i];
	return (str1);
}
