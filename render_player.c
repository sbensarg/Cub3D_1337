/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:26:35 by sbensarg          #+#    #+#             */
/*   Updated: 2020/11/23 02:19:56 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	clear_old_pos(int x, int y)
{
	int		xa;
	int		ya;
	float  angle;

	angle = PI / 2;
	while (angle > 0)
	{
		xa = cos(angle) * player.radius;
		ya = sin(angle) * player.radius;
		my_mlx_pixel_put(x - xa, y - ya, 0x00FFFFFF);
		my_mlx_pixel_put(x + xa, y + ya, 0x00FFFFFF);
		my_mlx_pixel_put(x - xa, y + ya, 0x00FFFFFF);
		my_mlx_pixel_put(x + xa, y - ya, 0x00FFFFFF);
		angle -= 0.01;
	}
}

void	render_player(int color)
{
	int		xa;
	int		ya;
	float	angle;
	int j = 0;

	angle = PI / 2;
	while (angle > 0)
	{
		xa = cos(angle) * player.radius;
		ya = sin(angle) * player.radius;
		my_mlx_pixel_put(player.x - xa, player.y - ya, color);
		my_mlx_pixel_put(player.x + xa, player.y + ya, color);
		my_mlx_pixel_put(player.x - xa, player.y + ya, color);
		my_mlx_pixel_put(player.x + xa, player.y - ya, color);
		angle -= 0.01;
	}
	while (j < 12)
	{
		xa = player.x - cos(player.rotationangle) * (j);
		ya = player.y - sin(player.rotationangle) * (j);
		my_mlx_pixel_put(xa, ya, 0x00757872);
		j += 1;
	}
}
