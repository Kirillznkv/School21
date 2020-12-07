/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:30:56 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/01 14:54:22 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_calloc(size_t n, size_t size)
{
	unsigned char	*s;

	if (n * size < 0)
		return (NULL);
	s = (unsigned char*)malloc(n * size);
	if (s != NULL)
		ft_bzero(s, n * size);
	return (void*)s;
}
