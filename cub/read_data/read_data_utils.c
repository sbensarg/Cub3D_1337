/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:44:11 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/10 19:07:23 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../GNL/get_next_line.h"
#include "../cub3d.h"

int		is_all(void)
{
	if (g_data_cub.r_x != -1 && g_data_cub.r_y != -1 && g_data_cub.no != NULL
	&& g_data_cub.so != NULL && g_data_cub.we != NULL && g_data_cub.ea != NULL
	&& g_data_cub.s != NULL && g_data_cub.f != -1 && g_data_cub.c != -1)
		return (1);
	else
		ft_print_err("map must be the last");
	return (0);
}

int		is_all1(void)
{
	if (g_data_cub.r_x != -1 && g_data_cub.r_y != -1 && g_data_cub.no != NULL
	&& g_data_cub.so != NULL && g_data_cub.we != NULL && g_data_cub.ea != NULL
	&& g_data_cub.s != NULL && g_data_cub.f != -1 && g_data_cub.c != -1)
		return (1);
	return (0);
}

int		is_valide(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' ' && str[i] != '2'
		&& str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E')
			return (0);
		i++;
	}
	return (1);
}

int		is_player(int *k)
{
	if (g_data_cub.string_map[*k] == 'N' || g_data_cub.string_map[*k] == 'S'
	|| g_data_cub.string_map[*k] == 'E' || g_data_cub.string_map[*k] == 'W')
		return (1);
	return (0);
}

void	ft_isdigit(char *c)
{
	int i;

	i = 0;
	while (c[i] != '\0')
	{
		if (!(c[i] >= 48 && c[i] <= 57))
			ft_print_err("Invalid digit");
		i++;
	}
}
