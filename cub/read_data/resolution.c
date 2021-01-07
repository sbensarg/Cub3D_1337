/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:05:10 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/06 17:11:39 by sbensarg         ###   ########.fr       */
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

void	ft_getresolution(char *str)
{
	int		i;
	char	**ptr;

	i = 0;
	ptr = ft_split(str, ' ');
	while (ptr[i++])
		ft_add_to_freeall(ptr[i - 1]);
	ft_add_to_freeall(ptr);
	if (ft_strncmp(ptr[0], "R", 2) != 0)
		ft_print_err("ivalide identifer (R)");
	if (ptr[1] == NULL)
		ft_print_err("invalide arg1");
	if (ptr[2] == NULL)
		ft_print_err("invalide arg2");
	ft_isdigit(ptr[1]);
	ft_isdigit(ptr[2]);
	g_data_cub.r_x = ft_atoi(ptr[1]);
	g_data_cub.r_y = ft_atoi(ptr[2]);
	if (ptr[3] != NULL)
		ft_print_err("too many argument");
	if ((len_num(g_data_cub.r_y) != strlen(ptr[2]))
	|| (len_num(g_data_cub.r_x) != strlen(ptr[1])))
		ft_print_err("Invalid Resolution");
	set_screen_size();
}
