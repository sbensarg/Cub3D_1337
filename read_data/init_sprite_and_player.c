/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_and_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:51:54 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/02 18:42:17 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../GNL/get_next_line.h"
#include "../cub3d.h"

void	init_sprite(void)
{
	int l;

	l = 0;
	if (sprite.num_sprites > 0)
	{
		sprite.sprite_map = malloc(sprite.num_sprites * sizeof(int*));
		ft_add_to_freeall(sprite.sprite_map);
	}
	while (l < sprite.num_sprites)
	{
		sprite.sprite_map[l] = malloc(2 * sizeof(int));
		ft_add_to_freeall(sprite.sprite_map[l]);
		l++;
	}
}

void	sprite_position(int *i, int *j, int *k, int *l)
{
	sprite.sprite_map[*l][0] = (*i * 64) + 64 / 2;
	sprite.sprite_map[*l][1] = (*j * 64) + 64 / 2;
	data_cub.map[*i][*j] = data_cub.string_map[*k] - '0';
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
	if (data_cub.playerI == 0 && data_cub.playerJ == 0)
	{
		data_cub.playerI = *i;
		data_cub.playerJ = *j;
		data_cub.playerdirect = data_cub.string_map[*k];
		data_cub.map[*i][*j] = 0;
	}
	else
		ft_print_err("duplicated player!!");
}

void	check_player(void)
{
	if (data_cub.playerI == 0 && data_cub.playerJ == 0)
		ft_print_err("player not foand");
}
