/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:53:25 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/29 20:00:45 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char* s1, const char* s2, size_t n)
{
	int		i;

	i = 0;
	if (n > ft_strlen(s2))
		n = ft_strlen(s2);
	if (n > ft_strlen(s1))
		n = ft_strlen(s1);
	while (i < n && s1[i] == s2[i])
		i++;
	if (i != n)
		return s1[i] - s2[i];
	return 0;
}
