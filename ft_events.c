/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:20:05 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/02 17:45:00 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(void)
{
	freestrct();
	mlx_destroy_image(data.mlx_ptr, img.img);
	mlx_destroy_window(data.mlx_ptr, data.mlx_win);
	system("leaks cub3D");
	exit(0);
	return (0);
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
	return (0);
}
