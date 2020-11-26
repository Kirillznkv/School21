/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:11:42 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/26 03:42:46 by kshanti          ###   ########.fr       */
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

int			column_width_str(t_arg *tmp, char *str)
{
	int		res;

	res = tmp->width;
	if (tmp->precision == -1)
		return (res);
	if (tmp->precision < ft_strlen(str))
		res -= tmp->precision;
	else
		res -= ft_strlen(str);
	if (res < 0)
		return (0);
	return (res);
}

void		output_precision_str(t_arg *tmp, char *str)
{
	if (tmp->precision > ft_strlen(str))
		tmp->precision = ft_strlen(str);
	while (tmp->precision-- && *str)
		ft_putchar_fd(*(str++), 1);
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
