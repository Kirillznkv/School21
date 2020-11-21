/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:08:11 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/21 16:08:17 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "../libft/libft.h"
# include "parser.h"

typedef struct	s_list
{
	int		flags;
	int		width;
	int		precision;
	char	type;
	size_t	length;
}				t_list;

int				printf(const char *format, ...);

#endif
