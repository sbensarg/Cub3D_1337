/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:33:27 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/06 17:18:30 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../GNL/get_next_line.h"
#include "../cub3d.h"

void	ft_read_no(char **str)
{
	char *str1;

	str1 = *str;
	if (g_data_cub.no == NULL)
	{
		if (str1[3] != '\0')
			g_data_cub.no = check_identifer(str1);
		else
			ft_print_err("North texture is empty");
	}
	else
		ft_print_err("North texture is duplicated");
}

void	ft_read_so(char **str)
{
	char *str1;

	str1 = *str;
	if (g_data_cub.so == NULL)
	{
		if (str1[3] != '\0')
			g_data_cub.so = check_identifer(str1);
		else
			ft_print_err("South texture is empty");
	}
	else
		ft_print_err("South texture is duplicated");
}

void	ft_read_we(char **str)
{
	char *str1;

	str1 = *str;
	if (g_data_cub.we == NULL)
	{
		if (str1[3] != '\0')
			g_data_cub.we = check_identifer(str1);
		else
			ft_print_err("West texture is empty");
	}
	else
		ft_print_err("West texture is duplicated");
}

void	ft_read_ea(char **str)
{
	char *str1;

	str1 = *str;
	if (g_data_cub.ea == NULL)
	{
		if (str1[2] != '\0' && str1[3] != '\0')
			g_data_cub.ea = check_identifer(str1);
		else
			ft_print_err("East texture is empty");
	}
	else
		ft_print_err("East texture is duplicated");
}

void	ft_read_s(char **str)
{
	char *str1;

	str1 = *str;
	if (g_data_cub.s == NULL)
	{
		if (str1[2] != '\0' && str1[1] != '\0')
			g_data_cub.s = check_s(str1);
		else
			ft_print_err("Sprite texture is empty");
	}
	else
		ft_print_err("Sprite texture is duplicated");
}
