/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:59:12 by kshanti           #+#    #+#             */
/*   Updated: 2020/12/01 17:41:11 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			out_diu(t_arg *tmp, long long num, int width, int precision)//вывод для d, i, u
{
	int		res;

	res = 0;
	if (num == 0 && tmp->precision == 0)
	{
		if (width)
			width++;
		ft_put_n_char(' ', width);
		return (width);
	}
	if (tmp->flags == 0)
		ft_put_n_char(' ', width);
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
		res++;
	}
	if (tmp->flags == 1)
		ft_put_n_char('0', width);
	ft_put_n_char('0', precision);
	ft_putnbr_fd(num, 1);
	if (tmp->flags == 2)
		ft_put_n_char(' ', width);
	return (res + width + precision + num_length(num));
}

int		output_d(t_arg *tmp, va_list *va)
{
	int		num;
	int		width;
	int		precision;

	num = va_arg(*va, int);
	width = column_width(tmp, num);
	precision = column_precision(tmp, num);
	return (out_diu(tmp, num, width, precision));
}

int		output_u(t_arg *tmp, va_list *va)
{
	unsigned int	num;
	int				width;
	int				precision;

	num = va_arg(*va, unsigned int);
	width = column_width(tmp, num);
	precision = column_precision(tmp, num);
	return (out_diu(tmp, num, width, precision));
}

int		output_percent(t_arg *tmp)
{
	int				width;

	width = column_width(tmp, 0);
	if (tmp->flags == 0)
		ft_put_n_char(' ', width);
	if (tmp->flags == 1)
		ft_put_n_char('0', width);
	ft_putchar_fd('%', 1);
	if (tmp->flags == 2)
		ft_put_n_char(' ', width);
	return (width + 1);
}

int		output_c(t_arg *tmp, va_list *va)
{
	int				width;
	unsigned char	ch;

	ch = va_arg(*va, int);
	width = column_width(tmp, 1);
	if (tmp->flags == 0)
		ft_put_n_char(' ', width);
	ft_putchar_fd(ch, 1);
	if (tmp->flags == 2)
		ft_put_n_char(' ', width);
	return (width + 1);
}

int		output_p(t_arg *tmp, va_list *va)
{
	long long	pointer;
	char		*str;
	int         width;
    int		    precision;

	pointer = va_arg(*va, long long);
	width = tmp->width - 14;
	if (width < 0)
		width = 0;
	if (!pointer)
		width = tmp->width - 3;
	if (tmp->flags == 0)
	    ft_put_n_char(' ', width);
    ft_putstr_fd("0x", 1);
	out_to_16(pointer, 'a');
	if (tmp->flags == 2)
        ft_put_n_char(' ', width);
	if (!pointer)
		width -= 11;
	return (14 + width);
}

int		output_s(t_arg *tmp, va_list *va)
{
	int		flaaaag;
	int		res;
	int		width;
	char	*str;

	str = va_arg(*va, char*);
	flaaaag = 0;
	if (!str && ++flaaaag)
		if (!(str = ft_strdup("(null)")))
			return (0);
	width = column_width_str(tmp, str);
	if (tmp->flags == 0)
		ft_put_n_char(' ', width);
	res = output_precision_str(tmp, str);
	if (tmp->flags == 2)
		ft_put_n_char(' ', width);
	if (flaaaag)
		free(str);
	return (res + width);
}

int        output_x(t_arg *tmp, va_list *va)
{
    char			c;
    unsigned int	num;
    int				width;
    int				precision;

    c = (tmp->type == 'x') ? 'a' : 'A';
    num = va_arg(*va, unsigned int);
    precision = precision_poiner(tmp, num);
    width = width_pointer(tmp, num, precision);
	if (num == 0 && tmp->precision == 0)
	{
		if (width)
			width++;
		ft_put_n_char(' ', width);
		return (width);
	}
	if (tmp->flags == 0)
        ft_put_n_char(' ', width);
	if (tmp->flags == 1)
        ft_put_n_char('0', width);
    ft_put_n_char('0', precision);
    out_to_16(num, c);
    if (tmp->flags == 2)
        ft_put_n_char(' ', width);
	return (width + precision + pointer_length(num));
}

int		processor(t_arg *tmp, va_list *va)
{
	if (tmp->flags == 1 && tmp->precision != -1)
		tmp->flags = 0;
	if (tmp->precision < -1)
		tmp->precision = -1;
	if (tmp->flags == 3)// && (tmp->type == '%' || tmp->type == 's'))
		tmp->flags = 2;
	//else if (tmp->flags == 3)
	//	return (0);
	if (tmp->type == 'd' || tmp->type == 'i')
		return (output_d(tmp, va));
	else if (tmp->type == 'u')
		return (output_u(tmp, va));
	else if (tmp->type == '%')
		return (output_percent(tmp));
	else if (tmp->type == 'c')
		return (output_c(tmp, va));
	else if (tmp->type == 's')
		return (output_s(tmp, va));
	else if (tmp->type == 'p')
		return (output_p(tmp, va));
	else if (tmp->type == 'x' || tmp->type == 'X')
	    return (output_x(tmp, va));
	return (0);
}
