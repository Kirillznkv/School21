# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/07 17:20:27 by kshanti           #+#    #+#              #
#    Updated: 2020/12/07 17:23:27 by kshanti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libcub.a

SRCS = ./srcs/

C_FILE = main.c $(SRCS)parser.c

O_FILE = $(C_FILE:.c=.o)

HEAD =	./cubheader.h

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