/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:41:22 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/27 10:29:46 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < g_consts.display_window_width && y >= 0
			&& y < g_consts.display_window_height)
	{
		dst =
		g_img.addr + (y * g_img.line_length + x * (g_img.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

unsigned int	ft_read_from_memory(t_data texture, int x, int y)
{
	char	*dst;

	if (x >= 0 && x < texture.tw && y >= 0 && y < texture.th)
	{
		dst = texture.addr +
		(y * texture.line_length + x * (texture.bits_per_pixel / 8));
		return (*(unsigned int*)dst);
	}
	return (0);
}

int				nextposallowed(float newplayerx, float newplayery)
{
	int	gridx;
	int	gridy;

	if (newplayerx < 0 || newplayerx >= g_consts.window_width
			|| newplayery < 0 || newplayery >= g_consts.window_height)
		return (1);
	if (g_player.x - newplayerx <= 0)
		newplayerx += g_player.radius + 1;
	else
		newplayerx -= g_player.radius + 1;
	if (g_player.y - newplayery <= 0)
		newplayery += g_player.radius + 1;
	else
		newplayery -= g_player.radius + 1;
	gridx = floor(newplayerx / g_consts.tile_size);
	gridy = floor(newplayery / g_consts.tile_size);
	return (g_data_cub.map[gridy][gridx]);
}

int				iswall(float x, float y)
{
	int	gridx;
	int	gridy;

	if (x < 0 || x >= g_consts.window_width
	|| y < 0 || y >= g_consts.window_height)
		return (1);
	gridx = floor(x / g_consts.tile_size);
	gridy = floor(y / g_consts.tile_size);
	return (g_data_cub.map[gridy][gridx]);
}
