# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pschmunk <pschmunk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 14:56:59 by pschmunk          #+#    #+#              #
#    Updated: 2025/03/22 21:46:58 by pschmunk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC =	sources/init.c			\
		sources/key_inputs.c	\
		sources/main.c			\
		sources/raycasting.c	\
		sources/render.c		\
		sources/utils.c			\
		sources/textures.c		\

CC = gcc

CFLAGS = -Wall -Werror -Wextra -no-pie

OBJ = $(SRC:.c=.o)

MLX_PATH = ./mlx_linux

LIBFT_PATH = ./libft

MLX_NAME = libmlx.a

MLX_FLAGS = -L$(MLX_PATH) -lmlx_Linux -lX11 -lXext -lm

all: $(NAME) $(OBJ) $(LIBFT)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_PATH)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS) $(LIBFT_PATH)/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -I./minilibx-linux -c -o $@ $<

clean:
	rm -f $(OBJ)
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) fclean
    
fclean: clean
	rm -f $(NAME)
    
re: fclean all

.PHONY: all bonus clean fclean re
