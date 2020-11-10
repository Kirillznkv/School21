/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:06:46 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/10 19:52:12 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 32
#endif

int				get_next_line(int fd, char **line);
char			*ft_strjoin_for_gnl(char *s1, char *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
void			*ft_calloc(size_t n, size_t size);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *str);
size_t			maybe_nextline(char *st_buff);
char			*ft_strdup(const char *s);

#endif
