/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:52:27 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/07 16:30:59 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_textureoffsetx(void)
{
	if (g_ray.vert)
	{
		g_textureoffsetx = (int)g_ray.v_wallhity % g_consts.tile_size;
		if (g_pos.angleisleft)
			g_texturenum = 0;
		else
			g_texturenum = 2;
	}
	else
	{
		g_textureoffsetx = (int)g_ray.h_wallhitx % g_consts.tile_size;
		if (g_pos.angleisup)
			g_texturenum = 1;
		else
			g_texturenum = 3;
	}
}

void	checkangle(float angle)
{
	if (angle > 0 && angle < PI)
		g_pos.angleisup = 1;
	else
		g_pos.angleisdown = 1;
	if ((angle > 0 && angle < PI / 2) || (angle > 1.5 * PI && angle < 2 * PI))
		g_pos.angleisleft = 1;
	else
		g_pos.angleisright = 1;
}

void	reset_angles(void)
{
	g_pos.angleisup = 0;
	g_pos.angleisleft = 0;
	g_pos.angleisdown = 0;
	g_pos.angleisright = 0;
	g_ray.angel = 0;
}

float	putray(float angle)
{
	g_ray.vert = 0;
	g_ray.angel = angle;
	angle = fmod_angle(angle);
	checkangle(angle);
	g_ray.horz_hit_distance =
	(ft_nexthorztinter(&g_ray.h_wallhitx, &g_ray.h_wallhity))
	? sqrt((g_ray.h_wallhitx - g_player.x) * (g_ray.h_wallhitx - g_player.x)
	+ (g_ray.h_wallhity - g_player.y) * (g_ray.h_wallhity - g_player.y))
		: MAX_VALUE;
	g_ray.vert_hit_distance =
	(ft_nextvertinter(&g_ray.v_wallhitx, &g_ray.v_wallhity))
	? sqrt((g_ray.v_wallhitx - g_player.x) * (g_ray.v_wallhitx - g_player.x)
	+ (g_ray.v_wallhity - g_player.y) * (g_ray.v_wallhity - g_player.y))
		: MAX_VALUE;
	if (g_ray.vert_hit_distance < g_ray.horz_hit_distance)
	{
		g_ray.distance = g_ray.vert_hit_distance;
		g_ray.vert = 1;
	}
	else
		g_ray.distance = g_ray.horz_hit_distance;
	calc_textureoffsetx();
	reset_angles();
	return (g_ray.distance);
}
