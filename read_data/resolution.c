/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:05:10 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/27 12:17:00 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../GNL/get_next_line.h"
#include "../cub3d.h"

void ft_getresolution(char *str)
{
    int i;
    i = 0;
    char **ptr;
    int d_window_width;
    int d_window_height;
    
    mlx_get_screen_size(data.mlx_ptr, &d_window_width, &d_window_height);
    ptr = ft_split(str, ' ');
    if(ft_strncmp(ptr[0], "R", 2) != 0)
        ft_print_err("ivalide identifer (R)");
    if(ptr[3] != NULL)
        ft_print_err("too many argument");
    data_cub.R_x = ft_atoi(ptr[1]);
    data_cub.R_y = ft_atoi(ptr[2]);
    ft_isdigit(ptr[1]);
    ft_isdigit(ptr[2]);
    if((len_num(data_cub.R_y) != strlen(ptr[2])) || (len_num(data_cub.R_x) != strlen(ptr[1])))
        ft_print_err("Invalid Resolution");
    if(data_cub.R_x <= 0 || data_cub.R_y <= 0)
        ft_print_err("Invalid Resolution");
     if(data_cub.R_x > d_window_width)
        data_cub.R_x = d_window_width;
    if(data_cub.R_y > d_window_height)
        data_cub.R_y = d_window_height;
    
 }