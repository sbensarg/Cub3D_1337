/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:52:27 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/02 17:43:36 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dep_cam(int direction)
{
	player.movestep = 0;
	player.newplayerx = 0;
	player.newplayery = 0;
	player.movestep = player.movespeed;
	player.angle = player.rotationangle + ((PI / 2) * direction);
	player.newplayerx = player.x + cos(player.angle) * player.movestep;
	player.newplayery = player.y + sin(player.angle) * player.movestep;
	if (nextposallowed(player.newplayerx, player.newplayery) == 0)
	{
		player.x = player.newplayerx;
		player.y = player.newplayery;
	}
}

int		update(void)
{
	player.movestep = 0;
	player.newplayerx = 0;
	player.newplayery = 0;
	player.movestep += player.walkdirection * player.movespeed;
	player.newplayerx = player.x + cos(player.rotationangle) * player.movestep;
	player.newplayery = player.y + sin(player.rotationangle) * player.movestep;
	if (nextposallowed(player.newplayerx, player.newplayery) == 0)
	{
		player.x = player.newplayerx;
		player.y = player.newplayery;
	}
	init_rotationangle();
	if (player.strafe != 0)
		dep_cam(player.strafe);
	render_rays();
	rendersprites();
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, img.img, 0, 0);
	return (0);
}

void	mlx_hooks(void)
{
	mlx_hook(data.mlx_win, 2, 1L << 0, ft_keypressed, 0);
	mlx_hook(data.mlx_win, 3, 1L << 1, ft_keyreleased, 0);
	mlx_hook(data.mlx_win, 17, 1L << 0, ft_close, 0);
	mlx_loop_hook(data.mlx_ptr, update, 0);
	mlx_loop(data.mlx_ptr);
}

int		init_window(void)
{
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win =
	mlx_new_window(data.mlx_ptr, consts.display_window_width,
	consts.display_window_height, "cub3D")) == NULL)
		return (EXIT_FAILURE);
	img.img = mlx_new_image(data.mlx_ptr, consts.display_window_width,
	consts.display_window_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	&img.line_length, &img.endian);
	return (0);
}

int		main(int argc, char **argv)
{
	init_struct();
	if (argc >= 2)
	{
		if (ft_read_from_dotcub(argv[1]) == -1)
		{
			perror("Error: ");
			return (-1);
		}
		init_consts();
		init_player();
		init_window();
		init_texture();
		render_rays();
		rendersprites();
		if (argc == 3)
		{
			if (!ft_strncmp(argv[2], "--save", 7))
				write_bmp("cub3d.bmp", img.addr);
			else
				ft_print_err("invalide argument!!");
			exit(0);
		}
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, img.img, 0, 0);
		mlx_hooks();
		return (EXIT_SUCCESS);
	}
}
