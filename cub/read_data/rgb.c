/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:02:47 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/27 10:02:53 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../GNL/get_next_line.h"
#include "../cub3d.h"

int		get_nbr(char **str, int *i)
{
	char	*str1;
	int		nbr2;

	str1 = *str;
	while (str1[*i] != '\0' && (str1[*i] == ' '
				|| (str1[*i] >= '0' && str1[*i] <= '9')))
		(*i)++;
	if (str1[*i] != ',')
		ft_print_err("invalid data!!");
	while (str1[*i + 1] == ' ')
		(*i)++;
	nbr2 = ft_atoi(str1 + *i + 1);
	if (nbr2 > 255 || nbr2 < 0)
		ft_print_err("invalide data");
	return (nbr2);
}

void	check_after_getnbr(char **str, int *i)
{
	char *str1;

	str1 = *str;
	while (str1[*i + 1] != '\0' && str1[*i + 1] >= '0' && str1[*i + 1] <= '9')
		(*i)++;
	if (str1[*i + 1] != '\0')
		ft_print_err("invalid nbr");
}

void	check_rgb(char **ptr)
{
	char	**ptr2;
	int		j;

	j = 0;
	ptr2 = ft_split(ptr[1], ',');
	free_ptr(ptr2);
	while (ptr2[j])
		j++;
	if (j != 3)
		ft_print_err("invalide data!!");
}

int		ft_getcolorintegerfromrgb_f(char *str)
{
	int		nbr1;
	int		nbr2;
	int		nbr3;
	char	**ptr;
	int		i;

	i = 2;
	nbr1 = 0;
	nbr2 = 0;
	nbr3 = 0;
	ptr = ft_split(str, ' ');
	free_ptr(ptr);
	if (ft_strncmp(ptr[0], "F", 2) != 0)
		ft_print_err("ivalide identifer (F)");
	check_rgb(ptr);
	while (str[i] == ' ')
		i++;
	nbr1 = ft_atoi(str + i);
	nbr2 = get_nbr(&str, &i);
	i++;
	nbr3 = get_nbr(&str, &i);
	check_after_getnbr(&str, &i);
	if (nbr1 > 255 || nbr1 < 0)
		ft_print_err("invalide data");
	return ((nbr1 << 16) + (nbr2 << 8) + nbr3);
}

int		ft_getcolorintegerfromrgb_c(char *str)
{
	int		nbr1;
	int		nbr2;
	int		nbr3;
	char	**ptr;
	int		i;

	i = 2;
	nbr1 = 0;
	nbr2 = 0;
	nbr3 = 0;
	ptr = ft_split(str, ' ');
	free_ptr(ptr);
	if (ft_strncmp(ptr[0], "C", 2) != 0)
		ft_print_err("ivalide identifer (C)");
	check_rgb(ptr);
	while (str[i] == ' ')
		i++;
	nbr1 = ft_atoi(str + i);
	nbr2 = get_nbr(&str, &i);
	i++;
	nbr3 = get_nbr(&str, &i);
	check_after_getnbr(&str, &i);
	if (nbr1 > 255 || nbr1 < 0)
		ft_print_err("invalide data");
	return ((nbr1 << 16) + (nbr2 << 8) + nbr3);
}
