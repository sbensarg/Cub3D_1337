/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:06:24 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/02 18:44:19 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../GNL/get_next_line.h"
#include "../cub3d.h"

void	init_data(void)
{
	data_cub.R_x = -1;
	data_cub.R_y = -1;
	data_cub.NO = NULL;
	data_cub.SO = NULL;
	data_cub.WE = NULL;
	data_cub.EA = NULL;
	data_cub.S = NULL;
	data_cub.F = -1;
	data_cub.C = -1;
	data_cub.map_i = 0;
	data_cub.map_j = 0;
	data_cub.playerJ = 0;
	data_cub.playerI = 0;
	data_cub.string_map = ft_strdup("\n");
	ft_add_to_freeall(data_cub.string_map);
}

void	ft_check_param(void)
{
	if (data_cub.R_x == -1 || data_cub.R_y == -1 || data_cub.NO == NULL
			|| data_cub.SO == NULL || data_cub.WE == NULL || data_cub.EA == NULL
			|| data_cub.S == NULL || data_cub.F == -1 || data_cub.C == -1)
		ft_print_err("Invalid Configuration");
}

int		len_num(long long nbr)
{
	int count;

	count = 0;
	if (nbr >= 0 && nbr <= 9)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void	check_ext(char *ext)
{
	int len;

	len = ft_strlen1(ext);
	if (ft_strncmp(&ext[len - 4], ".cub", 4) != 0)
		ft_print_err("ivalid cub");
}

int		check_path(char *path)
{
	int fd;

	fd = open(path, O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
	if (fd < 0)
	{
		if (errno == EEXIST)
			return (1);
		else
			return (-1);
	}
	return (0);
}
