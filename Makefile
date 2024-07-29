# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ranaili <ranaili@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 10:21:48 by ranaili           #+#    #+#              #
#    Updated: 2021/02/24 11:13:04 by ranaili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean fclean re cub3D

NAME = cub3D

CC = clang

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

SRCS = 	./source/ft_dda_calcul.c \
	./source/ft_draw.c \
	./source/ft_init.c \
	./source/ft_mlx.c  \
	./source/ft_move.c \
	./source/ft_move2.c \
	./source/ft_sprite.c \
	./source/ft_texture.c \
	./source/ft_utils_move.c \
 	./source/map.c \
	./source/main.c \
	./source/parcing.c \
	./source/parcing_next.c \
	./source/parcing_utils.c \
	./source/parcing_utils_next.c \
	./source/parcing_map.c \
	./source/ft_utils.c \
	./source/ft_save_bmp.c \
	./source/ft_test_screen_size.c

all : $(NAME)

$(NAME) :
	@echo "\033[0;34mCreate the lib ..."
	cd libft && make re && cd ..
	@echo "\n\033[0;35mExecution ..."
	$(CC) $(CFLAGS) $(SRCS) -Lminilibx-linux -lmlx_Linux -Llibft -Imlx_linux -lXext -lX11 -lm -o $(NAME) libft/libft.a

clean :
	@echo "\033[0;36mCleaning ..."
	rm -f $(NAME)

fclean : clean
	@echo "\033[0m"

re : fclean all
