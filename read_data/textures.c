/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:00:41 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/02 18:37:18 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../GNL/get_next_line.h"
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
	int 	i;
	
	i= 0;
	ptr = ft_split(str, ' ');
	while (ptr[i++])
		ft_add_to_freeall(ptr[i - 1]);
	ft_add_to_freeall(ptr);
	if (ft_strncmp(ptr[0], "NO", 3) != 0 && ft_strncmp(ptr[0], "SO", 3) != 0
	&& ft_strncmp(ptr[0], "WE", 3) != 0 && ft_strncmp(ptr[0], "EA", 3) != 0)
		ft_print_err("ivalide identifer");
	ret = ft_substr(ptr[1], 0, ft_strlen1(ptr[1]));
	if (check_path(ret) == -1)
		ft_print_err("the path of file not exist 1");
	return (ret);
}

char	*check_s(char *str)
{
	char	**ptr;
	char	*ret;
	int		i;

	i = 0;
	ptr = ft_split(str, ' ');
	while (ptr[i++])
		ft_add_to_freeall(ptr[i - 1]);
	ft_add_to_freeall(ptr);
	if (ft_strncmp(ptr[0], "S", 2) != 0)
		ft_print_err("ivalide identifer (S)");
	ret = ft_substr(ptr[1], 0, ft_strlen1(ptr[1]));
	if (check_path(ret) == -1)
		ft_print_err("the path of file not exist");
	return (ret);
}

void	init_texture(void)
{
	if ((texture[0].img = mlx_xpm_file_to_image(data.mlx_ptr, data_cub.NO,
	&texture[0].tw, &texture[0].th)) == NULL)
		ft_print_err("ivalide xpm (NO)");
	texture[0].addr = mlx_get_data_addr(texture[0].img,
	&texture[0].bits_per_pixel, &texture[0].line_length, &texture[0].endian);
	if ((texture[1].img = mlx_xpm_file_to_image(data.mlx_ptr, data_cub.SO,
	&texture[1].tw, &texture[1].th)) == NULL)
		ft_print_err("ivalide xpm (SO)");
	texture[1].addr = mlx_get_data_addr(texture[1].img,
	&texture[1].bits_per_pixel, &texture[1].line_length, &texture[1].endian);
	if ((texture[2].img = mlx_xpm_file_to_image(data.mlx_ptr, data_cub.EA,
	&texture[2].tw, &texture[2].th)) == NULL)
		ft_print_err("ivalide xpm (EA)");
	texture[2].addr = mlx_get_data_addr(texture[2].img,
	&texture[2].bits_per_pixel, &texture[2].line_length, &texture[2].endian);
	if ((texture[3].img = mlx_xpm_file_to_image(data.mlx_ptr, data_cub.WE,
	&texture[3].tw, &texture[3].th)) == NULL)
		ft_print_err("ivalide xpm (WE)");
	texture[3].addr = mlx_get_data_addr(texture[3].img,
	&texture[3].bits_per_pixel, &texture[3].line_length, &texture[3].endian);
	if ((texture[4].img = mlx_xpm_file_to_image(data.mlx_ptr, data_cub.S,
	&texture[4].tw, &texture[4].th)) == NULL)
		ft_print_err("ivalide xpm (S)");
	texture[4].addr = mlx_get_data_addr(texture[4].img,
	&texture[4].bits_per_pixel, &texture[4].line_length, &texture[4].endian);
}
