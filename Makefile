# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/13 00:03:46 by sbensarg          #+#    #+#              #
#    Updated: 2020/11/20 17:20:23 by sbensarg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  GNL/*.c cub3d.c cub3d_utils.c read_data.c ft_atoi.c ft_memcpy.c ft_strjoin.c ft_strdup.c ft_strlen.c ft_substr.c init_functions.c render_map.c render_player.c render_rays.c render_sprites.c write_bmp.c -D BUFFER_SIZE=10

all:
	gcc -I minilibx -lmlx -framework OpenGL -framework AppKit $(SRCS) -o cub3d
	./cub3d map.cub
test:
	gcc -I minilibx -lmlx -framework OpenGL -framework AppKit -g cub3d_test.c cub3d_utils.c -o cub3d_map
	./cub3d_map