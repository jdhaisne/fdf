# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/12 13:52:30 by jdhaisne          #+#    #+#              #
#    Updated: 2016/02/12 14:32:31 by jdhaisne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = draw.c \
	  draw2.c \
	  main.c \
	  read.c \
	  get_next_line/get_next_line.c

OBJ = draw.o \
	  draw2.o \
	  main.o \
	  read.o \
	  get_next_line.o

LIB = libft.a

CFLAG = -Wall -Werror -Wextra

LIBFT_DIR = libft

MLX_FLAG = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) :
	make -C $(LIBFT_DIR) re
	gcc -c $(SRC) $(CFLAG)
	gcc -o $(NAME) $(OBJ) $(LIBFT_DIR)/$(LIB) $(MLX_FLAG)
	
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
