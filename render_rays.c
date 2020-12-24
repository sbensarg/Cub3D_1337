/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:25:42 by sbensarg          #+#    #+#             */
/*   Updated: 2020/11/26 20:30:52 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int		ft_nexthorztinter(float *horzWallHitX, float *horzWallHitY)
{
	int	foundHorzWallHit;
	float	xstep;
	float	ystep;
	float	nextHorzTouchY;
	float	nextHorzTouchX;

	nextHorzTouchY = floor(player.y / consts.tile_size) * consts.tile_size;
	nextHorzTouchY += pos.angleisdown ? consts.tile_size : 0;
	nextHorzTouchX = player.x + (nextHorzTouchY - player.y) / tan(ray.angel);
	ystep = consts.tile_size;
	ystep *= pos.angleisup ? -1 : 1;
	xstep = consts.tile_size / tan(ray.angel);
	xstep *= (pos.angleisleft && xstep > 0) ? -1 : 1;
	xstep *= (pos.angleisright && xstep < 0) ? -1 : 1;
	foundHorzWallHit = 0;
	if (pos.angleisup)
		nextHorzTouchY--;
	while (nextHorzTouchX >= 0 && nextHorzTouchX <= consts.window_width
	 && nextHorzTouchY >= 0 && nextHorzTouchY <= consts.window_height)
	{
		if (iswall(nextHorzTouchX, nextHorzTouchY) == 1)
		{
			foundHorzWallHit = 1;
			*horzWallHitX = nextHorzTouchX;
			*horzWallHitY = nextHorzTouchY;
			break ;
		}
		else
		{
			nextHorzTouchX += xstep;
			nextHorzTouchY += ystep;
		}
	}
	if (pos.angleisup)
		*horzWallHitY = *horzWallHitY + 1;
	return (foundHorzWallHit);
}

int		ft_nextvertinter(float	*vertWallHitX, float	*vertWallHitY)
{
	int		foundVertWallHit;
	float	xstep;
	float	ystep;
	float	nextVertTouchX;
	float	nextVertTouchY;

	foundVertWallHit = 0;
	nextVertTouchX = floor(player.x / consts.tile_size) * consts.tile_size;
	nextVertTouchX += pos.angleisright ? consts.tile_size : 0;
	nextVertTouchY = player.y + (nextVertTouchX - player.x) * tan(ray.angel);
	xstep = consts.tile_size;
	xstep *= pos.angleisleft ? -1 : 1;
	ystep = consts.tile_size * tan(ray.angel);
	ystep *= (pos.angleisup && ystep > 0) ? -1 : 1;
	ystep *= (pos.angleisdown && ystep < 0) ? -1 : 1;
	if (pos.angleisleft)
		nextVertTouchX--;
	while (nextVertTouchX >= 0 && nextVertTouchX <= consts.window_width
	 && nextVertTouchY >= 0 && nextVertTouchY <= consts.window_height)
	{
		if (iswall(nextVertTouchX, nextVertTouchY) == 1)
		{
			foundVertWallHit = 1;
			*vertWallHitX = nextVertTouchX;
			*vertWallHitY = nextVertTouchY;
			break;
		}
		else
		{
			nextVertTouchX += xstep;
			nextVertTouchY += ystep;
		}
	}
	if (pos.angleisleft)
		*vertWallHitX = *vertWallHitX + 1;
	return (foundVertWallHit);
}

void check_derection(float angle)
{
	if (angle > PI * 0.25 && angle < PI * 0.75)
		pos.angleisup = 1;
	else if (angle > PI * 0.25 && angle < PI * 1.75)
		pos.angleisright = 1;
	else if (angle < PI * 1.75 && angle > PI * 1.25)
		pos.angleisdown = 1;
	else if (angle < PI * 1.25 && angle > PI * 0.75)
		pos.angleisleft = 1;
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

float	putray(float angle)
{
	float	VwallHitX;
	float	VwallHitY;
	float	HwallHitX;
	float	HwallHitY;
	float	distance;
	float	horzHitDistance;
	float	vertHitDistance;
	int vert = 0;

	ray.angel = angle;
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle = (2 * PI) + angle;
	checkangle(angle);
	horzHitDistance = (ft_nexthorztinter(&HwallHitX, &HwallHitY))
? sqrt((HwallHitX - player.x) * (HwallHitX - player.x) + (HwallHitY - player.y) * (HwallHitY - player.y))
		: MAX_VALUE;
	vertHitDistance = (ft_nextvertinter(&VwallHitX, &VwallHitY))
		? sqrt((VwallHitX - player.x) * (VwallHitX - player.x) + (VwallHitY - player.y) * (VwallHitY - player.y))
		: MAX_VALUE;
	if (vertHitDistance < horzHitDistance)
	{
		distance = vertHitDistance;
		vert = 1;
	}
	else
		distance = horzHitDistance;
	if (vert)
	{
		textureoffsetx = (int)VwallHitY % consts.tile_size;
		if (pos.angleisleft)
			texturenum = 0;
		else
			texturenum = 2;
	}
	else
	{
		textureoffsetx = (int)HwallHitX % consts.tile_size;
		if (pos.angleisup)
			texturenum = 1;
		else
			texturenum = 3;
	}
	pos.angleisup = 0;
	pos.angleisleft = 0;
	pos.angleisdown = 0;
	pos.angleisright = 0;
	ray.angel = 0;
	return (distance);
}

void	draw_wall(int tilex, int tiley, int height)
{
	int	i;
	int	j;
	int y;

	i = 0;
	j = 0;
    while (i < consts.ray_width)
	{
          while (j  <= tiley)
		{
			my_mlx_pixel_put(tilex + i, j, data_cub.C);
			j++;
		}
		j = 0;
		while (j < height)
		{
			if (tiley + j >= 0 && tiley + j < consts.display_window_height)
			{
				y = (consts.tile_size * j) / height;
				my_mlx_pixel_put(tilex + i, tiley + j,
				ft_read_from_memory(texture[texturenum],
				(textureoffsetx * texture[texturenum].tw) / consts.tile_size,
				(y * texture[texturenum].th) / consts.tile_size));
			}
			j++;
		}
		j = 0;
        while (tiley + height + j < consts.display_window_height)
		{
			my_mlx_pixel_put(tilex + i, tiley + height + j, data_cub.F);
			j++;
		}
		j = 0;
		i++;
	}
}

void	render_rays(void)
{
	float	ray_lenght;
	float	distanceprojectionplane;
	int		wallstripheight;
	int		wallstripheight_d;
	float	correctdist;
	

	ray.ray = 0;
	ray_lenght = 0;
	init_consts();
	raydistance = malloc(sizeof(float) * consts.num_of_rays);
	while (ray.ray < consts.num_of_rays)
	{
		ray_lenght = putray(consts.first_ray_ang);
		correctdist = ray_lenght * cos(fabs(consts.first_ray_ang - player.rotationangle));
		distanceprojectionplane = (consts.window_width / 2) / tan(consts.fov_ang / 2);
		wallstripheight = (consts.tile_size / correctdist) * distanceprojectionplane;
		wallstripheight_d = (consts.display_window_width * wallstripheight) / consts.window_width;
		draw_wall(ray.ray * consts.ray_width, (consts.display_window_height / 2) - (wallstripheight_d / 2), wallstripheight_d);
		consts.first_ray_ang += consts.angleinc;
		raydistance[ray.ray] = ray_lenght;
		ray.ray++;
	}
}