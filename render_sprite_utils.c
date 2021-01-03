/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 14:20:46 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/30 14:47:55 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_stripheight(void)
{
	sprite.correctdist = sprite.spritedistance[sprite.l] /
		cos(fabs(sprite.spriteangle - sprite.firstangle));
	sprite.distanceprojectionplane =
		(consts.window_width / 2) / tan(consts.fov_ang / 2);
	sprite.size_sprite = (consts.tile_size / sprite.correctdist)
		* sprite.distanceprojectionplane;
	sprite.stripheight =
		(sprite.size_sprite * consts.display_window_width)
		/ consts.window_width;
}

void	putpixel_sprite(int x, int y, int height)
{
	int				j;
	unsigned int	color;
	int				i;

	j = 0;
	i = 0;
	while (j < height)
	{
		if (y + j >= 0 && y + j < consts.display_window_height)
		{
			color = ft_read_from_memory(texture[4],
					texture[4].tw * sprite.j / sprite.nbrofrays,
					texture[4].th * j / height);
			if (color != 0x0000)
				my_mlx_pixel_put(x, y + j, color);
		}
		j++;
	}
}

void	ft_bubble_sorte(double *distance)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i + 1 < sprite.num_sprites)
	{
		if (distance[i] < distance[i + 1])
		{
			temp = distance[i];
			distance[i] = distance[i + 1];
			distance[i + 1] = temp;
			temp = sprite.sprite_map[i][0];
			sprite.sprite_map[i][0] = sprite.sprite_map[i + 1][0];
			sprite.sprite_map[i + 1][0] = temp;
			temp = sprite.sprite_map[i][1];
			sprite.sprite_map[i][1] = sprite.sprite_map[i + 1][1];
			sprite.sprite_map[i + 1][1] = temp;
			i = -1;
		}
		i++;
	}
}
