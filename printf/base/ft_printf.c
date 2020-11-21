/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:06:55 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/21 16:08:20 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_printf(const char *str, ...)
{
	va_list		ap;
	char		*p_newArg;
	size_t		size;
	t_list		elem;

	size = ft_strlen(str);
	va_start(ap, str);
	while ((p_newArg = ft_strchr(str, '%')))//вычесть ненаписанные символы
	{
		*p_newArg = '\0';
		ft_putstr_fd(str, 1);
		elem = parser(++p_newArg);
	}
	if (*str)
		ft_putstr_fd(str, 1);
	va_end(ap);
}
