/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 23:59:01 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/28 17:10:18 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../GNL/get_next_line.h"
#include "../cub3d.h"

void	ft_getcolor_f(char **ret)
{
	if (data_cub.F == -1)
	{
		if (ret[1] != '\0' && ret[2] != '\0')
			data_cub.F = ft_getColorIntegerFromRGB_F(*ret);
		else
			ft_print_err("Floor color is empty");
	}
	else
		ft_print_err("Duplicate color of floor");
}

void	ft_getcolor_c(char **ret)
{
	if (data_cub.C == -1)
	{
		if (ret[1] != '\0' && ret[2] != '\0')
		{
			data_cub.C = ft_getColorIntegerFromRGB_C(*ret);
		}
		else
			ft_print_err("C color is empty");
	}
	else
		ft_print_err("Duplicate color of Ceilling");
}

void	ft_getmap(char **str, char **ret)
{
	if (is_all() == 1 && is_valide(*str) == 1)
	{
		sprite.num_sprites += ft_checksprite(*str);
		ft_read_map(*str);
		check_border(*str);
		check_spaces(*str);
		data_cub.map_j++;
	}
	else if (str[0] == '\0' && data_cub.map_j > 0)
	{
		ft_print_err("empty line in map");
	}
	else if (is_valide(*ret) != 1 && data_cub.map_j > 0)
	{
		ft_print_err("line in map not valide");
	}
}

void	ft_readfromdotcubpart2(char *str)
{
	char *tmp;
	char *ret;

	tmp = ft_strdup1(str);
	ret = ft_strtrim(tmp, " ");
	if (ret[0] != '\0')
	{
		if (ret[0] == 'R')
			ft_getresolution(ret);
		else if (ret[0] == 'N' || ret[0] == 'S'
				|| ret[0] == 'W' || ret[0] == 'E')
			ft_read_texture_from_cub(ret);
		else if (ret[0] == 'F')
			ft_getcolor_f(&ret);
		else if (ret[0] == 'C')
			ft_getcolor_c(&ret);
		else
			ft_getmap(&str, &ret);
	}
}

int		ft_read_from_dotcub(char *filename)
{
	int		fd;
	char	*str;
	int		r;

	sprite.num_sprites = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	check_ext(filename);
	init_data();
	while ((r = get_next_line(fd, &str)) > 0)
	{
		if (is_all1() != 1 && (str[0] == '\0'))
			continue ;
		ft_readfromdotcubpart2(str);
	}
	ft_readfromdotcubpart2(str);
	ft_check_param();
	ft_init_map();
	ft_rempli_map();
	check_player();
	check_tab_spaces();
	ft_rempli_spaces();
	return (0);
}
