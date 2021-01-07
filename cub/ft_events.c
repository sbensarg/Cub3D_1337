/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:20:05 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/07 18:47:29 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(void)
{
	freestrct();
	mlx_destroy_image(g_data.mlx_ptr, g_img.img);
	mlx_destroy_window(g_data.mlx_ptr, g_data.mlx_win);
	exit(0);
	return (0);
}

int		ft_keypressed(int keycode, void *lol)
{
	if (keycode == KEY_RIGHT)
		g_player.turndirection = 1;
	if (keycode == KEY_LEFT)
		g_player.turndirection = -1;
	if (keycode == KEY_W)
		g_player.walkdirection = -1;
	if (keycode == KEY_S)
		g_player.walkdirection = 1;
	if (keycode == KEY_A)
		g_player.strafe = 1;
	if (keycode == KEY_D)
		g_player.strafe = -1;
	if (keycode == ESC)
		ft_close();
	return (0);
}

int		ft_keyreleased(int keycode, void *lol)
{
	if (keycode == KEY_RIGHT)
		g_player.turndirection = 0;
	if (keycode == KEY_LEFT)
		g_player.turndirection = 0;
	if (keycode == KEY_W)
		g_player.walkdirection = 0;
	if (keycode == KEY_S)
		g_player.walkdirection = 0;
	if (keycode == KEY_A)
		g_player.strafe = 0;
	if (keycode == KEY_D)
		g_player.strafe = 0;
	return (0);
}
