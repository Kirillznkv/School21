/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:06:46 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/13 20:20:35 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 3
#endif

size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
int			maybe_line(char **static_buff, char **line);
int			get_next_line(int fd, char **line);

#endif
