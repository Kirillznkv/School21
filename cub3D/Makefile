# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 17:20:27 by kshanti           #+#    #+#              #
#    Updated: 2021/01/26 16:07:49 by kshanti          ###   ########.fr        #
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
			$(SRCS)error.c\
			$(SRCS)print_map2d.c ./main.c

O_FILE = $(C_FILE:.c=.o)

all: $(NAME)

$(NAME): $(O_FILE)
	$(MAKE) -C ./libft all
	$(MAKE) -C ./mlx all
	#ECHO $(O_FILE)
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