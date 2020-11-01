/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:49:10 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/01 17:00:36 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!(*little) || len == 0)
		return ((char*)big);
	while (big[i] && (i < len))
	{
		j = 0;
		while (i + j < len && little[j] && big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char*)&big[i]);
		i++;
	}
	return (NULL);
}
