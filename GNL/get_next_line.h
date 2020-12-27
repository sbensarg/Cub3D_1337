/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 22:08:07 by sbensarg          #+#    #+#             */
/*   Updated: 2020/10/15 00:02:28 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>



size_t			ft_strlen(const char *str);
void			*ft_memcpy(void *dest, char *src, size_t n);
char			*ft_strjoin(char **s1, char **s2);
char			*ft_strchr(const char *s, int c);
int				get_next_line(int fd, char **line);
char			*ft_strdup(char *str1);
#endif
