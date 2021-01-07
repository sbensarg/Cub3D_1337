/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:57:27 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/06 17:02:30 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../GNL/get_next_line.h"
#include "../cub3d.h"

void	check_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '0')
		{
			if (str[i - 1] == ' ' || str[i + 1] == ' ')
				ft_print_err("map not closed 3");
		}
		i++;
	}
}

void	check_border(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] != '1' || str[ft_strlen1(str) - 1] != '1')
		ft_print_err("map not closed 4");
}

void	check_tab_spaces_diagonale(int *i, int *j)
{
	if (*j > 0 && (g_data_cub.map[*j - 1][*i] == 4 ||
				g_data_cub.map[*j - 1][*i] == -1))
		ft_print_err("map not closed 1");
	if (*j > 0 && (g_data_cub.map[*j - 1][*i - 1] == 4 ||
				g_data_cub.map[*j - 1][*i - 1] == -1))
		ft_print_err("map not closed 5");
	if (*j > 0 && (g_data_cub.map[*j - 1][*i + 1] == 4 ||
				g_data_cub.map[*j - 1][*i + 1] == -1))
		ft_print_err("map not closed 6");
	if (*j < g_data_cub.map_j - 1 && (g_data_cub.map[*j + 1][*i] == 4
				|| g_data_cub.map[*j + 1][*i] == -1))
		ft_print_err("map not closed 2");
	if (*j < g_data_cub.map_j - 1 && (g_data_cub.map[*j + 1][*i - 1] == 4
				|| g_data_cub.map[*j + 1][*i - 1] == -1))
		ft_print_err("map not closed 7");
	if (*j < g_data_cub.map_j - 1 && (g_data_cub.map[*j + 1][*i + 1] == 4
				|| g_data_cub.map[*j + 1][*i + 1] == -1))
		ft_print_err("map not closed 8");
}

void	check_tab_spaces(void)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j < g_data_cub.map_j)
	{
		while (i < g_data_cub.map_i)
		{
			while (g_data_cub.map[j][i] == 4)
				i++;
			if ((g_data_cub.map[0][i] == 0 || g_data_cub.map[0][i] == 2)
					&& g_data_cub.map[0][i] != -1)
				ft_print_err("top of the map not closed");
			if (g_data_cub.map[j][i] == 0 || g_data_cub.map[j][i] == 2)
				check_tab_spaces_diagonale(&i, &j);
			if ((g_data_cub.map[g_data_cub.map_j - 1][i] == 0 ||
						g_data_cub.map[g_data_cub.map_j - 1][i] == 0)
					&& g_data_cub.map[g_data_cub.map_j - 1][i] != -1)
				ft_print_err("end of the map not closed");
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_getmap(char **str, char **ret)
{
	char *str1;
	char *ret1;

	str1 = *str;
	ret1 = *ret;
	if (is_all() == 1 && is_valide(str1) == 1)
	{
		g_sprite.num_sprites += ft_checksprite(str1);
		ft_read_map(str1);
		g_data_cub.map_j++;
		check_border(str1);
		check_spaces(str1);
	}
	else if (is_valide(ret1) != 1 && g_data_cub.map_j > 0)
	{
		ft_print_err("line in map not valide");
	}
}
