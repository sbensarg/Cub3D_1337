/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:02:47 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/27 12:19:49 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../GNL/get_next_line.h"
#include "../cub3d.h"

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