/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:06:46 by kshanti           #+#    #+#             */
/*   Updated: 2020/11/15 19:59:48 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

typedef struct		s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}					t_list;
t_list				*list_finder(int fd, t_list **lst);
char				*return_last_line_and_free(char **st_buff, int *res);
int					add_to_static(int fd, int *size_buff, char *buff,
char **st_buff);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strchr(const char *s, int c);
int					maybe_line(char **static_buff, char **line);
int					get_next_line(int fd, char **line);

#endif
