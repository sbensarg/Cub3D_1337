/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_and_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:51:54 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/06 17:06:29 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../GNL/get_next_line.h"
#include "../cub3d.h"

void	init_sprite(void)
{
	int l;

	l = 0;
	if (g_sprite.num_sprites > 0)
	{
		g_sprite.sprite_map = malloc(g_sprite.num_sprites * sizeof(int*));
		ft_add_to_freeall(g_sprite.sprite_map);
	}
	while (l < g_sprite.num_sprites)
	{
		g_sprite.sprite_map[l] = malloc(2 * sizeof(int));
		ft_add_to_freeall(g_sprite.sprite_map[l]);
		l++;
	}
}

void	sprite_position(int *i, int *j, int *k, int *l)
{
	g_sprite.sprite_map[*l][0] = (*i * 64) + 64 / 2;
	g_sprite.sprite_map[*l][1] = (*j * 64) + 64 / 2;
	g_data_cub.map[*i][*j] = g_data_cub.string_map[*k] - '0';
}

int		ft_checksprite(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '2')
			ret++;
		i++;
	}
	return (ret);
}

void	init_p(int *i, int *j, int *k)
{
	if (g_data_cub.playeri == 0 && g_data_cub.playerj == 0)
	{
		g_data_cub.playeri = *i;
		g_data_cub.playerj = *j;
		g_data_cub.playerdirect = g_data_cub.string_map[*k];
		g_data_cub.map[*i][*j] = 0;
	}
	else
		ft_print_err("duplicated player!!");
}

void	check_player(void)
{
	if (g_data_cub.playeri == 0 && g_data_cub.playerj == 0)
		ft_print_err("player not foand");
}
