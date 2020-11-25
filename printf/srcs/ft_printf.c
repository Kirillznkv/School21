/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:06:55 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/25 17:10:54 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
//
#include "stdio.h"
//

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
		processor(elem, &va);
		s += elem->length;
		//
		/*if (!elem)
			printf("NULL\n");
		else
		{
			printf("\ntype = %c\n", elem->type);
			printf("flag = %c\n", (elem->flags == 0) ? 'N' : (elem->flags == 1) ? '0' : '-');
			printf("wigth = %d\n", elem->width);
			printf("precision = %d\n", elem->precision);
			printf("length = %d\n", elem->length);
			s += elem->length;
		}*/
		//
	}
	if (*s)
		ft_putstr_fd(s, 1);
	va_end(va);
	return (1);
}
