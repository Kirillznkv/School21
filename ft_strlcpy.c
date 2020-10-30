/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:28:13 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/30 16:42:10 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		i;
	int		end;
	char*	str;

	i = 0;
	str = (char*)src;
	end = (int)(ft_strlen(str) > ft_strlen(dst));
	while(--size)
	{
		dst[i] = str[i];
		i++;
	}
	if (end)
		dst[i] = '\0';
	return ft_strlen(dst);
}
