/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:44:34 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/06 16:17:22 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_consts(void)
{
	g_consts.tile_size = 64;
	g_consts.map_num_rows = g_data_cub.map_j;
	g_consts.map_num_cols = g_data_cub.map_i;
	g_consts.window_width = g_consts.map_num_cols * g_consts.tile_size;
	g_consts.window_height = g_consts.map_num_rows * g_consts.tile_size;
	g_consts.display_window_width = g_data_cub.r_x;
	g_consts.display_window_height = g_data_cub.r_y;
	g_consts.ray_width = 1;
	g_consts.num_of_rays = g_consts.display_window_width / g_consts.ray_width;
	g_consts.fov_ang = 60 * (PI / 180);
	g_consts.angleinc = g_consts.fov_ang / g_consts.num_of_rays;
	g_consts.first_ray_ang = g_player.rotationangle - (g_consts.fov_ang / 2);
	g_consts.last_ray_ang = g_player.rotationangle + (g_consts.fov_ang / 2);
	g_sprite.startfov = g_player.rotationangle - (g_consts.fov_ang / 2);
	g_sprite.startfov = fmod_angle(g_sprite.startfov);
	g_sprite.endfov = g_player.rotationangle + (g_consts.fov_ang / 2);
	g_sprite.endfov = fmod_angle(g_sprite.endfov);
}

void	position_initial_player(void)
{
	if (g_data_cub.playerdirect == 'N')
		g_player.rotationangle = PI * 0.5;
	else if (g_data_cub.playerdirect == 'E')
		g_player.rotationangle = PI;
	else if (g_data_cub.playerdirect == 'S')
		g_player.rotationangle = PI * 1.5;
	else if (g_data_cub.playerdirect == 'W')
		g_player.rotationangle = 0;
}

void	init_player(void)
{
	g_player.x = g_data_cub.playerj * g_consts.tile_size
	+ (g_consts.tile_size / 2);
	g_player.y = g_data_cub.playeri * g_consts.tile_size
	+ (g_consts.tile_size / 2);
	g_player.radius = 7;
	position_initial_player();
	g_player.turndirection = 0;
	g_player.walkdirection = 0;
	g_player.strafe = 0;
	g_player.movespeed = 12;
	g_player.rotationspeed = 7 * (PI / 180);
}

void	init_rotationangle(void)
{
	if (g_player.turndirection == 1)
		g_player.rotationangle += g_player.rotationspeed;
	if (g_player.turndirection == -1)
		g_player.rotationangle -= g_player.rotationspeed;
}

float	fmod_angle(float angle)
{
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle = (2 * PI) + angle;
	return (angle);
}
