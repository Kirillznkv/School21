/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:46:49 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/30 18:32:23 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = (char*)s;
	n = n > ft_strlen(str) ? ft_strlen(str) : n;
	while (n)
		*(str++) = c;
	return (str);
}
