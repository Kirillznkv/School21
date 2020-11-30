/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:06:55 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/30 15:59:15 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_printf(const char *str, ...)
{
	va_list		va;
	char        *s;
	char		*p_newArg;
	size_t		size;
	t_arg		*elem;

	size = ft_strlen(str);
	va_start(va, str);
	s = ft_strdup(str);
	while ((p_newArg = ft_strchr(s, '%')))//вычесть ненаписанные символы
	{
		*p_newArg = '\0';
		ft_putstr_fd(s, 1);
		s = p_newArg;
		elem = parser(++p_newArg, &va);
		size += processor(elem, &va);
		size -= elem->length;
		s += elem->length;
	}
	if (*s)
		ft_putstr_fd(s, 1);
	va_end(va);
	return (size);
}
