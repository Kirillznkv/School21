/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:29:03 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/29 18:28:16 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long			ft_atoi(const char* str)//пропустить невидимые, переполнение
{
	unsigned long long		res;
	unsigned int			i;
	char					m;

	m = 0;
	i = 0;
	res = 0;
	while (str[i] < 33)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		m++;
		i++;
	}
	while (i < ft_strlen(str) && str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	return m ? -res:res;
}
