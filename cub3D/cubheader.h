/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubheader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:17:59 by kshanti           #+#    #+#             */
/*   Updated: 2021/01/20 16:06:16 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBHEADER_H
# define CUBHEADER_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "fcntl.h"
# include "errno.h"
# include "stdio.h" //убрать

typedef struct	s_images
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*sprite;
}					t_images;
typedef struct	s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;
typedef struct	s_map_settings
{
	int				width;
	int				height;
	t_images		images;
	t_color			color_f;
	t_color			color_c;
	char			**map;
}					t_map_settings;
typedef struct	s_player
{
	char			direction;
	int				x;
	int				y;
}					t_player;
typedef struct	s_sprite
{
	int				x;
	int				y;
	struct s_sprite	*next;
}					t_sprite;

t_map_settings		*parser(char *filename, int *w, int *h);
void				error_control(char *str);
void				error_system(int error);
int					set_path(char *str, char **image);
int					set_color(char *str, t_color *color);
int					set_r(char *str, t_map_settings *tmp);
void				skip_settings(int fd, t_map_settings *tmp);
void				skip_map(int fd, int *w, int *h);
void				check_map(char **tmp, int h);
int					skip_empty_line(char *line);

#endif
