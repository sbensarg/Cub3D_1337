/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chicky <chicky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:00:41 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/28 22:03:08 by chicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../GNL/get_next_line.h"
#include "../cub3d.h"

void    ft_read_texture_from_cub(char *str)
{
    if (str[0] =='N' && str[1] == 'O')
        ft_read_NO(&str);
    else if (str[0] =='S' && str[1] == 'O')
        ft_read_SO(&str);
    else if (str[0] =='W' && str[1] == 'E')
        ft_read_WE(&str);
    else if (str[0] == 'E' && str[1] == 'A')
        ft_read_EA(&str);
    else if (str[0] == 'S')
        ft_read_S(&str);
    else
        ft_print_err("Invalide Configuration!!");
}

char *check_identifer(char *str)
{
    char **ptr;
    char *ret;
    ptr = ft_split(str, ' ');
    if(ft_strncmp(ptr[0], "NO", 3) != 0 && ft_strncmp(ptr[0], "SO", 3) != 0
    &&ft_strncmp(ptr[0], "WE", 3) != 0 && ft_strncmp(ptr[0], "EA", 3) != 0)
        ft_print_err("ivalide identifer");
    ret = ft_substr(str, 3, ft_strlen1(str+3));
    if(check_path(ret) == -1)
        ft_print_err("the path of file not exist");
    return(ret);
}

char *check_S(char *str)
{
    char **ptr;
    char *ret;
    ptr = ft_split(str, ' ');
    if(ft_strncmp(ptr[0], "S", 2) != 0)
        ft_print_err("ivalide identifer (S)");
    ret = ft_substr(str, 2, ft_strlen1(str+2));
    if(check_path(ret) == -1)
        ft_print_err("the path of file not exist");
    return(ret);
}
