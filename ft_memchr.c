/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:11:15 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/29 19:32:09 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void*		memchr(const void *s, int c, size_t n)
{
	int i;
	char*	str;

	i = 0;
	str = (char*)s;
	if (n > ft_strlen(s))
		n = ft_strlen(s);
	while (n-- && s[i] != c)
		i++;
	return str;
}