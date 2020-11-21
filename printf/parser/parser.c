/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:26:01 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/21 17:20:13 by kshanti          ###   ########.fr       */
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

t_list		parser(char *str)
{
	t_list	tmp;

	tmp.length = 1;
	str = skip_flag(str, &tmp);
}
