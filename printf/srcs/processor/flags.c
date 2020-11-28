/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:59:12 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/28 13:52:00 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		output_d(t_arg *tmp, va_list *va)
{
	int		num;
	int		width;
	int		precision;

	num = va_arg(*va, int);
	width = column_width(tmp, num);
	precision = column_precision(tmp, num);
	if (num == 0 && tmp->precision == 0)
	{
	    width++;
		tmp->flags = 0;
	}
	if (tmp->flags == 0 || (tmp->flags == 1 && tmp->precision != -1))
		ft_put_n_char(' ', width);
	if (num < 0)
		ft_putchar_fd('-', 1);
	if (tmp->flags == 1 && tmp->precision == -1)
		ft_put_n_char('0', width);
	ft_put_n_char('0', precision);
	if (!(num == 0 && tmp->precision == 0))
	    ft_putnbr_fd((num > 0) ? num : -num, 1);
	if (tmp->flags == 2)
		ft_put_n_char(' ', width);
}

void		output_percent(t_arg *tmp)
{
	int		width;

	width = column_width(tmp, 0);
	if (tmp->flags == 0 || (tmp->flags == 1 && tmp->precision != -1))
		ft_put_n_char(' ', width);
	if (tmp->flags == 1 && tmp->precision == -1)
		ft_put_n_char('0', width);
	ft_putchar_fd('%', 1);
	if (tmp->flags == 2)
		ft_put_n_char(' ', width);
}

void		output_c(t_arg *tmp, va_list *va)
{
	int		width;
	unsigned char	ch;

	ch = va_arg(*va, int);
	width = column_width(tmp, 1);
	if (tmp->flags == 0)
		ft_put_n_char(' ', width);
	ft_putchar_fd(ch, 1);
	if (tmp->flags == 2)
		ft_put_n_char(' ', width);
}

void		output_s(t_arg *tmp, va_list *va)
{
	int		width;
	char	*str;

	str = va_arg(*va, char*);
	width = column_width_str(tmp, str);
	if (tmp->flags == 0)
		ft_put_n_char(' ', width);
	output_precision_str(tmp, str);
	if (tmp->flags == 2)
		ft_put_n_char(' ', width);
}

void		output_p(t_arg *tmp, va_list *va)
{
	long long	pointer;
	char		*str;
	int         width;
    int		    precision;

	pointer = va_arg(*va, long long);
	width = width_pointer(tmp, pointer);
	precision = precision_poiner(tmp, pointer);
	if (tmp->flags == 0 || (tmp->flags == 1 && tmp->precision != -1))
	    ft_put_n_char(' ', width);
    ft_putstr_fd("0x", 1);
	if (tmp->flags == 1 && tmp->precision == -1)
    	ft_put_n_char('0', precision);
	out_to_16(pointer, 'a');
	if (tmp->flags == 2)
        ft_put_n_char(' ', width);
}

void        output_x(t_arg *tmp, va_list *va)
{
    char    c;
    int		num;
    int		width;
    int		precision;

    if (tmp->type == 'x')
        c = 'a';
    else
        c = 'A';
    num = va_arg(*va, int);
    width = width_pointer(tmp, num);
    precision = precision_poiner(tmp, num);
	if (num == 0 && tmp->precision == 0)
	{
	    width++;
		tmp->flags = 0;
	}
	if (tmp->flags == 0 || (tmp->flags == 1 && tmp->precision != -1))
        ft_put_n_char(' ', width);
	if (tmp->flags == 1 && tmp->precision == -1)
        ft_put_n_char('0', width);
    ft_put_n_char('0', precision);
    if (!(num == 0 && tmp->precision == 0))
        out_to_16(num, c);
    if (tmp->flags == 2)
        ft_put_n_char(' ', width);
}

void		processor(t_arg *tmp, va_list *va)
{
	if (tmp->type == 'd' || tmp->type == 'i')
		output_d(tmp, va);
	else if (tmp->type == '%')
		output_percent(tmp);
	else if (tmp->type == 'c')
		output_c(tmp, va);
	else if (tmp->type == 's')
		output_s(tmp, va);
	else if (tmp->type == 'p')
		output_p(tmp, va);
	else if (tmp->type == 'x' || tmp->type == 'X')
	    output_x(tmp, va);
}
