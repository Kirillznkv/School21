/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:26:01 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/22 20:43:38 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int         num_length(int n)
{
    int     i;

    i = 0;
    if (n == 0)
        return (1);
    while (n)
    {
        n /=10;
        i++;
    }
    return (i);
}

char		*skip_flag(char *str, t_arg *tmp)
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

char		*skip_width_precis(char *str, t_arg *tmp, va_list *va)
{
	if (*str == '0' || *str == '-' || *str == '+')
		tmp->flags = -1;
	else if (ft_isdigit(*str))
	{
		tmp->width = ft_atoi(str);
		while (ft_isdigit(*str) && str++)
			tmp->length++;
	}
	else if (*str == '*')
	{
		tmp->width = va_arg(*va, int);
		if (tmp->width < 0)
		{
			tmp->width *= -1;
			tmp->flags = (!tmp->flags) ? 2 : -1;
			tmp->length++;
		}
        tmp->length += num_length(tmp->width);
		str++;
	}
	else if (*str != '.')
		return (str);
	tmp->length++;
	tmp->precision = 0;
	if (ft_isdigit(*(++str)))
	{
		tmp->precision = ft_atoi(str);
		while (ft_isdigit(*str) && str++)
			tmp->length++;
	}
	else if (*str == '*')
	{
		tmp->precision = va_arg(*va, int);
		if (tmp->precision < 0)
			tmp->flags = -1;
        tmp->length += num_length(tmp->precision);
		str++;
	}
	return (str);
}

char		*skip_type(char *str, t_arg *tmp)//дописать проверки воизбежание сеги
{
	char	*set;

	set = ft_strdup("cspdiuxX");
	if (ft_strchr(set, *str))
		tmp->type = *str;
	else
		tmp->flags = -1;
	tmp->length++;
	str++;
	return (str);
}

//флаг = -1, не правильный тип
t_arg		*parser(char *str, va_list *va)
{
	t_arg	*tmp;

	if (!(tmp = (t_arg*)malloc(sizeof(t_arg))))
		return (NULL);
	tmp->length = 1;//%
	tmp->flags = 0;
	tmp->width = 0;
	tmp->precision = -1;
	tmp->type = '\0';
	str = skip_flag(str, tmp);
	str = skip_width_precis(str, tmp, va);
	str = skip_type(str, tmp);
	if (tmp->flags == -1)
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
