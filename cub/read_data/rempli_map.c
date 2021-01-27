/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rempli_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:38:20 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/27 10:56:02 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../GNL/get_next_line.h"
#include "../cub3d.h"

void	ft_read_map(char *str)
{
	int	len;
	int	i;

	i = 1;
	len = ft_strlen1(str);
	str = ft_strjoin1(str, "\n");
	ft_add_to_freeall(str);
	g_data_cub.string_map = ft_strjoin1(g_data_cub.string_map, str);
	ft_add_to_freeall(g_data_cub.string_map);
	if (len > g_data_cub.map_i)
		g_data_cub.map_i = len;
}

void	ft_init_map(void)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if ((g_data_cub.map = malloc((g_data_cub.map_j) * sizeof(int*))) == NULL)
		ft_print_perror();
	ft_add_to_freeall(g_data_cub.map);
	while (j < g_data_cub.map_j)
	{
		g_data_cub.map[j] = malloc((g_data_cub.map_i + 1) * sizeof(int));
		if (g_data_cub.map[j] == NULL)
			ft_print_perror();
		ft_add_to_freeall(g_data_cub.map[j]);
		i = 0;
		while (i <= g_data_cub.map_i)
		{
			g_data_cub.map[j][i] = -1;
			i++;
		}
		j++;
	}
}

void	map(int *i, int *j, int *k, int *l)
{
	if (g_data_cub.string_map[*k] == '2')
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
	else if (g_data_cub.string_map[*k] == ' ')
	{
		g_data_cub.map[*i][*j] = 4;
		(*j)++;
	}
	else
	{
		g_data_cub.map[*i][*j] = g_data_cub.string_map[*k] - '0';
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
	while (g_data_cub.string_map[k] != '\0')
	{
		if (g_data_cub.string_map[k] == '\n')
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
	while (j < g_data_cub.map_j)
	{
		while (i < g_data_cub.map_i)
		{
			if (g_data_cub.map[j][i] == -1 || g_data_cub.map[j][i] == 4)
				g_data_cub.map[j][i] = 1;
			i++;
		}
		i = 0;
		j++;
	}
}
