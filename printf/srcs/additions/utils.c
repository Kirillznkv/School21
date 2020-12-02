/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:11:42 by kshanti           #+#    #+#             */
/*   Updated: 2020/12/02 18:19:24 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			num_length(long long n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int			column_width(t_arg *tmp, long long num)
{
	int		res;

	res = tmp->width;
	if (num < 0)
	{
		res--;
		num = -num;
	}
	if (tmp->precision > 0 && tmp->precision > num_length(num)
		&& tmp->type != '%')
		res -= tmp->precision;
	else
		res -= num_length(num);
	if (res < 0)
		return (0);
	return (res);
}

int			column_width_str(t_arg *tmp, char *str)
{
	int		res;

	res = tmp->width;
	if (tmp->precision == -1)
	{
		if ((int)res - (int)ft_strlen(str) < 0)
			return (0);
		else
			return ((int)res - (int)ft_strlen(str));
	}
	if ((int)tmp->precision < (int)ft_strlen(str))
		res -= tmp->precision;
	else
		res -= ft_strlen(str);
	if (res < 0)
		return (0);
	return (res);
}

void		out_to_16(long long n, char c)
{
	long long	i;
	char		ch;

	i = 1;
	while (n / i >= 16)
		i *= 16;
	while (i)
	{
		if (n / i < 10)
			ch = (n / i) + '0';
		else
			ch = ((n / i) % 10) + c;
		ft_putchar_fd(ch, 1);
		n %= i;
		i /= 16;
	}
}

int			output_precision_str(t_arg *tmp, char *str)
{
	int		length;

	length = 0;
	if ((int)tmp->precision > (int)ft_strlen(str))
		tmp->precision = ft_strlen(str);
	while (tmp->precision-- && str[length])
		ft_putchar_fd(str[length++], 1);
	return (length);
}
