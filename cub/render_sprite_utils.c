/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:20:46 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/16 18:59:40 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_stripheight(void)
{
	g_sprite.correctdist = g_sprite.spritedistance[g_sprite.l] /
		cos(fabs(g_sprite.spriteangle - g_sprite.firstangle));
	g_sprite.distanceprojectionplane =
		(g_consts.window_width / 2) / tan(g_consts.fov_ang / 2);
	g_sprite.size_sprite = (g_consts.tile_size / g_sprite.correctdist)
		* g_sprite.distanceprojectionplane;
	g_sprite.stripheight =
		(g_sprite.size_sprite * g_consts.display_window_width)
		/ g_consts.window_width;
}

void	putpixel_sprite(int x, int y, int height)
{
	int				j;
	unsigned int	color;

	j = 0;
	if (height >= g_consts.display_window_height)
		j = (height / 2) - (g_consts.display_window_height / 2);
	while (j < height)
	{
		if (y + j >= 0 && y + j < g_consts.display_window_height
		&& x >= 0 && x < g_consts.display_window_width)
		{
			color = ft_read_from_memory(g_texture[4],
					g_texture[4].tw * g_sprite.j / g_sprite.nbrofrays,
					g_texture[4].th * j / height);
			if (color != 0x0000)
				my_mlx_pixel_put(x, y + j, color);
		}
		else if (y + j >= g_consts.display_window_height)
			break ;
		j++;
	}
}

void	ft_bubble_sorte(double *distance)
{
	int	i;
	int	temp;

	i = 0;
	while (i + 1 < g_sprite.num_sprites)
	{
		if (distance[i] < distance[i + 1])
		{
			temp = distance[i];
			distance[i] = distance[i + 1];
			distance[i + 1] = temp;
			temp = g_sprite.sprite_map[i][0];
			g_sprite.sprite_map[i][0] = g_sprite.sprite_map[i + 1][0];
			g_sprite.sprite_map[i + 1][0] = temp;
			temp = g_sprite.sprite_map[i][1];
			g_sprite.sprite_map[i][1] = g_sprite.sprite_map[i + 1][1];
			g_sprite.sprite_map[i + 1][1] = temp;
			i = -1;
		}
		i++;
	}
}
