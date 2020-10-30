/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:29:56 by kshanti           #+#    #+#             */
/*   Updated: 2020/10/30 16:26:08 by kshanti          ###   ########.fr       */
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
void*		ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void*		ft_memccpy(void* s1, const void* s2, int c, size_t n);
int			ft_strncmp(const char* s1, const char* s2, size_t n);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c)

#endif
