/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:49:10 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/01 19:59:11 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrstr(const char *big, const char *little)
{
	size_t		i;
	size_t		j;

	i = ft_strlen(big);
	if (!(*little))
		return ((char*)big);
	while (i >= 0)
	{
		j = 0;
		while (big[i + j] && little[j] && big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char*)&big[i]);
		i--;
	}
	return (NULL);
}
