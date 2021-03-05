/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubheader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:17:59 by kshanti           #+#    #+#             */
/*   Updated: 2021/03/05 11:50:58 by kshanti          ###   ########.fr       */
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
typedef struct	s_sprite_arr
{
	double			x;
	double			y;
	double			dist;
}					t_sprite_arr;
typedef struct	s_sprite
{
	double			x;
	double			y;
	double			inv;
	double			transX;
	double			transY;
	int				sp_screenX;
	int				sp_hight;
	int				sp_width;
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
	int				stripe;
	int				tex_x;
	int				tex_y;
	int				i;
	int				d;
}					t_sprite;
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
	t_sprite		sp;
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
void				raycasting(t_map_settings *tmp);
void				sprite(t_map_settings *tmp, double dist[]);
int					color_we(t_map_settings *tmp, int x, int y);
int					color_s(t_map_settings *tmp, int x, int y);
int					color_so(t_map_settings *tmp, int x, int y);
int					color_ea(t_map_settings *tmp, int x, int y);
int					color_no(t_map_settings *tmp, int x, int y);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				screen(t_map_settings *tmp);
void				init_images(t_map_settings *tmp);
t_map_settings		*cub_init(char *filename, int scr);
void				fsm1(int *end, int *h);
void				fsm2(int *end, int *h, int *w, char **line);
void				fsm3(int *end, int *flag);
void				fsm4(int *check_gnl);
int					ffm(char **line, int *flag);
void				spase_in_map(t_map_settings *tmp, int w, int h);

#endif
