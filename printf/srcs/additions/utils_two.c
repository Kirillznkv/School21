/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:58:42 by kshanti           #+#    #+#             */
/*   Updated: 2020/12/02 18:18:01 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			column_precision(t_arg *tmp, long long num)
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

int			pointer_length(long unsigned int n)
{
	int		i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		i++;
		n /= 16;
	}
	return (i);
}

int			precision_poiner(t_arg *tmp, long unsigned int n)
{
	int		i;

	i = tmp->precision - pointer_length(n);
	if (i < 0)
		return (0);
	return (i);
}

int			width_pointer(t_arg *tmp, long unsigned int n)
{
	int		i;

	i = pointer_length(n);
	if (tmp->precision > i)
		i = tmp->precision;
	i = tmp->width - i;
	if (i < 0)
		return (0);
	return (i);
}
