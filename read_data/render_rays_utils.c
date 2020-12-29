/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:50:10 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/29 12:54:42 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_derection(float angle)
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

void	put_color_c(int *tilex, int *tiley, int *i)
{
	int j;

	j = 0;
	while (j <= *tiley)
	{
		my_mlx_pixel_put(*tilex + *i, j, data_cub.C);
		j++;
	}
}

void	put_color_f(int *tilex, int *tiley, int *i, int *h)
{
	int j;

	j = 0;
	while (*tiley + *h + j < consts.display_window_height)
	{
		my_mlx_pixel_put(*tilex + *i, *tiley + *h + j, data_cub.F);
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
	while (i < consts.ray_width)
	{
		put_color_c(&tilex, &tiley, &i);
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
		put_color_f(&tilex, &tiley, &i, &height);
		i++;
	}
}
