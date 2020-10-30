/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:53:25 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/30 18:34:23 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char*)s1;
	str2 = (char*)s2;
	n = n > ft_strlen(str2) ? ft_strlen(str2) : n;
	n = n > ft_strlen(str1) ? ft_strlen(str1) : n;
	while (i < n && str1[i] == str2[i])
		i++;
	if (i != n)
		return (str1[i] - str2[i]);
	return (0);
}
