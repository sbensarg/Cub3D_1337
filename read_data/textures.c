/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:00:41 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/29 10:49:53 by sbensarg         ###   ########.fr       */
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

	ptr = ft_split(str, ' ');
	if (ft_strncmp(ptr[0], "NO", 3) != 0 && ft_strncmp(ptr[0], "SO", 3) != 0
	&& ft_strncmp(ptr[0], "WE", 3) != 0 && ft_strncmp(ptr[0], "EA", 3) != 0)
		ft_print_err("ivalide identifer");
	ret = ft_substr(str, 3, ft_strlen1(str + 3));
	if (check_path(ret) == -1)
		ft_print_err("the path of file not exist");
	return (ret);
}

char	*check_s(char *str)
{
	char	**ptr;
	char	*ret;

	ptr = ft_split(str, ' ');
	if (ft_strncmp(ptr[0], "S", 2) != 0)
		ft_print_err("ivalide identifer (S)");
	ret = ft_substr(str, 2, ft_strlen1(str + 2));
	if (check_path(ret) == -1)
		ft_print_err("the path of file not exist");
	return (ret);
}
