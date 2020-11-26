/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 23:59:01 by sbensarg          #+#    #+#             */
/*   Updated: 2020/11/20 19:10:58 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "cub3d.h"


void init_data()
{
    data_cub.map_i = 0;
    data_cub.map_j = 0;
    data_cub.string_map= ft_strdup("\n");
}

void    ft_rempli_map()
{
    int i;
    int j;
    int k;
    int n = 0;
    int l = 0;

    i = 0;
    j = 0;
    k = 1;
    data_cub.map = malloc(data_cub.map_j * sizeof(int*));
    while (j < data_cub.map_j)
    {
        data_cub.map[j] = malloc(data_cub.map_i * sizeof(int));
        j++;
    }
    j = 0;
    if (sprite.num_sprites > 0)
        sprite.sprite_map = malloc(sprite.num_sprites * sizeof(int*));
    while (l < sprite.num_sprites)
    {
        sprite.sprite_map[l] = malloc(2 * sizeof(int));
        l++;
    }
    l = 0;
     while (data_cub.string_map[k] != '\0')
     {   
        if (data_cub.string_map[k] == '\n')
        {
            j = 0;
            i++;
        }
        else
        {
            if(data_cub.string_map[k] == '2')
            {
                
                sprite.sprite_map[l][0] = (i * 64) + 64 / 2;
                sprite.sprite_map[l][1] = (j * 64) +  64 / 2;
                data_cub.map[i][j] = data_cub.string_map[k] - '0';
                j++;
                l++;
            }
            else if ((data_cub.string_map[k] == 'N' || data_cub.string_map[k] == 'S' ||
                    data_cub.string_map[k] == 'W' || data_cub.string_map[k] == 'E'))
            {
                data_cub.playerI = i;
                data_cub.playerJ = j;
                data_cub.playerdirect = data_cub.string_map[k];
                data_cub.map[i][j] = 0;
                j++;
            }
            else
            {
                data_cub.map[i][j] = data_cub.string_map[k] - '0';
                j++;
           }
        }
    k++;
    }
}
 int ft_checksprite(char *str)
 {
     int i;
     int ret;
     i = 0;
     ret = 0;
     
     while(str[i] != '\0')
     {
         if(str[i] == '2')
            ret++;
        i++;
     }
     return ret;
 }
void    ft_read_map(char *str)
{
    int  len;
    
    len = ft_strlen1(str);
    str = ft_strjoin1(str, "\n");
    data_cub.string_map = ft_strjoin1(data_cub.string_map, str);
  
    if (len > data_cub.map_i)
        data_cub.map_i = len;
}

int ft_getColorIntegerFromRGB(char *str)
{
    int nbr1 = 0;
    int nbr2 = 0;
    int nbr3 = 0;
    int i;
    i = 2;
    
         nbr1 = ft_atoi(str+i);
        while(str[i] != '\0' && str[i] != ',')
            i++;
        nbr2 = ft_atoi(str+i+1);
        i++;
        while(str[i] != '\0' && str[i] != ',')
            i++;
        nbr3 = ft_atoi(str+i+1);
     return ((nbr1 << 16) + (nbr2 << 8) + nbr3);
}

void    ft_read_texture_from_cub(char *str)
{
    if (str[0] =='N' && str[1] == 'O')
    {
        data_cub.NO = ft_substr(str, 3, ft_strlen1(str+3));
    }
    else if (str[0] =='S')
    {
        if (str[1] == 'O')
            data_cub.SO = ft_substr(str, 3, ft_strlen1(str+3));
        else
            data_cub.S = ft_substr(str, 2, ft_strlen1(str+2));
    }
    else if (str[0] =='W' && str[1] == 'E')
    {
        data_cub.WE = ft_substr(str, 3, ft_strlen1(str+3));
    }
    else if (str[0] == 'E' && str[1] == 'A')
    {
        data_cub.EA = ft_substr(str, 3, ft_strlen1(str+3));
    }
}
void ft_readfromdotcubpart2(char *str)
{
    int i;
    i = 2;

    if (str[0] == 'R')
    {
        data_cub.R_x = ft_atoi(str+i);
        while (str[i++] != ' ')
            data_cub.R_y = ft_atoi(str+i);
    }
    else if(str[0] == 'N' || str[0] =='S' ||str[0] =='W' || str[0] == 'E')
        ft_read_texture_from_cub(str);
    else if(str[0] == 'F')
        data_cub.F = ft_getColorIntegerFromRGB(str);
    else if (str[0] == 'C')
        data_cub.C = ft_getColorIntegerFromRGB(str);
    else if (str[0] != '\0')
    {
        sprite.num_sprites += ft_checksprite(str);
        ft_read_map(str);
        data_cub.map_j++;
        
    }
}
int ft_read_from_dotcub(char *filename)
{
    int fd;
    char *str;
    int r;

    sprite.num_sprites = 0;
    fd = open(filename, O_RDONLY);
    init_data();
    if (fd == -1)
        return (-1);
    while ((r = get_next_line(fd, &str)) > 0)
    {
        ft_readfromdotcubpart2(str);   
    }
     ft_readfromdotcubpart2(str);
    ft_rempli_map();
        
    // int i =0;
    // int j=0;
    // printf("%s\n", data_cub.string_map);
    // while(j < data_cub.map_j)
    // {
    //     while(i < data_cub.map_i)
    //     {
    //         printf("%d", data_cub.map[j][i]);
    //         i++;
    //     }
    //     printf("\n");
    //     i = 0;
    //     j++;
    // }
    return 0;  
}