/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:06:55 by kshanti           #+#    #+#             */
/*   Updated: 2020/12/02 16:07:59 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_str(char *s1, char *s2)
{
	while (s1 != s2)
		ft_putchar_fd(*(s1++), 1);
}

int			ft_printf(const char *str, ...)
{
	va_list		va;
	char		*p_newArg;
	size_t		size;
	t_arg		*elem;

	size = ft_strlen(str);
	va_start(va, str);
	elem = NULL;
	while ((p_newArg = ft_strchr(str, '%')))
	{
		print_str((char*)str, p_newArg);
		if (!(elem = parser(p_newArg + 1, &va)))
			return (0);
		size += (processor(elem, &va) - elem->length);
		str = p_newArg + elem->length;
	}
	ft_putstr_fd((char*)str, 1);
	va_end(va);
	free(elem);
	return (size);
}
