/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:59:12 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/25 17:06:30 by kshanti          ###   ########.fr       */
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
	if (tmp->flags == 0)
		ft_put_n_char(' ', width);
	else if (tmp->flags == 1)
		ft_put_n_char('0', width);
	if (num < 0)
		ft_putchar_fd('-', 1);
	ft_put_n_char('0', precision);
	ft_putnbr_fd((num > 0) ? num : -num, 1);
	if (tmp->flags == 2)
		ft_put_n_char(' ', width);
}

void		processor(t_arg *tmp, va_list *va)
{
	if (tmp->type == 'd')
		output_d(tmp, va);
}
