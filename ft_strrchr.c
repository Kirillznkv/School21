/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:48:52 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/01 14:01:17 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ps;

	if (s == NULL)
		return (NULL);
	ps = (char *)s;
	i = ft_strlen(ps);
	while (i >= 0 && ps[i] != c)
		i--;
	if (i == -1)
		return (NULL);
	return (&ps[i]);
}
