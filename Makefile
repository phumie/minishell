# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnevhuta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/22 12:30:49 by pnevhuta          #+#    #+#              #
#    Updated: 2017/09/22 15:37:09 by pnevhuta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

NAME = minishell

SRCS = 	minishell.c env.c setenv.c unsetenv.c signals.c cd.c echo.c builtins.c exit.c get_next_line.c epur_str.c ft_split.c

SRC	= $(addprefix ./src/,$(SRCS))
OBJ = $(SRC:.c=.o)
BUILDDIR = ./build/
FLAGS = -Wall -Wextra -Werror -o
LIBDIR = ./libft/
LIB = ./libft/libft.a

all: $(NAME) $(LIB) $(SRC)

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	@gcc $(FLAGS) $@ $^ $(LIB) 
	@echo $@" complied"

clean:
	@make -C ./libft/ clean
	@rm -rf $(OBJ)
	@echo "minishell clean"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME) *.a
	@echo "minishell fclean"

re: fclean all 
