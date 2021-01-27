/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:00:41 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/18 16:21:48 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../GNL/get_next_line.h"
#include "../cub3d.h"

void	ft_read_texture_from_cub(char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		ft_read_no(&str);
	else if (str[0] == 'S' && str[1] == 'O')
		ft_read_so(&str);
	else if (str[0] == 'W' && str[1] == 'E')
		ft_read_we(&str);
	else if (str[0] == 'E' && str[1] == 'A')
		ft_read_ea(&str);
	else if (str[0] == 'S')
		ft_read_s(&str);
	else
		ft_print_err("Invalide Configuration!!");
}

char	*check_identifer(char *str)
{
	char	**ptr;
	char	*ret;
	int		i;

	i = 2;
	ptr = ft_split(str, ' ');
	free_ptr(ptr);
	if (ft_strncmp(ptr[0], "NO", 3) != 0 && ft_strncmp(ptr[0], "SO", 3) != 0
	&& ft_strncmp(ptr[0], "WE", 3) != 0 && ft_strncmp(ptr[0], "EA", 3) != 0)
		ft_print_err("ivalide identifer");
	while (str[i] == ' ')
		i++;
	ret = ft_substr(str + i, 0, ft_strlen1(str + i));
	if (check_path(ret) == -1)
		ft_print_err("the path of file not exist 1");
	return (ret);
}

char	*check_s(char *str)
{
	char	**ptr;
	char	*ret;
	int		i;

	i = 2;
	ptr = ft_split(str, ' ');
	free_ptr(ptr);
	if (ft_strncmp(ptr[0], "S", 2) != 0)
		ft_print_err("ivalide identifer");
	while (str[i] == ' ')
		i++;
	ret = ft_substr(str + i, 0, ft_strlen1(str + i));
	if (check_path(ret) == -1)
		ft_print_err("the path of file not exist");
	return (ret);
}

void	init_texture(void)
{
	if ((g_texture[0].img = mlx_xpm_file_to_image(g_data.mlx_ptr, g_data_cub.ea,
	&g_texture[0].tw, &g_texture[0].th)) == NULL)
		ft_print_err("ivalide xpm (EA)");
	g_texture[0].addr = mlx_get_data_addr(g_texture[0].img, &g_texture[0].
	bits_per_pixel, &g_texture[0].line_length, &g_texture[0].endian);
	if ((g_texture[1].img = mlx_xpm_file_to_image(g_data.mlx_ptr, g_data_cub.so,
	&g_texture[1].tw, &g_texture[1].th)) == NULL)
		ft_print_err("ivalide xpm (SO)");
	g_texture[1].addr = mlx_get_data_addr(g_texture[1].img, &g_texture[1].
	bits_per_pixel, &g_texture[1].line_length, &g_texture[1].endian);
	if ((g_texture[2].img = mlx_xpm_file_to_image(g_data.mlx_ptr, g_data_cub.we,
	&g_texture[2].tw, &g_texture[2].th)) == NULL)
		ft_print_err("ivalide xpm (WE)");
	g_texture[2].addr = mlx_get_data_addr(g_texture[2].img, &g_texture[2].
	bits_per_pixel, &g_texture[2].line_length, &g_texture[2].endian);
	if ((g_texture[3].img = mlx_xpm_file_to_image(g_data.mlx_ptr, g_data_cub.no,
	&g_texture[3].tw, &g_texture[3].th)) == NULL)
		ft_print_err("ivalide xpm (NO)");
	g_texture[3].addr = mlx_get_data_addr(g_texture[3].img, &g_texture[3].
	bits_per_pixel, &g_texture[3].line_length, &g_texture[3].endian);
	if ((g_texture[4].img = mlx_xpm_file_to_image(g_data.mlx_ptr, g_data_cub.s,
	&g_texture[4].tw, &g_texture[4].th)) == NULL)
		ft_print_err("ivalide xpm (S)");
	g_texture[4].addr = mlx_get_data_addr(g_texture[4].img, &g_texture[4].
	bits_per_pixel, &g_texture[4].line_length, &g_texture[4].endian);
}
