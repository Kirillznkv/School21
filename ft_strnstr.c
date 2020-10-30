/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:49:10 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/30 19:31:39 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	char		*s1;
	char		*s2;
	size_t		len_s1;
	size_t		i;
	size_t		j;

	i = 0;
	s1 = (char*)big;
	s2 = (char*)little;
	len_s1 = ft_strlen(s1);
	if (ft_strlen(s2) > len_s1)
		return (NULL);
	len = len_s1 < len ? len_s1 : len;
	while (i + ft_strlen(s2) <= len)
	{
		j = 0;
		while (j < ft_strlen(s2) && s1[i + j] == s2[j])
			j++;
		if (j == ft_strlen(s2))
			return (&s1[i]);
		i++;
	}
	return (NULL);
}
