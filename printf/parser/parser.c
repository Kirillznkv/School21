/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:26:01 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/21 18:55:47 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

char		*skip_flag(char *str, t_list *tmp)
{
	while (*str == '0' && (*str + 1) != '-')
	{
		str++;
		tmp->length++;
		tmp->flags = 1;
	}
	while (*str == '-' && (*str + 1) != '0')
	{
		str++;
		tmp->length++;
		tmp->flags = 2;
	}
	return (str);
}

char		*skip_width_precis(char *str, t_list *tmp, va_list **va)
{
	if (*str == '0' || *str == '-' || *str == '+')
		tmp->flags = -1;
	else if (ft_isdigit(str))
	{
		tmp->width = ft_atoi(str);
		while (ft_isdigit(str))
			str++;
	}
	else if (*str == '*')
	{
		tmp->width = va_arg(**va, int);
		if (tmp->width < 0)
		{
			tmp->width *= -1;
			tmp->flags = (!tmp->flags) ? 2 : -1;
		}
		str++;
	}
	else
		return (str);
	
}

t_list		*parser(char *str, va_list *va)
{
	t_list	*tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	tmp->length = 1;
	tmp->flags = 0;
	tmp->width = 0;
	tmp->precision = 0;
	tmp->type = '\0';
	str = skip_flag(str, tmp);
	str = skip_width_precis(str, tmp, &va);

	return (tmp);
}
