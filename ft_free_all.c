/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 16:27:51 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/02 17:42:08 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_struct(void)
{
    freeall = malloc(sizeof(t_freeall));
	list = freeall;
	if(freeall == NULL)
		exit(EXIT_FAILURE);
    freeall->next = NULL;
}

void    ft_add_to_freeall(void *addr)
{   
    freeall->addr = addr;
    freeall->next = malloc(sizeof(t_freeall));
    freeall = freeall->next;
    freeall->next = NULL;
}



void    freestrct()
{
    //free all adresses added to the list malloced while we run the programme
    t_freeall *temp;
    temp = list;
    while (list)
    {
        free(list->addr);
        list = list->next;
    }
    //free the list of structs
    list = temp;
    while (list)
    {
        temp = list->next;
        free(list);
        list = temp;
    }
}