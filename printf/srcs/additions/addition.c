/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:11:42 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/26 04:57:23 by kshanti          ###   ########.fr       */
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

int         pointer_length(long long n)
{
    int     i;

    i = 0;
    while (n)
    {
        i++;
        n /= 16;
    }
    return (i);
}

int         precision_poiner(t_arg *tmp, long long n)
{
    int     i;

    if (tmp->flags == 1 && tmp->precision == -1)
        i = tmp->width - 2 - pointer_length(n);
    else
        i = tmp->precision - pointer_length(n);
    if (i < 0)
        return (0);
    return (i);
}

int         width_pointer(t_arg *tmp, long long n)
{
    int     i;

    if (tmp->flags == 1 && tmp->precision == -1)
        return (0);
    i = pointer_length(n);
    if (tmp->precision > i)
        i = tmp->precision;
    i = tmp->width - i - 2;
    if (i < 0)
        return (0);
    return (i);
}

void		out_to_16(long long n)
{
    long long		i;
	char	ch;

	i = 1;
	while (n / i >= 16)
		i *= 16;
	while (i)
	{
		if (n / i < 10)
			ch = (n / i) + '0';
		else
			ch = ((n / i) % 10) + 'a';
		ft_putchar_fd(ch, 1);
		n %= i;
		i /= 16;
	}
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
