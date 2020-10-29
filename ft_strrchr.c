/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:48:52 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/29 18:23:08 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char*		ft_strrchr(const char* s, int c)
{
	int		i;
	char*	ps;

	ps = (char *)s;
	i = ft_strlen(ps) - 1;
	while (i >= 0 && ps[i] != c)
		i--;
	return &ps[i];
}
