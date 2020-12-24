/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 12:44:34 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/24 18:03:07 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	init_consts(void)
// {
// 	consts.tile_size = 64;
// 	consts.map_num_rows = data_cub.map_j;
// 	consts.map_num_cols = data_cub.map_i;
// 	consts.window_width = consts.map_num_cols * consts.tile_size;
// 	consts.window_height = consts.map_num_rows * consts.tile_size;
// 	consts.display_window_width = consts.window_width;
// 	consts.display_window_height = consts.window_height;
// 	consts.ray_width = 1;
// 	consts.num_of_rays = consts.display_window_width/ consts.ray_width;
// 	consts.fov_ang = 60 * (PI / 180);
// 	consts.angleinc = consts.fov_ang / consts.num_of_rays;
// }

void	init_consts(void)
{
	consts.tile_size = 64;
	consts.map_num_rows = data_cub.map_j;
	consts.map_num_cols = data_cub.map_i;
	consts.window_width = consts.map_num_cols * consts.tile_size;
	consts.window_height = consts.map_num_rows * consts.tile_size;
	consts.display_window_width = data_cub.R_x;
	consts.display_window_height = data_cub.R_y;
	consts.ray_width = 1;
	consts.num_of_rays = consts.display_window_width/ consts.ray_width;
	consts.fov_ang = 60 * (PI / 180);
	consts.angleinc = consts.fov_ang / consts.num_of_rays;
	consts.first_ray_ang = player.rotationangle - (consts.fov_ang / 2);
	consts.last_ray_ang = player.rotationangle + (consts.fov_ang / 2);
}

void    position_initial_player()
{
	if (data_cub.playerdirect == 'N')
		player.rotationangle = PI * 0.5;
	else if (data_cub.playerdirect == 'E')
		player.rotationangle = PI;
	else if (data_cub.playerdirect == 'S')
		player.rotationangle = PI * 1.5;
	else if (data_cub.playerdirect == 'W')
		player.rotationangle = 0;
}

void	init_player(void)
{
	player.x = data_cub.playerJ * consts.tile_size + (consts.tile_size / 2);
	player.y = data_cub.playerI * consts.tile_size + (consts.tile_size / 2);
	player.radius = 7;
	position_initial_player();
	player.turndirection = 0;	
	player.walkdirection = 0;
	player.strafe = 0;
	player.movespeed = 12;
	player.rotationspeed = 5 * (PI / 180);
}

void	fmod_angle(float angle)
{
    angle = fmod(angle, 2 * PI);
        if (angle < 0)
            angle = (2 * PI) + angle;
}