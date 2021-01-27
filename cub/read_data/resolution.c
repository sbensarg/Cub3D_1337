/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:05:10 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/22 15:19:10 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../GNL/get_next_line.h"
#include "../cub3d.h"

void	set_screen_size(void)
{
	int		d_window_width;
	int		d_window_height;

	mlx_get_screen_size(g_data.mlx_ptr, &d_window_width, &d_window_height);
	if (g_data_cub.r_x <= 0 || g_data_cub.r_y <= 0)
		ft_print_err("Invalid Resolution");
	if (g_data_cub.r_x > d_window_width)
		g_data_cub.r_x = d_window_width;
	if (g_data_cub.r_y > d_window_height)
		g_data_cub.r_y = d_window_height;
}

int		ft_strlenwithskipzero(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] == '0' && str[i] != '\0')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

void	ft_getresolution(char *str)
{
	char	**ptr;
	int		d_window_width;
	int		d_window_height;

	mlx_get_screen_size(g_data.mlx_ptr, &d_window_width, &d_window_height);
	ptr = ft_split(str, ' ');
	free_ptr(ptr);
	if (ft_strncmp(ptr[0], "R", 2) != 0)
		ft_print_err("ivalide identifer (R)");
	if (ptr[2] == NULL)
		ft_print_err("invalide Resolution");
	ft_isdigit(ptr[1]);
	ft_isdigit(ptr[2]);
	if (ft_strlenwithskipzero(ptr[1]) > 4 || ft_atoi(ptr[1]) > d_window_width)
		g_data_cub.r_x = d_window_width;
	else
		g_data_cub.r_x = ft_atoi(ptr[1]);
	if (ft_strlenwithskipzero(ptr[2]) > 4 || ft_atoi(ptr[2]) > d_window_height)
		g_data_cub.r_y = d_window_height;
	else
		g_data_cub.r_y = ft_atoi(ptr[2]);
	if (g_data_cub.r_x <= 0 || g_data_cub.r_y <= 0)
		ft_print_err("Invalid Resolution");
	if (ptr[3] != NULL)
		ft_print_err("too many argument");
}
