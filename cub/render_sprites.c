/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:08:03 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/06 16:48:19 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sortsprites(void)
{
	int l;

	l = 0;
	g_sprite.spritedistance = malloc(sizeof(double) * g_sprite.num_sprites);
	while (l < g_sprite.num_sprites)
	{
		g_sprite.spritedistance[l] =
			sqrt((g_player.x - g_sprite.sprite_map[l][1])
		* (g_player.x - g_sprite.sprite_map[l][1])
		+ (g_player.y - g_sprite.sprite_map[l][0])
		* (g_player.y - g_sprite.sprite_map[l][0]));
		l++;
	}
	ft_bubble_sorte(g_sprite.spritedistance);
}

void	calc_sprite_angle(void)
{
	g_sprite.spriteangle = atan2(g_player.y - g_sprite.sprite_map[g_sprite.l][0]
	, g_player.x - g_sprite.sprite_map[g_sprite.l][1]);
	g_sprite.spriteangle = fmod_angle(g_sprite.spriteangle);
	g_sprite.fxa = g_sprite.sprite_map[g_sprite.l][1]
		- cos(g_sprite.spriteangle - 1.5708) * (g_consts.tile_size / 2);
	g_sprite.fya = g_sprite.sprite_map[g_sprite.l][0]
		- sin(g_sprite.spriteangle - 1.5708) * (g_consts.tile_size / 2);
	g_sprite.firstangle = atan2(g_player.y - g_sprite.fya,
		g_player.x - g_sprite.fxa);
	g_sprite.lxa = g_sprite.sprite_map[g_sprite.l][1]
		- cos(g_sprite.spriteangle + 1.5708) * (g_consts.tile_size / 2);
	g_sprite.lya = g_sprite.sprite_map[g_sprite.l][0]
		- sin(g_sprite.spriteangle + 1.5708) * (g_consts.tile_size / 2);
	g_sprite.lastangle = atan2(g_player.y - g_sprite.lya,
		g_player.x - g_sprite.lxa);
	g_sprite.firstangle = fmod_angle(g_sprite.firstangle);
	g_sprite.lastangle = fmod_angle(g_sprite.lastangle);
	if (g_sprite.lastangle < g_sprite.firstangle)
		g_sprite.lastangle += (2 * PI);
}

void	calc_x(void)
{
	while (g_sprite.j < g_sprite.nbrofrays)
	{
		g_sprite.firstangle = fmod_angle(g_sprite.firstangle);
		calc_stripheight();
		if ((g_sprite.firstangle >= g_sprite.startfov
			&& g_sprite.firstangle <= g_sprite.startfov + g_consts.fov_ang))
		{
			g_sprite.x = fabs(g_sprite.startfov - g_sprite.firstangle)
				/ g_consts.angleinc;
			break ;
		}
		else if (g_sprite.firstangle <= g_sprite.endfov
				&& g_sprite.startfov + g_consts.fov_ang > 2 * PI)
		{
			g_sprite.x = g_consts.display_window_width -
			(fabs(g_sprite.firstangle - fmod(g_sprite.startfov
			+ g_consts.fov_ang, 2 * PI)) / g_consts.angleinc);
			break ;
		}
		g_sprite.j++;
		g_sprite.firstangle += g_consts.angleinc;
	}
}

void	draw_sprite(void)
{
	while (g_sprite.j < g_sprite.nbrofrays)
	{
		if (g_sprite.x != -1 &&
				g_raydistance[g_sprite.x] > g_sprite.spritedistance[g_sprite.l])
		{
			putpixel_sprite(g_sprite.x,
			g_consts.display_window_height / 2 - g_sprite.stripheight / 2,
			g_sprite.stripheight);
		}
		g_sprite.x++;
		g_sprite.j++;
	}
}

void	rendersprites(void)
{
	ft_sortsprites();
	g_sprite.l = 0;
	g_sprite.j = 0;
	g_sprite.spriteangle = 0;
	g_sprite.size_sprite = 0;
	g_sprite.ray_lenght = 0;
	while (g_sprite.l < g_sprite.num_sprites)
	{
		calc_sprite_angle();
		g_sprite.x = -1;
		g_sprite.j = 0;
		g_sprite.nbrofrays = fabs(g_sprite.firstangle - g_sprite.lastangle)
			/ g_consts.angleinc;
		calc_x();
		draw_sprite();
		g_sprite.l++;
	}
	free(g_raydistance);
	free(g_sprite.spritedistance);
}
