/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubheader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:17:59 by kshanti           #+#    #+#             */
/*   Updated: 2021/02/06 22:14:50 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBHEADER_H
# define CUBHEADER_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "fcntl.h"
# include "errno.h"
# include "./mlx/mlx.h"
# include "math.h"
# include "stdio.h" //убрать

typedef struct	s_rey
{
	int				step;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			dy;
	double			dx;
}					t_rey;
typedef struct	s_vector
{
	int				x;
	int				y;
}					t_vector;
typedef struct	s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;
typedef struct	s_player
{
	t_vector		dir;
	int				y;
	int				x;
}					t_player;
typedef struct	s_sprite
{
	int				y;
	int				x;
	struct s_sprite	*next;
}					t_sprite;
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
	t_player		plr;
	t_sprite		*sp;
	void			*mlx;
	void			*win;
	t_data			img;
}					t_map_settings;

t_map_settings		*parser(char *filename);
void				error_control(char *str);
void				error_system(int error);
void				set_path(char *str, char **image);
void				set_color(char *str, t_color *color);
void				set_r(char *str, t_map_settings *tmp);
void				skip_settings(int fd, t_map_settings *tmp);
void				skip_map(int fd, int *w, int *h);
void				check_map(t_map_settings *tmp, int h);
int					skip_empty_line(char *line);
t_sprite			*lstnew(int i, int j);
void				addlst(t_map_settings *tmp, int i, int j);
void				print_map2d(t_map_settings *tmp);

#endif
