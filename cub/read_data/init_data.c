/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:06:24 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/06 17:04:40 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../GNL/get_next_line.h"
#include "../cub3d.h"

void	init_data(void)
{
	g_data_cub.r_x = -1;
	g_data_cub.r_y = -1;
	g_data_cub.no = NULL;
	g_data_cub.so = NULL;
	g_data_cub.we = NULL;
	g_data_cub.ea = NULL;
	g_data_cub.s = NULL;
	g_data_cub.f = -1;
	g_data_cub.c = -1;
	g_data_cub.map_i = 0;
	g_data_cub.map_j = 0;
	g_data_cub.playerj = 0;
	g_data_cub.playeri = 0;
	g_data_cub.string_map = ft_strdup("\n");
	ft_add_to_freeall(g_data_cub.string_map);
}

void	ft_check_param(void)
{
	if (g_data_cub.r_x == -1 || g_data_cub.r_y == -1 || g_data_cub.no == NULL
	|| g_data_cub.so == NULL || g_data_cub.we == NULL || g_data_cub.ea == NULL
	|| g_data_cub.s == NULL || g_data_cub.f == -1 || g_data_cub.c == -1)
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
