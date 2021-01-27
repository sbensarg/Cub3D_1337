# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/13 00:03:46 by sbensarg          #+#    #+#              #
#    Updated: 2021/01/27 10:44:16 by sbensarg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =  ../GNL/get_next_line.c\
		../GNL/get_next_line_utils.c\
		cub3d.c\
		cub3d_utils.c\
		read_data/check_map.c\
		read_data/ft_print_err.c\
		read_data/init_data.c\
		read_data/init_sprite_and_player.c\
		read_data/read_data.c\
		read_data/read_data_utils.c\
		read_data/rempli_map.c\
		read_data/resolution.c\
		read_data/rgb.c\
		read_data/textures.c\
		read_data/textures_utils.c\
		ft_atoi.c\
		ft_strtrim.c\
		ft_memcpy.c\
		ft_split.c\
		ft_memset.c\
		ft_strncmp.c\
		ft_strjoin.c\
		ft_strdup.c\
		ft_strlen.c\
		ft_substr.c\
		init_functions.c\
		render_rays.c\
		render_rays_utils.c\
		put_ray.c\
		render_sprites.c\
		render_sprite_utils.c\
		write_bmp.c\
		ft_free_all.c\
		ft_events.c

FLAGS=  -Wall -Wextra -Werror -D BUFFER_SIZE=10
MFLAGS = -I../minilibx_beta -I. -lmlx $(MLX) -framework OpenGL -framework AppKit
MLX = libmlx.dylib
rm = rm -f
CC = gcc

all : $(NAME)

$(NAME): $(MLX)
	@cp ../minilibx_beta/libmlx.dylib . && $(CC) $(MFLAGS) $(FLAGS) $(SRCS) -o $(NAME)
$(MLX):
	@$(MAKE) -C ../minilibx_beta
clean:
	@$(rm) $(NAME)
	@$(rm) $(MLX)
	@$(MAKE) -C ../minilibx_beta clean
fclean: clean
re: fclean all
