# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 15:15:48 by snagulap          #+#    #+#              #
#    Updated: 2024/01/14 16:39:41 by snagulap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

CC=cc
CFLAGS=-Wall -Wextra -Werror -fsanitize=address -g

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/

# CFILES= cam_init.c ray.c  vec1,c vec2.c vec.c 
CFILES= main.c vec.c ray.c shapes.c colors.c vec1.c vec2.c camera.c\
		ft_init_get_data.c ft_init_utils.c ft_init.c ft_init_check_input.c \
		ft_init_check_float.c
# OFILES= cam_init.o ray.o vec.o vec1.o vec2.o
OFILES= main.o vec.o ray.o shapes.o colors.o vec1.o vec2.o camera.o\
		ft_init_get_data.o ft_init_utils.o ft_init.o ft_init_check_input.o \
		ft_init_check_float.o
SRC=$(addprefix $(SRC_DIR), $(CFILES))
OBJ=$(addprefix $(OBJ_DIR), $(OFILES))


LIBFT=./libft/libft.a
MLX=./mlx/libmlx.a

MAKE=make

all:$(NAME)

$(NAME): $(MLX) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	@cd ./libft && $(MAKE)

$(MLX):
	@cd ./mlx && $(MAKE) &> out
	rm ./mlx/out

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -Imlx -c -o $@ $^

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	fi;
	@cd ./libft && $(MAKE) clean
	@cd ./mlx && $(MAKE) clean
	@echo "Cleaned"

fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	fi;
	rm -f $(LIBFT)

re: fclean all

norm:
	norminette ./libft/* $(SRC) include/miniRT.h

bonus: all