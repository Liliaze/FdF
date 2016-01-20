# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboudy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:53:12 by dboudy            #+#    #+#              #
#    Updated: 2016/01/20 14:54:34 by dboudy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF
GCC = gcc
PATH_SRC = ./
PATH_OBJ = ./obj/
PATH_INC = ./libft/includes/
CFLAGS = -Wall -Werror -Wextra
FLAGS2 = -lmlx -framework OpenGL -framework AppKit
HEADERS = includes/
SRC = fdf.c draw_shape.c key_hook.c\

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME): $(OBJS)
	$(GCC) $(CFLAGS) -I $(HEADERS) -c $(SRC)
	$(GCC) -o $(NAME) $(OBJ) -lm -L libft/ -lft $(FLAGS2)

.PHONY: clean fclean re

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
