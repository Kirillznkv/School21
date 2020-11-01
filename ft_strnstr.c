/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:49:10 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/01 15:31:21 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	char		*s1;
	char		*s2;
	size_t		i;
	size_t		j;

	i = 0;
	s1 = (char*)big;
	s2 = (char*)little;
	if (!(*s2))
		return (s1);
	while (s1[i] && (i + ft_strlen(s2)) < len)
	{
		j = 0;
		while (s2[j] && s1[i + j] == s2[j])
			j++;
		if (!s2[j])
			return (&s1[i]);
		i++;
	}
	return (NULL);
}
