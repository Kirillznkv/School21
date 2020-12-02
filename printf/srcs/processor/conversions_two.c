/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:52:08 by kshanti           #+#    #+#             */
/*   Updated: 2020/12/02 18:19:52 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			output_c(t_arg *tmp, va_list *va)
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

int			output_p(t_arg *tmp, va_list *va)
{
	long long		pointer;
	int				width;
	int				precision;

	pointer = va_arg(*va, long unsigned int);
	width = width_pointer(tmp, pointer) - 2;
	precision = precision_poiner(tmp, pointer);
	if (width < 0)
		width = 0;
	if (!pointer && tmp->precision == 0)
	{
		if (tmp->width - 2 > 0)
			width++;
		ft_put_n_char(' ', width);
		ft_putstr_fd("0x", 1);
		return (width + 2);
	}
	if (tmp->flags == 0)
		ft_put_n_char(' ', width);
	ft_putstr_fd("0x", 1);
	ft_put_n_char('0', precision);
	out_to_16(pointer, 'a');
	if (tmp->flags == 2)
		ft_put_n_char(' ', width);
	return (width + precision + pointer_length(pointer) + 2);
}

int			output_s(t_arg *tmp, va_list *va)
{
	int				flaaaag;
	int				res;
	int				width;
	char			*str;

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

int			output_x(t_arg *tmp, va_list *va)
{
	char			c;
	unsigned int	num;
	int				width;
	int				precision;

	c = (tmp->type == 'x') ? 'a' : 'A';
	num = va_arg(*va, unsigned int);
	precision = precision_poiner(tmp, num);
	width = width_pointer(tmp, num);
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
