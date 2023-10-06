# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 15:15:48 by snagulap          #+#    #+#              #
#    Updated: 2023/10/06 10:47:38 by snagulap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

CC=cc
CFLAGS=-Wall -Wextra -Werror -fsanitize=address

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/

CFILES=main.c vec.c
OFILES=main.o vec.o

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