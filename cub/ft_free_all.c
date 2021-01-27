/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:27:51 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/27 10:46:05 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(void)
{
	g_freeall = malloc(sizeof(t_freeall));
	if (g_freeall == NULL)
		ft_print_perror();
	g_list = g_freeall;
	g_freeall->next = NULL;
}

void	ft_add_to_freeall(void *addr)
{
	g_freeall->addr = addr;
	if ((g_freeall->next = malloc(sizeof(t_freeall))) == NULL)
		ft_print_perror();
	g_freeall = g_freeall->next;
	g_freeall->next = NULL;
}

void	freestrct(void)
{
	t_freeall *temp;

	temp = g_list;
	while (g_list && g_list->next)
	{
		free(g_list->addr);
		g_list = g_list->next;
	}
	g_list = temp;
	while (g_list)
	{
		temp = g_list->next;
		free(g_list);
		g_list = temp;
	}
}

void	free_ptr(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i++])
		ft_add_to_freeall(ptr[i - 1]);
	ft_add_to_freeall(ptr);
}
