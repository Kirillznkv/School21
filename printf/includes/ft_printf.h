/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:08:11 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/30 17:38:01 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "../libft/libft.h"

typedef struct	s_lst
{
	int		flags;
	int		width;
	int		precision;
	char	type;
	int		length;
}				t_arg;
t_arg			*parser(char *str, va_list *va);
int				ft_printf(const char *format, ...);
int				num_length(long long n);
int				column_width(t_arg *tmp, long long num);
int				column_precision(t_arg *tmp, long long num);
int				column_width_str(t_arg *tmp, char *str);
int				output_precision_str(t_arg *tmp, char *str);
int             precision_poiner(t_arg *tmp, unsigned int n);
void			out_to_16(long long n, char c);
int       		pointer_length(unsigned int n);
void			ft_put_n_char(char ch, int n);
int             width_pointer(t_arg *tmp, unsigned int n);
int				processor(t_arg *tmp, va_list *va);

#endif
