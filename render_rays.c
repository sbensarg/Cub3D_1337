/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:25:42 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/02 17:48:26 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_horz_wall_hit(void)
{
	hozinter.nexthorztouchy =
	floor(player.y / consts.tile_size) * consts.tile_size;
	hozinter.nexthorztouchy += pos.angleisdown ? consts.tile_size : 0;
	hozinter.nexthorztouchx =
	player.x + (hozinter.nexthorztouchy - player.y) / tan(ray.angel);
	hozinter.ystep = consts.tile_size;
	hozinter.ystep *= pos.angleisup ? -1 : 1;
	hozinter.xstep = consts.tile_size / tan(ray.angel);
	hozinter.xstep *= (pos.angleisleft && hozinter.xstep > 0) ? -1 : 1;
	hozinter.xstep *= (pos.angleisright && hozinter.xstep < 0) ? -1 : 1;
	hozinter.foundhorzwallhit = 0;
}

void	init_vert_wall_hit(void)
{
	vertinter.foundvertwallhit = 0;
	vertinter.nextverttouchx =
	floor(player.x / consts.tile_size) * consts.tile_size;
	vertinter.nextverttouchx += pos.angleisright ? consts.tile_size : 0;
	vertinter.nextverttouchy =
	player.y + (vertinter.nextverttouchx - player.x) * tan(ray.angel);
	vertinter.xstep = consts.tile_size;
	vertinter.xstep *= pos.angleisleft ? -1 : 1;
	vertinter.ystep = consts.tile_size * tan(ray.angel);
	vertinter.ystep *= (pos.angleisup && vertinter.ystep > 0) ? -1 : 1;
	vertinter.ystep *= (pos.angleisdown && vertinter.ystep < 0) ? -1 : 1;
}

int		ft_nexthorztinter(float *horzwallhitx, float *horzwallhity)
{
	init_horz_wall_hit();
	if (pos.angleisup)
		hozinter.nexthorztouchy--;
	while (hozinter.nexthorztouchx >= 0
	&& hozinter.nexthorztouchx <= consts.window_width
	&& hozinter.nexthorztouchy >= 0
	&& hozinter.nexthorztouchy <= consts.window_height)
	{
		if (iswall(hozinter.nexthorztouchx, hozinter.nexthorztouchy) == 1)
		{
			hozinter.foundhorzwallhit = 1;
			*horzwallhitx = hozinter.nexthorztouchx;
			*horzwallhity = hozinter.nexthorztouchy;
			break ;
		}
		else
		{
			hozinter.nexthorztouchx += hozinter.xstep;
			hozinter.nexthorztouchy += hozinter.ystep;
		}
	}
	if (pos.angleisup)
		*horzwallhity = *horzwallhity + 1;
	return (hozinter.foundhorzwallhit);
}

int		ft_nextvertinter(float *vertwallhitx, float *vertwallhity)
{
	init_vert_wall_hit();
	if (pos.angleisleft)
		vertinter.nextverttouchx--;
	while (vertinter.nextverttouchx >= 0
	&& vertinter.nextverttouchx <= consts.window_width
	&& vertinter.nextverttouchy >= 0
	&& vertinter.nextverttouchy <= consts.window_height)
	{
		if (iswall(vertinter.nextverttouchx, vertinter.nextverttouchy) == 1)
		{
			vertinter.foundvertwallhit = 1;
			*vertwallhitx = vertinter.nextverttouchx;
			*vertwallhity = vertinter.nextverttouchy;
			break ;
		}
		else
		{
			vertinter.nextverttouchx += vertinter.xstep;
			vertinter.nextverttouchy += vertinter.ystep;
		}
	}
	if (pos.angleisleft)
		*vertwallhitx = *vertwallhitx + 1;
	return (vertinter.foundvertwallhit);
}

void	render_rays(void)
{
	ray.ray = 0;
	ray.ray_lenght = 0;
	init_consts();
	raydistance = malloc(sizeof(float) * consts.num_of_rays);
	while (ray.ray < consts.num_of_rays)
	{
		ray.ray_lenght = putray(consts.first_ray_ang);
		ray.correctdist = ray.ray_lenght *
		cos(fabs(consts.first_ray_ang - player.rotationangle));
		ray.distanceprojectionplane =
		(consts.window_width / 2) / tan(consts.fov_ang / 2);
		ray.wallstripheight =
		(consts.tile_size / ray.correctdist) * ray.distanceprojectionplane;
		ray.wallstripheight_d = (consts.display_window_width
		* ray.wallstripheight) / consts.window_width;
		draw_wall(ray.ray * consts.ray_width,
		(consts.display_window_height / 2) - (ray.wallstripheight_d / 2),
		ray.wallstripheight_d);
		consts.first_ray_ang += consts.angleinc;
		raydistance[ray.ray] = ray.ray_lenght;
		ray.ray++;
	}
}
