/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 10:33:27 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/29 10:40:37 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../GNL/get_next_line.h"
#include "../cub3d.h"

void	ft_read_no(char **str)
{
	char *str1;

	str1 = *str;
	if (data_cub.NO == NULL)
	{
		if (str1[3] != '\0')
			data_cub.NO = check_identifer(str1);
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
	if (data_cub.SO == NULL)
	{
		if (str1[3] != '\0')
			data_cub.SO = check_identifer(str1);
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
	if (data_cub.WE == NULL)
	{
		if (str1[3] != '\0')
			data_cub.WE = check_identifer(str1);
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
	if (data_cub.EA == NULL)
	{
		if (str1[2] != '\0' && str1[3] != '\0')
			data_cub.EA = check_identifer(str1);
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
	if (data_cub.S == NULL)
	{
		if (str1[2] != '\0' && str1[1] != '\0')
			data_cub.S = check_s(str1);
		else
			ft_print_err("Sprite texture is empty");
	}
	else
		ft_print_err("Sprite texture is duplicated");
}
