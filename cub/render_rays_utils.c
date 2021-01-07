/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:50:10 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/06 16:59:35 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_derection(float angle)
{
	if (angle > PI * 0.25 && angle < PI * 0.75)
		g_pos.angleisup = 1;
	else if (angle > PI * 0.25 && angle < PI * 1.75)
		g_pos.angleisright = 1;
	else if (angle < PI * 1.75 && angle > PI * 1.25)
		g_pos.angleisdown = 1;
	else if (angle < PI * 1.25 && angle > PI * 0.75)
		g_pos.angleisleft = 1;
}

void	put_color_c(int *tilex, int *tiley, int *i)
{
	int j;

	j = 0;
	while (j <= *tiley)
	{
		my_mlx_pixel_put(*tilex + *i, j, g_data_cub.c);
		j++;
	}
}

void	put_color_f(int *tilex, int *tiley, int *i, int *h)
{
	int j;

	j = 0;
	while (*tiley + *h + j < g_consts.display_window_height)
	{
		my_mlx_pixel_put(*tilex + *i, *tiley + *h + j, g_data_cub.f);
		j++;
	}
}

void	draw_wall(int tilex, int tiley, int height)
{
	int	i;
	int	j;
	int y;

	i = 0;
	j = 0;
	while (i < g_consts.ray_width)
	{
		put_color_c(&tilex, &tiley, &i);
		while (j < height)
		{
			if (tiley + j >= 0 && tiley + j < g_consts.display_window_height)
			{
				y = (g_consts.tile_size * j) / height;
				my_mlx_pixel_put(tilex + i, tiley + j,
				ft_read_from_memory(g_texture[g_texturenum], (g_textureoffsetx *
				g_texture[g_texturenum].tw) / g_consts.tile_size,
				(y * g_texture[g_texturenum].th) / g_consts.tile_size));
			}
			j++;
		}
		put_color_f(&tilex, &tiley, &i, &height);
		i++;
	}
}
