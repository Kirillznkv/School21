/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:06:55 by kshanti           #+#    #+#             */
/*   Updated: 2020/12/02 17:28:06 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_str(char *s1, char *s)
{
		*s1 = '\0';
		ft_putstr_fd(s, 1);
}

int			ft_printf(const char *str, ...)
{
	va_list		va;
	char		*s;
	char		*p_newArg;
	size_t		size;
	t_arg		*elem;

	size = ft_strlen(str);
	if (!(s = ft_strdup(str)))
		return (0);
	va_start(va, str);
	str = s;
	while ((p_newArg = ft_strchr(s, '%')))
	{
		elem = NULL;
		print_str(p_newArg, s);
		if (!(elem = parser(p_newArg + 1, &va)))
			break ;
		size += (processor(elem, &va) - elem->length);
		s = p_newArg + elem->length;
		free(elem);
	}
	ft_putstr_fd(s, 1);
	va_end(va);
	free((void*)str);
	return (size);
}
