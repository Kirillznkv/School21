#!/bin/bash
gcc -Wall -Wextra -Werror -L./minilibx_mms_20200219 -lmlx -framework OpenGL -framework AppKit main.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./libft/ft_calloc.c ./libft/ft_bzero.c ./libft/ft_isdigit.c ./libft/ft_isalpha.c ./libft/ft_strncmp.c ./srcs/parser.c ./libft/ft_atoi.c ./libft/ft_strtrim.c ./libft/ft_strlcpy.c ./libft/ft_strrchr.c ./libft/ft_putstr_fd.c ./libft/ft_putchar_fd.c ./srcs/error.c ./srcs/parser_check_map.c ./srcs/parser_skip_map.c ./srcs/parser_skip_s_utils.c ./srcs/parser_skip_s.c ./srcs/print_map2d.c
./a.out\


