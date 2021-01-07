# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/13 00:03:46 by sbensarg          #+#    #+#              #
#    Updated: 2021/01/06 19:36:55 by sbensarg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ../GNL/*.c cub3d.c cub3d_utils.c read_data/*.c ft_atoi.c ft_strtrim.c ft_memcpy.c ft_split.c ft_memset.c ft_strncmp.c ft_strjoin.c ft_strdup.c ft_strlen.c ft_substr.c init_functions.c render_rays.c render_rays_utils.c put_ray.c render_sprites.c render_sprite_utils.c write_bmp.c ft_free_all.c ft_events.c -D BUFFER_SIZE=10
FLAGS= -Wall -Wextra -Werror

all: minilibx
	cp ../minilibx_beta/libmlx.dylib . && gcc  -I minilibx -lmlx libmlx.dylib -framework OpenGL -framework AppKit $(SRCS) -o cub3D
minilibx:
	cd ../minilibx_beta && $(MAKE)
clean:
	rm -f cub3D
	rm -f libmlx.dylib
fclean: clean
	cd ../minilibx_beta && $(MAKE) clean
re: fclean all