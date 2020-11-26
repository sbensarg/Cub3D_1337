/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:26:28 by sbensarg          #+#    #+#             */
/*   Updated: 2020/11/23 01:41:07 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	rect(int tilex, int tiley, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < consts.tile_size)
	{
		while (j < consts.tile_size)
		{
			if (j == 0 || i == 0)
				my_mlx_pixel_put((tilex + i), (tiley + j), 0x00FFFFFF);
			else
				my_mlx_pixel_put((tilex + i), (tiley + j), color);
			j++;
		}
		j = 0;
		i++;
	}
}

void	render_map()
{
	int	tileX;
	int	tileY;
	int	tileColor;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < consts.map_num_rows)
	{
		while (j < consts.map_num_cols)
		{
			tileX = j * consts.tile_size;
			tileY = i * consts.tile_size;
			tileColor = data_cub.map[i][j]  == 1 ? 0x00FF7F7F : 0x00FFFFFF;
			if (data_cub.map[i][j] == 1)
				rect(tileX, tileY, tileColor);
			else
			{
				rect(tileX, tileY, 0x00FFFFFF);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
