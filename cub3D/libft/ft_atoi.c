/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:29:03 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/22 18:38:04 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "errno.h"

int					ft_atoi(const char *str)
{
	unsigned int	res;
	unsigned int	i;
	char			m;

	m = 0;
	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
		str[i] == '\r' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		m++;
		i++;
	}
	if (!(ft_isdigit(str[i])))
	{
		ft_putstr_fd("error: digit was not found", 1);
		ft_putchar_fd('\n', 1);
		exit(1);
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9' && res < 2147483648)
		res = res * 10 + str[i++] - '0';
	if (res > 2147483648 && m)
		res = 2147483648;
	else if (res > 2147483647 && !m)
		res = 2147483647;
	return (m ? -res : res);
}
