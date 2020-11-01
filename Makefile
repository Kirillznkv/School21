# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 14:54:25 by kshanti           #+#    #+#              #
#    Updated: 2020/11/01 18:56:15 by kshanti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

C_FILE = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_strchr.c\
ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
ft_memcpy.c ft_memmove.c ft_memset.c ft_strdup.c ft_strlcat.c ft_toupper.c\
ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c\
ft_substr.c

O_FILE = $(C_FILE:.c=.o)

HEDER = libft.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(O_FILE)
	ar -rcs $(NAME) $(O_FILE)

%.o: %.c $(HEADER)
	gcc -c -Wall -Wextra -Werror $<

clean:
	@rm -f $(O_FILE)

fclean: clean
	@rm -f $(NAME)

re: fclean all
