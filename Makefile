# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboudy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:53:12 by dboudy            #+#    #+#              #
#    Updated: 2016/01/19 16:02:37 by dboudy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF
GCC = gcc
CFLAGS = -lmlx -framework OpenGL -framework AppKit
HEADERS = includes/
SRCS = fdf.c draw_form.c \

all: $(NAME)

$(NAME): $(OBJS)
	 $(GCC) $(CFLAGS) $(SRCS) -I $(HEADERS) -o $(NAME)

.PHONY: clean fclean re mrproper

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) 

mrproper: all clean

re: fclean all
