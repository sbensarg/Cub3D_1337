/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:28:20 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/20 19:42:35 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



static int	max_int(long a, int s)
{
	if (a > 9223372036854775807)
	{
		if (s == -1)
			return (0);
		else if (s == 1)
			return (-1);
	}
	return (1);
}

long			ft_atoi(const char *str)
{
	long		i;
	long	a;
	long		s;

	i = 0;
	a = 0;
	s = 1;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
	{
		if (str[i] == 27)
			return (0);
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		a = a * 10 + str[i++] - 48;
		max_int(a, s);
	}
	return (a * s);
}
