/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:52:27 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/22 19:25:50 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dep_cam(int direction)
{
	g_player.movestep = 0;
	g_player.newplayerx = 0;
	g_player.newplayery = 0;
	g_player.movestep = g_player.movespeed;
	g_player.angle = g_player.rotationangle + ((PI / 2) * direction);
	g_player.newplayerx = g_player.x + cos(g_player.angle) * g_player.movestep;
	g_player.newplayery = g_player.y + sin(g_player.angle) * g_player.movestep;
	if (nextposallowed(g_player.newplayerx, g_player.newplayery) == 0)
	{
		g_player.x = g_player.newplayerx;
		g_player.y = g_player.newplayery;
	}
}

int		update(void)
{
	g_player.movestep = 0;
	g_player.newplayerx = 0;
	g_player.newplayery = 0;
	g_player.movestep += g_player.walkdirection * g_player.movespeed;
	g_player.newplayerx = g_player.x +
		cos(g_player.rotationangle) * g_player.movestep;
	g_player.newplayery = g_player.y +
		sin(g_player.rotationangle) * g_player.movestep;
	if (nextposallowed(g_player.newplayerx, g_player.newplayery) == 0)
	{
		g_player.x = g_player.newplayerx;
		g_player.y = g_player.newplayery;
	}
	init_rotationangle();
	if (g_player.strafe != 0)
		dep_cam(g_player.strafe);
	render_rays();
	rendersprites();
	mlx_put_image_to_window(g_data.mlx_ptr, g_data.mlx_win, g_img.img, 0, 0);
	return (0);
}

void	mlx_hooks(void)
{
	mlx_hook(g_data.mlx_win, 2, 1L << 0, ft_keypressed, 0);
	mlx_hook(g_data.mlx_win, 3, 1L << 1, ft_keyreleased, 0);
	mlx_hook(g_data.mlx_win, 17, 1L << 0, ft_close, 0);
	mlx_loop_hook(g_data.mlx_ptr, update, 0);
	mlx_loop(g_data.mlx_ptr);
}

int		init_window(void)
{
	if ((g_data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((g_data.mlx_win =
	mlx_new_window(g_data.mlx_ptr, g_consts.display_window_width,
	g_consts.display_window_height, "cub3D")) == NULL)
		return (EXIT_FAILURE);
	g_img.img = mlx_new_image(g_data.mlx_ptr, g_consts.display_window_width,
	g_consts.display_window_height);
	g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bits_per_pixel,
	&g_img.line_length, &g_img.endian);
	mlx_put_image_to_window(g_data.mlx_ptr, g_data.mlx_win, g_img.img, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	init_struct();
	if (argc == 2 || argc == 3)
	{
		if (ft_read_from_dotcub(argv[1]) == -1)
			ft_print_perror();
		init_consts();
		init_player();
		init_window();
		init_texture();
		render_rays();
		rendersprites();
		if (argc == 3)
		{
			if (!ft_strncmp(argv[2], "--save", 7))
				write_bmp("cub3d.bmp", g_img.addr);
			else
				ft_print_err("invalide argument!!");
			exit(0);
		}
		mlx_hooks();
		return (EXIT_SUCCESS);
	}
	else
		ft_print_err("invalide argument!!");
}
