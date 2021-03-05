# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 17:20:27 by kshanti           #+#    #+#              #
#    Updated: 2021/03/05 12:37:36 by kshanti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

HEAD = ./cubheader.h
SRCS = ./srcs/
GNL = ./get_next_line/

CFLAGS = -Wall -Wextra -Werror
MLX = ./mlx/libmlx.a -framework OpenGL -framework Appkit

C_FILE =	$(SRCS)parser_skip_s.c $(SRCS)parser_skip_s_utils.c\
			$(SRCS)parser_skip_map.c $(SRCS)parser_check_map.c\
			$(SRCS)parser.c\
			$(GNL)get_next_line.c $(GNL)get_next_line_utils.c\
			$(SRCS)error.c $(SRCS)raycasting.c $(SRCS)get_color.c\
			./main.c $(SRCS)sprite.c $(SRCS)screen.c $(SRCS)raycasting_u.c\
			$(SRCS)init.c $(SRCS)fsm.c $(SRCS)fp.c $(SRCS)sprite_utils.c

O_FILE = $(C_FILE:.c=.o)

all:
	$(MAKE) $(NAME) -j 4

$(NAME): $(O_FILE)
	$(MAKE) -C ./libft all
	$(MAKE) -C ./mlx all
	gcc $(O_FILE) ./libft/libft.a $(MLX) -o $(NAME)

%.o: %.c $(HEAD)
	gcc -c $(СFLAGS) $< -o $@

clean:
	@rm -f $(O_FILE)
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./mlx clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re