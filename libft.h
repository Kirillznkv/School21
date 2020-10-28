/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:29:56 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/28 19:31:14 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"//

size_t		ft_strlen(const char* str);
char*		ft_strdup(const char* str);
void		ft_bzero(void* s, size_t n);
void*		ft_calloc(size_t n, size_t size);

#endif
