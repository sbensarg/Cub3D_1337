/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rempli_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:38:20 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/28 17:53:00 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../GNL/get_next_line.h"
#include "../cub3d.h"

void	ft_read_map(char *str)
{
	int	len;
	int	i;

	i = 1;
	len = ft_strlen1(str);
	str = ft_strjoin1(str, "\n");
	data_cub.string_map = ft_strjoin1(data_cub.string_map, str);
	if (len > data_cub.map_i)
		data_cub.map_i = len;
}

void	ft_init_map(void)
{
	int i;
	int j;

	j = 0;
	i = 0;
	data_cub.map = malloc(data_cub.map_j * sizeof(int*));
	while (j < data_cub.map_j)
	{
		data_cub.map[j] = malloc(data_cub.map_i * sizeof(int));
		while (i <= data_cub.map_i)
		{
			data_cub.map[j][i] = -1;
			i++;
		}
		j++;
	}
}

void	map(int *i, int *j, int *k, int *l)
{
	if (data_cub.string_map[*k] == '2')
	{
		sprite_position(i, j, k, l);
		(*j)++;
		(*l)++;
	}
	else if (is_player(k) == 1)
	{
		init_p(i, j, k);
		(*j)++;
	}
	else if (data_cub.string_map[*k] == ' ')
	{
		data_cub.map[*i][*j] = 4;
		(*j)++;
	}
	else
	{
		data_cub.map[*i][*j] = data_cub.string_map[*k] - '0';
		(*j)++;
	}
}

void	ft_rempli_map(void)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	j = 0;
	k = 1;
	l = 0;
	ft_init_map();
	init_sprite();
	while (data_cub.string_map[k] != '\0')
	{
		if (data_cub.string_map[k] == '\n')
		{
			j = 0;
			i++;
		}
		else
			map(&i, &j, &k, &l);
		k++;
	}
}

void	ft_rempli_spaces(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < data_cub.map_j)
	{
		while (i < data_cub.map_i)
		{
			if (data_cub.map[j][i] == -1 || data_cub.map[j][i] == 4)
				data_cub.map[j][i] = 1;
			i++;
		}
		i = 0;
		j++;
	}
}
