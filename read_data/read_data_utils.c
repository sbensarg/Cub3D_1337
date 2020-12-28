/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:44:11 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/28 17:36:10 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../GNL/get_next_line.h"
#include "../cub3d.h"

int		is_all(void)
{
	if (data_cub.R_x != -1 && data_cub.R_y != -1 && data_cub.NO != NULL
			&& data_cub.SO != NULL && data_cub.WE != NULL && data_cub.EA != NULL
			&& data_cub.S != NULL && data_cub.F != -1 && data_cub.C != -1)
		return (1);
	else
		ft_print_err("map must be the last");
	return (0);
}

int		is_all1(void)
{
	if (data_cub.R_x != -1 && data_cub.R_y != -1 && data_cub.NO != NULL
	&& data_cub.SO != NULL && data_cub.WE != NULL && data_cub.EA != NULL
	&& data_cub.S != NULL && data_cub.F != -1 && data_cub.C != -1)
		return (1);
	return (0);
}

int		is_valide(char *str)
{
	int i;

	i = 0;
	if (str[i] != '\0')
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == ' ' || str[i] == '2'
		|| str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
			return (1);
		else
			ft_print_err("line in map not valide!!");
	}
	return (0);
}

int		is_player(int *k)
{
	if (data_cub.string_map[*k] == 'N' || data_cub.string_map[*k] == 'S'
	|| data_cub.string_map[*k] == 'E' || data_cub.string_map[*k] == 'W')
		return (1);
	return (0);
}

void	ft_isdigit(char *c)
{
	if (!(*c >= 48 && *c <= 57))
		ft_print_err("Invalid digit");
}
