/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:46:33 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/20 16:48:35 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		fct(char s, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == s)
			return (1);
		i++;
	}
	return (0);
}

static char		*is_null(char const *s1, char const *set)
{
	if (set == NULL)
		return ((char *)s1);
	return (NULL);
}

char			*var(int start, int end)
{
	char	*vr;

	if (end < start)
	{
		vr = malloc(1);
		if (!vr)
			return (NULL);
		vr[0] = '\0';
		return (vr);
	}
	return (NULL);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (is_null(s1, set));
	start = 0;
	end = ft_strlen1(s1) - 1;
	while (fct(s1[start], (char *)set) != 0)
		start++;
	while (fct(s1[end], (char *)set) != 0 && end > 0)
		end--;
	if (end < start)
		return (var(start, end));
	str = (char *)malloc(end - start + 2);
	if (str == NULL)
		return (NULL);
	ft_memcpy1(str, s1 + start, end - start + 1);
	str[end - start + 1] = '\0';
	return (str);
}