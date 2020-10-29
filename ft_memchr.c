/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:11:15 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/29 21:19:17 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void*		ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char*	str;

	i = 0;
	str = (char*)s;
	if (n > ft_strlen(str))
		n = ft_strlen(str);
	while (n-- && s[i] != c)
		i++;
	return str;
}