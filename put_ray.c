/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:52:27 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/29 12:54:48 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_textureoffsetx(void)
{
	if (ray.vert)
	{
		textureoffsetx = (int)ray.v_wallhity % consts.tile_size;
		if (pos.angleisleft)
			texturenum = 0;
		else
			texturenum = 2;
	}
	else
	{
		textureoffsetx = (int)ray.h_wallhitx % consts.tile_size;
		if (pos.angleisup)
			texturenum = 1;
		else
			texturenum = 3;
	}
}

void	checkangle(float angle)
{
	if (angle > 0 && angle < PI)
		pos.angleisup = 1;
	else
		pos.angleisdown = 1;
	if ((angle > 0 && angle < PI / 2) || (angle > 1.5 * PI && angle < 2 * PI))
		pos.angleisleft = 1;
	else
		pos.angleisright = 1;
}

void	reset_angles(void)
{
	pos.angleisup = 0;
	pos.angleisleft = 0;
	pos.angleisdown = 0;
	pos.angleisright = 0;
	ray.angel = 0;
}

float	putray(float angle)
{
	ray.vert = 0;
	ray.angel = angle;
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle = (2 * PI) + angle;
	checkangle(angle);
	ray.horz_hit_distance =
	(ft_nexthorztinter(&ray.h_wallhitx, &ray.h_wallhity))
	? sqrt((ray.h_wallhitx - player.x) * (ray.h_wallhitx - player.x)
	+ (ray.h_wallhity - player.y) * (ray.h_wallhity - player.y))
		: MAX_VALUE;
	ray.vert_hit_distance = (ft_nextvertinter(&ray.v_wallhitx, &ray.v_wallhity))
	? sqrt((ray.v_wallhitx - player.x) * (ray.v_wallhitx - player.x)
	+ (ray.v_wallhity - player.y) * (ray.v_wallhity - player.y))
		: MAX_VALUE;
	if (ray.vert_hit_distance < ray.horz_hit_distance)
	{
		ray.distance = ray.vert_hit_distance;
		ray.vert = 1;
	}
	else
		ray.distance = ray.horz_hit_distance;
	calc_textureoffsetx();
	reset_angles();
	return (ray.distance);
}
