/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:57:27 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/01 11:46:45 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../GNL/get_next_line.h"
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
	if (*j > 0 && (data_cub.map[*j - 1][*i] == 4 ||
				data_cub.map[*j - 1][*i] == -1))
		ft_print_err("map not closed 1");
	if (*j > 0 && (data_cub.map[*j - 1][*i - 1] == 4 ||
				data_cub.map[*j - 1][*i - 1] == -1))
		ft_print_err("map not closed 5");
	if (*j > 0 && (data_cub.map[*j - 1][*i + 1] == 4 ||
				data_cub.map[*j - 1][*i + 1] == -1))
		ft_print_err("map not closed 6");
	if (*j < data_cub.map_j - 1 && (data_cub.map[*j + 1][*i] == 4
				|| data_cub.map[*j + 1][*i] == -1))
		ft_print_err("map not closed 2");
	if (*j < data_cub.map_j - 1 && (data_cub.map[*j + 1][*i - 1] == 4
				|| data_cub.map[*j + 1][*i - 1] == -1))
		ft_print_err("map not closed 7");
	if (*j < data_cub.map_j - 1 && (data_cub.map[*j + 1][*i + 1] == 4
				|| data_cub.map[*j + 1][*i + 1] == -1))
		ft_print_err("map not closed 8");
}

void	check_tab_spaces(void)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j < data_cub.map_j)
	{
		while (i < data_cub.map_i)
		{
			while (data_cub.map[j][i] == 4)
				i++;
			if ((data_cub.map[0][i] == 0 || data_cub.map[0][i] == 2)
					&& data_cub.map[0][i] != -1)
				ft_print_err("top of the map not closed");
			if (data_cub.map[j][i] == 0 || data_cub.map[j][i] == 2)
				check_tab_spaces_diagonale(&i, &j);
			if ((data_cub.map[data_cub.map_j - 1][i] == 0 ||
						data_cub.map[data_cub.map_j - 1][i] == 0)
					&& data_cub.map[data_cub.map_j - 1][i] != -1)
				ft_print_err("end of the map not closed");
			i++;
		}
		i = 0;
		j++;
	}
}
