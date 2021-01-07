/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:25:42 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/06 17:00:34 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_horz_wall_hit(void)
{
	g_hozinter.nexthorztouchy =
	floor(g_player.y / g_consts.tile_size) * g_consts.tile_size;
	g_hozinter.nexthorztouchy += g_pos.angleisdown ? g_consts.tile_size : 0;
	g_hozinter.nexthorztouchx =
	g_player.x + (g_hozinter.nexthorztouchy - g_player.y) / tan(g_ray.angel);
	g_hozinter.ystep = g_consts.tile_size;
	g_hozinter.ystep *= g_pos.angleisup ? -1 : 1;
	g_hozinter.xstep = g_consts.tile_size / tan(g_ray.angel);
	g_hozinter.xstep *= (g_pos.angleisleft && g_hozinter.xstep > 0) ? -1 : 1;
	g_hozinter.xstep *= (g_pos.angleisright && g_hozinter.xstep < 0) ? -1 : 1;
	g_hozinter.foundhorzwallhit = 0;
}

void	init_vert_wall_hit(void)
{
	g_vertinter.foundvertwallhit = 0;
	g_vertinter.nextverttouchx =
	floor(g_player.x / g_consts.tile_size) * g_consts.tile_size;
	g_vertinter.nextverttouchx += g_pos.angleisright ? g_consts.tile_size : 0;
	g_vertinter.nextverttouchy =
	g_player.y + (g_vertinter.nextverttouchx - g_player.x) * tan(g_ray.angel);
	g_vertinter.xstep = g_consts.tile_size;
	g_vertinter.xstep *= g_pos.angleisleft ? -1 : 1;
	g_vertinter.ystep = g_consts.tile_size * tan(g_ray.angel);
	g_vertinter.ystep *= (g_pos.angleisup && g_vertinter.ystep > 0) ? -1 : 1;
	g_vertinter.ystep *= (g_pos.angleisdown && g_vertinter.ystep < 0) ? -1 : 1;
}

int		ft_nexthorztinter(float *horzwallhitx, float *horzwallhity)
{
	init_horz_wall_hit();
	if (g_pos.angleisup)
		g_hozinter.nexthorztouchy--;
	while (g_hozinter.nexthorztouchx >= 0
	&& g_hozinter.nexthorztouchx <= g_consts.window_width
	&& g_hozinter.nexthorztouchy >= 0
	&& g_hozinter.nexthorztouchy <= g_consts.window_height)
	{
		if (iswall(g_hozinter.nexthorztouchx, g_hozinter.nexthorztouchy) == 1)
		{
			g_hozinter.foundhorzwallhit = 1;
			*horzwallhitx = g_hozinter.nexthorztouchx;
			*horzwallhity = g_hozinter.nexthorztouchy;
			break ;
		}
		else
		{
			g_hozinter.nexthorztouchx += g_hozinter.xstep;
			g_hozinter.nexthorztouchy += g_hozinter.ystep;
		}
	}
	if (g_pos.angleisup)
		*horzwallhity = *horzwallhity + 1;
	return (g_hozinter.foundhorzwallhit);
}

int		ft_nextvertinter(float *vertwallhitx, float *vertwallhity)
{
	init_vert_wall_hit();
	if (g_pos.angleisleft)
		g_vertinter.nextverttouchx--;
	while (g_vertinter.nextverttouchx >= 0
	&& g_vertinter.nextverttouchx <= g_consts.window_width
	&& g_vertinter.nextverttouchy >= 0
	&& g_vertinter.nextverttouchy <= g_consts.window_height)
	{
		if (iswall(g_vertinter.nextverttouchx, g_vertinter.nextverttouchy) == 1)
		{
			g_vertinter.foundvertwallhit = 1;
			*vertwallhitx = g_vertinter.nextverttouchx;
			*vertwallhity = g_vertinter.nextverttouchy;
			break ;
		}
		else
		{
			g_vertinter.nextverttouchx += g_vertinter.xstep;
			g_vertinter.nextverttouchy += g_vertinter.ystep;
		}
	}
	if (g_pos.angleisleft)
		*vertwallhitx = *vertwallhitx + 1;
	return (g_vertinter.foundvertwallhit);
}

void	render_rays(void)
{
	g_ray.ray = 0;
	g_ray.ray_lenght = 0;
	init_consts();
	g_raydistance = malloc(sizeof(float) * g_consts.num_of_rays);
	while (g_ray.ray < g_consts.num_of_rays)
	{
		g_ray.ray_lenght = putray(g_consts.first_ray_ang);
		g_ray.correctdist = g_ray.ray_lenght *
		cos(fabs(g_consts.first_ray_ang - g_player.rotationangle));
		g_ray.distanceprojectionplane =
		(g_consts.window_width / 2) / tan(g_consts.fov_ang / 2);
		g_ray.wallstripheight = (g_consts.tile_size / g_ray.correctdist)
		* g_ray.distanceprojectionplane;
		g_ray.wallstripheight_d = (g_consts.display_window_width
		* g_ray.wallstripheight) / g_consts.window_width;
		draw_wall(g_ray.ray * g_consts.ray_width,
		(g_consts.display_window_height / 2) - (g_ray.wallstripheight_d / 2),
		g_ray.wallstripheight_d);
		g_consts.first_ray_ang += g_consts.angleinc;
		g_raydistance[g_ray.ray] = g_ray.ray_lenght;
		g_ray.ray++;
	}
}
