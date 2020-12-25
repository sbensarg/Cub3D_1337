/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 23:59:01 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/25 12:18:23 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include "cub3d.h"

void		ft_print_err(char *s)
{
	write(2, "Error\n", 6);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit(0);
}

void init_data()
{
    data_cub.R_x = -1;
    data_cub.R_y = -1;
    data_cub.NO = NULL;
    data_cub.SO = NULL;
    data_cub.WE = NULL;
    data_cub.EA = NULL;
    data_cub.S = NULL;
    data_cub.F = -1;
    data_cub.C = -1;
    data_cub.map_i = 0;
    data_cub.map_j = 0;
    data_cub.playerJ = 0;
    data_cub.playerI = 0;
    data_cub.string_map= ft_strdup("\n");
}
void    ft_init_map()
{
    int i;
    int j;

    j = 0;
    
    data_cub.map = malloc(data_cub.map_j * sizeof(int*));
    while (j < data_cub.map_j)
    {
        data_cub.map[j] = malloc(data_cub.map_i * sizeof(int));
        i = 0;
        while (i <= data_cub.map_i)
		{
			data_cub.map[j][i] = -1;
			i++;
		}
        j++;
    }
}

void check_player()
 {
    if (data_cub.playerI == 0 && data_cub.playerJ == 0)
        ft_print_err("player not foand");
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
    int ret;
    // data_cub.map = malloc(data_cub.map_j * sizeof(int*));
    // while (j < data_cub.map_j)
    // {
    //     data_cub.map[j] = malloc(data_cub.map_i * sizeof(int));
    //     j++;
    // }
    ft_init_map();

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
            else if (data_cub.string_map[k] == 'N' || data_cub.string_map[k] == 'S' 
         || data_cub.string_map[k] == 'E'  || data_cub.string_map[k] == 'W')
            {
                    data_cub.playerI = i;
                    data_cub.playerJ = j;
                    data_cub.playerdirect = data_cub.string_map[k];
                    data_cub.map[i][j] = 0;
                    j++;
            }
            else if(data_cub.string_map[k] == ' ')
            {
                  data_cub.map[i][j] = 4;
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
 int is_valide(char *str)
{
    int i;
    i = 0;
    if(str[i] != '\0')
    {
        if (str[i] == '1' || str[i] == '0' || str[i] == ' ' || str[i] == '2' || str[i] == 'N'
        || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
            return (1);
        else
        {
            ft_print_err("line in map not valide!!");
        }
    }   
    return (0);
}
 void check_spaces(char *str)
 {
     int i;
     i = 0;
     
     while(str[i] != '\0')
     {
         if(str[i] == '0')
         {
             if(str[i-1] == ' ' || str[i+1] == ' ')
                ft_print_err("map not closed 3");
         }
         i++;
     }
 }

 void check_border(char *str)
 {
     int i = 0;
 
         while (str[i] == ' ')
          i++;
        if(str[i] != '1' || str[ft_strlen1(str)-1] != '1')
            ft_print_err("map not closed 4");
 }

void    ft_read_map(char *str)
{
    int  len;
    int i;
    i = 1;

    len = ft_strlen1(str);
    str = ft_strjoin1(str, "\n");
    data_cub.string_map = ft_strjoin1(data_cub.string_map, str);
    if (len > data_cub.map_i)
        data_cub.map_i = len;
}

 void check_tab_spaces()
 {
     int i;
     int j;

     j = 0;
     i = 0;
    while(j < data_cub.map_j)
    {
        while(i < data_cub.map_i)
        {
            while(data_cub.map[j][i] == 4)
                i++;
            if((data_cub.map[0][i] == 0 || data_cub.map[0][i] == 2)  && data_cub.map[0][i] != -1)
                ft_print_err("top of the map not closed");
            if(data_cub.map[j][i] == 0 || data_cub.map[j][i] == 2)
            {
                if( j > 0 && (data_cub.map[j-1][i] == 4 || data_cub.map[j-1][i] == -1))
                    ft_print_err("map not closed 1");
                if(j < data_cub.map_j - 1 && (data_cub.map[j+1][i] == 4 || data_cub.map[j+1][i] == -1))
                     ft_print_err("map not closed 2");
            }
            if((data_cub.map[data_cub.map_j - 1][i] == 0 || data_cub.map[data_cub.map_j - 1][i] == 0)  && data_cub.map[data_cub.map_j - 1][i] != -1)
                ft_print_err("end of the map not closed");
            i++;
        }
        i = 0;
        j++;
    }
 }
 
 void ft_rempli_spaces()
 {
    int i;
    int j;
    
    i = 0;
    j = 0; 
    while(j < data_cub.map_j)
    {
        while(i < data_cub.map_i)
        {
            if(data_cub.map[j][i] == -1 || data_cub.map[j][i] == 4)
                data_cub.map[j][i] = 1;
            i++;
        }
        i = 0;
        j++;
    }   
 } 

int len_num(long long nbr)
{
    int count;
    count = 0;
    if (nbr >= 0 && nbr <=9)
        return (1);
    if (nbr < 0)
    {
        nbr *= -1;
        count++;
    }
    while(nbr)
    {
        nbr/=10;
        count++;
    }
    return (count);
}
void		ft_isdigit(char *c)
{
    
	if (!(*c >= 48 && *c <= 57))
		ft_print_err("Invalid digit");
}
int ft_getColorIntegerFromRGB_F(char *str)
{
    int nbr1 = 0;
    int nbr2 = 0;
    int nbr3 = 0;
    char *ret;
    char **ptr;
    int i;
    i = 2;
    ptr = ft_split(str, ' ');
    if(ft_strncmp(ptr[0], "F", 2) != 0)
        ft_print_err("ivalide identifer (F)");
    while(str[i] == ' ')
        i++;
    ft_isdigit(str+i);
    nbr1 = ft_atoi(str+i);
    
    while(str[i] != '\0' && (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9')))
        i++;
    if(str[i] != ',')
        ft_print_err("invalid dsd");
    while(str[i+1] == ' ')
        i++;
    ft_isdigit(str+i+1);
    nbr2 = ft_atoi(str+i+1);
    i++;
    while(str[i] != '\0' && (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9')))
        i++;
    if(str[i] != ',')
        ft_print_err("invalid dsd");
    while(str[i+1] == ' ')
        i++;
    ft_isdigit(str+i+1);
    nbr3 = ft_atoi(str+i+1);
    while(str[i+1] != '\0' && str[i+1] >= '0' && str[i+1] <= '9')
        i++;
    if(str[i+1] != '\0')
        ft_print_err("invalid nbr");
    
    // ret = ft_strtrim(str+i+1 , " ");
    // if(ft_strlen1(ret) != len_num(nbr3))
    //     ft_print_err("invalid nbr");
    if (nbr1 > 255 || nbr2 > 255 || nbr3 > 255 || nbr1 < 0 || nbr2 < 0 || nbr3 < 0)
    {
        ft_print_err("invalide data");
    }
     return ((nbr1 << 16) + (nbr2 << 8) + nbr3);
}
int ft_getColorIntegerFromRGB_C(char *str)
{
    int nbr1 = 0;
    int nbr2 = 0;
    int nbr3 = 0;
    char *ret;
    char **ptr;
    int i;
    i = 2;
    ptr = ft_split(str, ' ');
    if(ft_strncmp(ptr[0], "C", 2) != 0)
        ft_print_err("ivalide identifer (C)");
  while(str[i] == ' ')
        i++;
    ft_isdigit(str+i);
    nbr1 = ft_atoi(str+i);
    while(str[i] != '\0' && (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9')))
        i++;
    if(str[i] != ',')
        ft_print_err("invalid dsd");
    while(str[i+1] == ' ')
        i++;
    ft_isdigit(str+i+1);
    nbr2 = ft_atoi(str+i+1);
    i++;
    while(str[i] != '\0' && (str[i] == ' ' || (str[i] >= '0' && str[i] <= '9')))
        i++;
    if(str[i] != ',')
        ft_print_err("invalid dsd");
    while(str[i+1] == ' ')
        i++;
    ft_isdigit(str+i+1);
    nbr3 = ft_atoi(str+i+1);
    while(str[i+1] != '\0' && str[i+1] >= '0' && str[i+1] <= '9')
        i++;
    if(str[i+1] != '\0')
        ft_print_err("invalid nbr");
    if (nbr1 > 255 || nbr2 > 255 || nbr3 > 255 || nbr1 < 0 || nbr2 < 0 || nbr3 < 0)
    {
        ft_print_err("invalide data");
    }
     return ((nbr1 << 16) + (nbr2 << 8) + nbr3);
}

void check_ext(char *ext)
{
    int len;
    len = ft_strlen1(ext);
    if(ft_strncmp(&ext[len - 4], ".cub", 4) != 0)
         ft_print_err("ivalid cub");
}

int check_path(char *path)
{
    int fd;
    fd = open(path, O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
    if (fd < 0)
    {
        if (errno == EEXIST)
            return(1);
        else
            return(-1);
    }
    return(0);
}
char *check_NO(char *str)
{
    char **ptr;
    char *ret;
    ptr = ft_split(str, ' ');
    if(ft_strncmp(ptr[0], "NO", 3) != 0)
        ft_print_err("ivalide identifer (NO)");
    ret = ft_substr(str, 3, ft_strlen1(str+3));
    if(check_path(ret) == -1)
        ft_print_err("the path of file not exist (NO)");
  // check_ext(ret);
    return(ret);
}

char *check_SO(char *str)
{
    char **ptr;
    char *ret;
    ptr = ft_split(str, ' ');
    if(ft_strncmp(ptr[0], "SO", 3) != 0)
        ft_print_err("ivalide identifer (SO)");
    ret = ft_substr(str, 3, ft_strlen1(str+3));
    if(check_path(ret) == -1)
        ft_print_err("the path of file not exist (SO)");
   // check_ext(ret);
    return(ret);
}

char *check_WE(char *str)
{
    char **ptr;
    char *ret;
    ptr = ft_split(str, ' ');
    if(ft_strncmp(ptr[0], "WE", 3) != 0)
        ft_print_err("ivalide identifer (WE)");
    ret = ft_substr(str, 3, ft_strlen1(str+3));
    if(check_path(ret) == -1)
        ft_print_err("the path of file not exist (WE)");
   // check_ext(ret);
    return(ret);
}

char *check_EA(char *str)
{
    char **ptr;
    char *ret;
    ptr = ft_split(str, ' ');
    if(ft_strncmp(ptr[0], "EA", 3) != 0)
        ft_print_err("ivalide identifer (EA)");
    ret = ft_substr(str, 3, ft_strlen1(str+3));
    if(check_path(ret) == -1)
        ft_print_err("the path of file not exist (EA)");
   // check_ext(ret);
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
void    ft_read_texture_from_cub(char *str)
{
    
    if (str[0] =='N' && str[1] == 'O')
    {
        if(data_cub.NO == NULL)
        {
            if(str[3] != '\0')
                data_cub.NO = check_NO(str);
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
                data_cub.SO = check_SO(str);
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
                data_cub.WE = check_WE(str);
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
                data_cub.EA = check_EA(str);
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
int is_all()
{
    if(data_cub.R_x != -1 && data_cub.R_y != -1 && data_cub.NO != NULL 
    && data_cub.SO != NULL && data_cub.WE != NULL && data_cub.EA != NULL
    && data_cub.S != NULL && data_cub.F != -1 && data_cub.C != -1)
        return (1);
    else
    {
        ft_print_err("map must be the last");
    }
    
    return (0);
}

int is_all1()
{
    if(data_cub.R_x != -1 && data_cub.R_y != -1 && data_cub.NO != NULL 
    && data_cub.SO != NULL && data_cub.WE != NULL && data_cub.EA != NULL
    && data_cub.S != NULL && data_cub.F != -1 && data_cub.C != -1)
        return (1);

    return (0);
}
void ft_readfromdotcubpart2(char *str)
{
    int i;
    int emptyline;
    char *tmp;
    char *ret;

    emptyline = 0;
    i = 2;
    tmp = ft_strdup1(str);
    ret = ft_strtrim(tmp, " ");
    if (ret[0] == '\t')
        ret += 1;
    if(ret[0] != '\0')
    {
        if (ret[0] == 'R')
        {
            ft_getresolution(ret);
        }
        else if(ret[0] == 'N' || ret[0] =='S' || ret[0] =='W' || ret[0] == 'E')
        {
            ft_read_texture_from_cub(ret);
        }
            
        else if(ret[0] == 'F')
        {
            if (data_cub.F == -1)
            {
                if(ret[1] != '\0' && ret[2] != '\0')
                    data_cub.F = ft_getColorIntegerFromRGB_F(ret);
                else
                ft_print_err("Floor color is empty");
            }
            else
                ft_print_err("Duplicate color of floor");
            
        }
        else if (ret[0] == 'C')
        {
            if(data_cub.C == -1)
            {
                if(ret[1] != '\0' && ret[2] != '\0')
                    data_cub.C = ft_getColorIntegerFromRGB_C(ret);
                else
                    ft_print_err("C color is empty");
            }
            else
                ft_print_err("Duplicate color of Ceilling");
            
        }
        else if (is_all() == 1 && is_valide(str) == 1) 
        {
            sprite.num_sprites += ft_checksprite(str);
            ft_read_map(str);
            check_border(str);
            check_spaces(str);
            data_cub.map_j++;
        }
        else if (str[0] == '\0' && data_cub.map_j > 0)
        {
            ft_print_err("empty line in map");
        }
        else if (is_valide(ret) != 1 && data_cub.map_j > 0)
        {
            ft_print_err("line in map not valide");
        }
    // else
    // {
    //     ft_print_err("Invalide Configuration!");
    // }
}
}

void ft_check_param()
{
    if(data_cub.R_x == -1 || data_cub.R_y == -1 || data_cub.NO == NULL
    || data_cub.SO == NULL|| data_cub.WE == NULL || data_cub.EA == NULL
    || data_cub.S == NULL || data_cub.F == -1 || data_cub.C == -1)
        ft_print_err("Invalid Configuration");
}
int ft_read_from_dotcub(char *filename)
{
    int fd;
    char *str;
    int r;

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
        
    int i =0;
    int j=0;
//    printf("%s\n", data_cub.string_map);
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