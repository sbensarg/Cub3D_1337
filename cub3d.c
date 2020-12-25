/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:52:27 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/25 11:43:07 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dep_cam(int	direction)
{
	float	movestep;
	float	newplayerx;
	float	newplayery;
	float	checkplayerx;
	float	checkplayery;
	int		posallowed;
	
	movestep = player.movespeed;
	float angle = player.rotationangle + ((PI / 2) * direction);
	newplayerx = player.x + cos(angle) * movestep;
	newplayery = player.y + sin(angle) * movestep;
	if (nextposallowed(newplayerx, newplayery) == 0)
	{
		player.x = newplayerx;
		player.y = newplayery;
	}
}
void	update(void)
{
	float	movestep;
	float	newplayerx;
	float	newplayery;
	float	checkplayerx;
	float	checkplayery;
	int		posallowed;
	
	movestep += player.walkdirection * player.movespeed;
	newplayerx = player.x + cos(player.rotationangle) * movestep;
	newplayery = player.y + sin(player.rotationangle) * movestep;
	if (nextposallowed(newplayerx, newplayery) == 0)
	{
		posallowed = 1;
		while (movestep != 0)
		{
			checkplayerx = player.x + cos(player.rotationangle) * movestep;
			checkplayery = player.y + sin(player.rotationangle) * movestep;
			if (nextposallowed(checkplayerx, checkplayery) == 1)
			{
				posallowed = 0;
				break ;
			}
			if (movestep > 0)
				movestep--;
			else
				movestep++;
		}
	}
	if (posallowed == 1)
	{
		player.x = newplayerx;
		player.y = newplayery;
	}
	else
	{
		if (nextposallowed(newplayerx, player.y) == 0)
			player.x = newplayerx;
		else if (nextposallowed(player.x, newplayery) == 0)
			player.y = newplayery;
	}
	if (player.turndirection == 1)
		player.rotationangle += player.rotationspeed;
	if (player.turndirection == -1)
		player.rotationangle -= player.rotationspeed;
	if (player.strafe != 0)
		dep_cam(player.strafe);
	//render_rays();
	
    //render_map();
    //render_player(0x00000000);
	render_rays();
	rendersprites();
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, img.img, 0, 0);
}

int		ft_close()
{
	mlx_destroy_image(data.mlx_ptr ,img.img);
	mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	exit(0);
	return(0);
}

int		ft_keypressed(int keycode, void *lol)
{
	if (keycode == KEY_RIGHT)
		player.turndirection = 1;
	if (keycode == KEY_LEFT)
		player.turndirection = -1;
	if (keycode == KEY_W)
		player.walkdirection = -1;
	if (keycode == KEY_S)
		player.walkdirection = 1;
	if (keycode == KEY_A)
		player.strafe = 1;
	if (keycode == KEY_D)
		player.strafe = -1;
	if (keycode == esc)
		ft_close();
	update();
	return (0);
}

int		ft_keyreleased(int keycode, void *lol)
{
	if (keycode == KEY_RIGHT)
		player.turndirection = 0;
	if (keycode == KEY_LEFT)
		player.turndirection = 0;
	if (keycode == KEY_W)
		player.walkdirection = 0;
	if (keycode == KEY_S)
		player.walkdirection = 0;
	if (keycode == KEY_A)
		player.strafe = 0;
	if (keycode == KEY_D)
		player.strafe = 0;
	update();
	return (0);
}
void	init_texture()
{
	texture[0].img = mlx_xpm_file_to_image(data.mlx_ptr,data_cub.NO,&texture[0].tw, &texture[0].th);
	if (texture[0].img == NULL)
		 ft_print_err("ivalide xpm (NO)");
	texture[0].addr = mlx_get_data_addr(texture[0].img, &texture[0].bits_per_pixel, &texture[0].line_length,
	&texture[0].endian);
	texture[1].img = mlx_xpm_file_to_image(data.mlx_ptr,data_cub.SO,&texture[1].tw, &texture[1].th);
	if (texture[1].img == NULL)
		 ft_print_err("ivalide xpm (SO)");
	texture[1].addr = mlx_get_data_addr(texture[1].img, &texture[1].bits_per_pixel, &texture[1].line_length,
	&texture[1].endian);
	texture[2].img = mlx_xpm_file_to_image(data.mlx_ptr,data_cub.EA,&texture[2].tw, &texture[2].th);
	if (texture[2].img == NULL)
		 ft_print_err("ivalide xpm (EA)");
	texture[2].addr = mlx_get_data_addr(texture[2].img, &texture[2].bits_per_pixel, &texture[2].line_length,
	&texture[2].endian);
	texture[3].img = mlx_xpm_file_to_image(data.mlx_ptr,data_cub.WE,&texture[3].tw, &texture[3].th);
	if (texture[3].img == NULL)
		 ft_print_err("ivalide xpm (WE)");
	texture[3].addr = mlx_get_data_addr(texture[3].img, &texture[3].bits_per_pixel, &texture[3].line_length,
	&texture[3].endian);
	texture[4].img = mlx_xpm_file_to_image(data.mlx_ptr,data_cub.S,&texture[4].tw, &texture[4].th);
	if (texture[4].img == NULL)
		 ft_print_err("ivalide xpm (S)");
	texture[4].addr = mlx_get_data_addr(texture[4].img, &texture[4].bits_per_pixel, &texture[4].line_length,
	&texture[4].endian);
}
int		main(int argc, char **argv)
{
	int	i;
	int	j;


	i = 0;
	j = 0;
	if (argc >= 2)
	{
		if (ft_read_from_dotcub(argv[1]) == -1)
		{
			perror("Error: ");
			return(-1);
		}
		init_consts();
		init_player();
		if ((data.mlx_ptr = mlx_init()) == NULL)
			return (EXIT_FAILURE);
		if ((data.mlx_win = mlx_new_window(data.mlx_ptr, consts.display_window_width, consts.display_window_height, "cub3D")) == NULL)
			return (EXIT_FAILURE);
		img.img = mlx_new_image(data.mlx_ptr, consts.display_window_width, consts.display_window_height);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);
		
		init_texture();
		//render_map();
    	//render_player(0x00000000);
		render_rays();
		rendersprites();
		if (argc == 3)
		{
			if (!strcmp(argv[2], "--save"))
				write_bmp("cub.bmp", img.addr);
			else
				ft_print_err("invalide argument!!");
			exit(0);
		}
		mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, img.img, 0, 0);
		// mlx_hook(data.mlx_win, 2, 1L << 1, ft_keypressed, 0);
		// mlx_hook(data.mlx_win, 3, 1L << 2, ft_keyreleased, 0);
		mlx_hook(data.mlx_win, 2, 1L << 0, ft_keypressed, 0);
		mlx_hook(data.mlx_win, 3, 1L << 1, ft_keyreleased, 0);
		mlx_hook(data.mlx_win, 17, 1L << 0, ft_close, 0);
		mlx_loop(data.mlx_ptr);
		return (EXIT_SUCCESS);
	}
}
