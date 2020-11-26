/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:18:58 by sbensarg          #+#    #+#             */
/*   Updated: 2020/11/20 17:21:08 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup1(char *s1)
{
	char *dest;

	dest = (char*)malloc(sizeof(char) * (ft_strlen1(s1) + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy1(dest, s1, (ft_strlen1(s1) + 1));
	return (dest);
}
