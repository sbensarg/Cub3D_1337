/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:00:41 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/27 12:01:55 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../GNL/get_next_line.h"
#include "../cub3d.h"

void    ft_read_texture_from_cub(char *str)
{
    if (str[0] =='N' && str[1] == 'O')
    {
        if(data_cub.NO == NULL)
        {
            if(str[3] != '\0')
                data_cub.NO = check_identifer(str);
            else
                ft_print_err("North texture is empty");
        }
        else
            ft_print_err("North texture is duplicated");
    }
    else if (str[0] =='S' && str[1] == 'O')
    {
        if(data_cub.SO == NULL)
        {
            if(str[3] != '\0')
                data_cub.SO = check_identifer(str);
            else
                ft_print_err("South texture is empty");
        }
        else
            ft_print_err("South texture is duplicated");
    }
    else if (str[0] =='W' && str[1] == 'E')
    {
        if(data_cub.WE == NULL)
        {
            if(str[3] != '\0')
                data_cub.WE = check_identifer(str);
            else
                ft_print_err("West texture is empty");
        }
        else
            ft_print_err("West texture is duplicated");
    }
    else if (str[0] == 'E' && str[1] == 'A')
    {
        if(data_cub.EA == NULL)
        {
            if(str[2] != '\0' && str[3] != '\0')
                data_cub.EA = check_identifer(str);
            else
                ft_print_err("East texture is empty");
        }
        else
            ft_print_err("East texture is duplicated");
    }
     else if (str[0] == 'S')
    {
        if (data_cub.S == NULL)
        {
            if(str[2] != '\0' && str[1] != '\0')
                data_cub.S = check_S(str);
            else
                ft_print_err("Sprite texture is empty");
        }
        else
            ft_print_err("Sprite texture is duplicated");
    }
    else
    {
        ft_print_err("Invalide Configuration!!");
    }
    
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
