/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:46:31 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/29 20:01:41 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		len1;
	int		len2;
	char*	str1;
	char*	str2;

	str1 = (char*)s1;
	str2 = (char*)s2;
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (n > len2)
		n = len2;
	if (n > len1)
		n = len1;
	return ft_sttrncmp(str1, str2, n);
}
