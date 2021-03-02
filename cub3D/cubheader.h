/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubheader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:17:59 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/02 20:37:53 by kshanti          ###   ########.fr       */
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

typedef struct	s_ray
{
	double			planeX;
	double			planeY;
	double			time;
	double			oldtime;
	double			cameraX;
	double			rayDirX;
	double			rayDirY;
	double			sideDistX;
	double			sideDistY;
	double			deltaDistX;
	double			deltaDistY;
	int				mapX;
	int				mapY;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;
	double			perpWallDist;
}					t_ray;
typedef struct	s_line
{
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
}					t_line;
typedef struct	s_vector
{
	double			x;
	double			y;
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
	t_vector		pos;
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
	int				color;
	int				r;
	int				g;
	int				b;
}					t_color;
typedef struct	s_win
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				w;
	int				h;
}					t_win;
typedef struct	s_textur
{
	int				tex_x;
	int				tex_y;
	double			wall_x;
	double			step;
	double			tex_pos;
	t_win			img_so;
	t_win			img_no;
	t_win			img_we;
	t_win			img_ea;
	t_win			img_s;
}					t_textur;
typedef struct	s_map_settings
{
	int				w;
	int				h;
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
	double			planeX;
	double			planeY;
	t_textur		text;
	
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
void				raycasting(t_map_settings *tmp);

#endif
