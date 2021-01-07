/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:27:51 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/06 16:02:25 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_struct(void)
{
	g_freeall = malloc(sizeof(t_freeall));
	g_list = g_freeall;
	if (g_freeall == NULL)
		exit(EXIT_FAILURE);
	g_freeall->next = NULL;
}

void	ft_add_to_freeall(void *addr)
{
	g_freeall->addr = addr;
	g_freeall->next = malloc(sizeof(t_freeall));
	g_freeall = g_freeall->next;
	g_freeall->next = NULL;
}

void	freestrct(void)
{
	t_freeall *temp;

	temp = g_list;
	while (g_list)
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
