# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/28 14:42:19 by kshanti           #+#    #+#              #
#    Updated: 2020/12/02 18:05:26 by kshanti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a #Добавить флаги

C_FILE = ./srcs/additions/utils.c ./srcs/parser/parser.c\
		 ./srcs/processor/conversions.c ./srcs/ft_printf.c\
		 ./srcs/processor/conversions_two.c ./srcs/additions/utils_two.c

O_FILE = $(C_FILE:.c=.o)

HEAD =	./includes/ft_printf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(O_FILE)
	$(MAKE) -C ./libft all
	cp ./Libft/libft.a $(NAME)
	ar -rcs $(NAME) $(O_FILE)

%.o: %.c $(HEAD)
	gcc -c $(FLAGS) $< -o $@

clean:
	@rm -f $(O_FILE)
	$(MAKE) -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re