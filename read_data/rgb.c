/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:02:47 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/02 18:38:29 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../GNL/get_next_line.h"
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
		ft_print_err("invalid dsd");
	while (str1[*i + 1] == ' ')
		(*i)++;
	ft_isdigit(str1 + *i + 1);
	nbr2 = ft_atoi(str1 + *i + 1);
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

int		ft_getcolorintegerfromrgb_f(char *str)
{
	int		nbr1;
	int		nbr2;
	int		nbr3;
	char	**ptr;
	int		i;

	i = 0;
	nbr1 = 0;
	nbr2 = 0;
	nbr3 = 0;
	ptr = ft_split(str, ' ');
	while (ptr[i++])
		ft_add_to_freeall(ptr[i-1]);
	ft_add_to_freeall(ptr);
	i = 2;
	if (ft_strncmp(ptr[0], "F", 2) != 0)
		ft_print_err("ivalide identifer (F)");
	while (str[i] == ' ')
		i++;
	ft_isdigit(str + i);
	nbr1 = ft_atoi(str + i);
	nbr2 = get_nbr(&str, &i);
	i++;
	nbr3 = get_nbr(&str, &i);
	check_after_getnbr(&str, &i);
	if (nbr1 > 255 || nbr2 > 255 || nbr3 > 255
			|| nbr1 < 0 || nbr2 < 0 || nbr3 < 0)
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

	i = 0;
	nbr1 = 0;
	nbr2 = 0;
	nbr3 = 0;
	ptr = ft_split(str, ' ');
	while (ptr[i++])
		ft_add_to_freeall(ptr[i-1]);
	ft_add_to_freeall(ptr);
	i = 2;
	if (ft_strncmp(ptr[0], "C", 2) != 0)
		ft_print_err("ivalide identifer (C)");
	while (str[i] == ' ')
		i++;
	ft_isdigit(str + i);
	nbr1 = ft_atoi(str + i);
	nbr2 = get_nbr(&str, &i);
	i++;
	nbr3 = get_nbr(&str, &i);
	check_after_getnbr(&str, &i);
	if (nbr1 > 255 || nbr2 > 255 || nbr3 > 255
			|| nbr1 < 0 || nbr2 < 0 || nbr3 < 0)
		ft_print_err("invalide data");
	return ((nbr1 << 16) + (nbr2 << 8) + nbr3);
}
