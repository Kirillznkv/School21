/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:06:55 by kshanti           #+#    #+#             */
/*   Updated: 2020/12/01 20:20:23 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_printf(const char *str, ...)
{
	va_list		va;
	char		*s;
	char		*p_newArg;
	size_t		size;
	t_arg		*elem;

	size = ft_strlen(str);
	s = ft_strdup(str);
	if (!s)
		return (0);
	va_start(va, str);
	str = s;
	elem = NULL;
	while ((p_newArg = ft_strchr(s, '%')))
	{
		*p_newArg = '\0';
		ft_putstr_fd(s, 1);
		s = p_newArg;
		elem = parser(++p_newArg, &va);
		if (!elem)
			break ;
		size += processor(elem, &va);
		size -= elem->length;
		s += elem->length;
	}
	if (*s)
		ft_putstr_fd(s, 1);
	if (elem)
		free(elem);
	va_end(va);
	free(str);
	return (size);
}
