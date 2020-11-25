/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:11:42 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/25 18:09:16 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			num_length(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /=10;
		i++;
	}
	return (i);
}

int			column_width(t_arg *tmp, int num)
{
	int		res;

	res = tmp->width;
	if (num < 0)
	{
		res--;
		num = -num;
	}
	if (tmp->precision > 0 && tmp->precision > num_length(num) && tmp->type != '%')
		res -= tmp->precision;
	else
		res -= num_length(num);
	if (res < 0)
		return (0);
	return (res);
}

int			column_precision(t_arg *tmp, int num)
{
	int		res;

	res = tmp->precision;
	if (num < 0)
		num = -num;
	res -= num_length(num);
	if (res < 0)
		return (0);
	return (res);
}

void		ft_put_n_char(char ch, int n)
{
	while (n--)
		ft_putchar_fd(ch, 1);
}
