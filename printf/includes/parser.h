/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:06:55 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/22 20:41:36 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "stdarg.h"
# include "../libft/libft.h"
# include "./ft_printf.h"

typedef struct	s_lst
{
	int		flags;
	int		width;
	int		precision;
	char	type;
	int		length;
}				t_arg;
t_arg			*parser(char *str, va_list *va);

#endif
