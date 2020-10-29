/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:46:49 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/29 19:36:04 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void*		ft_memset(void* s, int c, size_t n)//Возврат не с начала
{
	char*	str;

	str = (char*)s;
	if (n > ft_strlen(s))
		n = ft_strlen(s);
	while (n)
		*(str++) = c;
	return str;
}
