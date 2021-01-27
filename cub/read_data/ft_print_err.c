/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:03:42 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/08 18:09:28 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../GNL/get_next_line.h"
#include "../cub3d.h"

void		ft_print_err(char *s)
{
	write(2, "Error\n", 6);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit(0);
}

void		ft_print_perror(void)
{
	write(2, "Error\n", 6);
	perror("");
	exit(0);
}
