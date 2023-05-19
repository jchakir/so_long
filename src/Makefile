# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchakir <jchakir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 14:01:46 by jchakir           #+#    #+#              #
#    Updated: 2022/02/10 16:26:14 by jchakir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = so_long
SOURCE_FILES = source/putendl_fd.c source/split.c source/itoa.c \
				source/strdup.c source/strjoin.c source/strlen.c \
				source/strncmp.c source/strrchr.c

FILES = $(SOURCE_FILES)
FILES += check_ext_and_read_map.c errors_and_free.c images_process.c so_long.c \
		read_and_check_valid_map.c moves_process.c main.c 

OBJ = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -Imlx -c $< -o $@

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJ)

re: fclean all
