/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:29:56 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/29 19:08:12 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"//
#include "string.h"//

size_t		ft_strlen(const char* str);
char*		ft_strdup(const char* str);
void		ft_bzero(void* s, size_t n);
void*		ft_calloc(size_t n, size_t size);

long long	ft_atoi(const char* str);
char*		ft_strchr(const char* s, int c);
char*		ft_strrchr(const char* s, int c);
void*		ft_memset(void* s, int c, size_t n);
void*		ft_memcpy(void* s1, const void* s2, size_t n);
void*		ft_memmove(void* s1, const void* s2, size_t  n);

#endif
