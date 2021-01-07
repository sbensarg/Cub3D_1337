/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:18:50 by sbensarg          #+#    #+#             */
/*   Updated: 2019/10/19 19:12:56 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin1(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	int		sum;
	char	*newstr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen1((char *)s1);
	lens2 = ft_strlen1((char *)s2);
	sum = lens1 + lens2;
	newstr = (char *)malloc(sum + 1);
	if (newstr == NULL)
		return (NULL);
	ft_memcpy1(newstr, s1, lens1);
	ft_memcpy1(newstr + lens1, s2, lens2 + 1);
	return (newstr);
}
