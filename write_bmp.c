/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 02:45:45 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/02 17:32:07 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp_info_header(int filesize)
{
	bmp.header[0] = filesize + 54;
	bmp.header[1] = 0;
	bmp.header[2] = 0x36;
	bmp.header[3] = 0x28;
	bmp.header[4] = consts.display_window_width;
	bmp.header[5] = consts.display_window_height;
	bmp.header[6] = 0x180001;
	bmp.header[7] = 0;
	bmp.header[8] = 0;
	bmp.header[9] = 0;
	bmp.header[10] = 0;
	bmp.header[11] = 0;
	bmp.header[12] = 0;
}

void	init_bmp(void)
{
	int k;

	k = 0;
	bmp.bitmap = (char *)malloc(bmp.bitmap_size * sizeof(char));
	ft_add_to_freeall(bmp.bitmap);
	while (k < bmp.bitmap_size)
	{
		bmp.bitmap[k] = 0;
		k++;
	}
}

void	rempli_bmp(char **rgb)
{
	int		i;
	int		j;
	int		l;
	char	*rgb1;

	i = 0;
	j = 0;
	l = 0;
	rgb1 = *rgb;
	j = consts.display_window_height - 1;
	while (j >= 0)
	{
		while (i < consts.display_window_width)
		{
			bmp.dest = ((l * (consts.display_window_width * 3) + i * 3));
			bmp.src = ((j * img.line_length + i * (img.bits_per_pixel / 8)));
			bmp.bitmap[bmp.dest] = rgb1[bmp.src];
			bmp.bitmap[bmp.dest + 1] = rgb1[bmp.src + 1];
			bmp.bitmap[bmp.dest + 2] = rgb1[bmp.src + 2];
			i++;
		}
		i = 0;
		j--;
		l++;
	}
}

void	write_bmp(char *filename, char *rgb)
{
	int	i;
	int	j;
	int	l;
	int fd;

	i = 0;
	j = 0;
	l = 0;
	bmp.tag[0] = 'B';
	bmp.tag[1] = 'M';
	bmp.bitmap_size = consts.display_window_width * consts.display_window_height
	* 3;
	bmp_info_header(bmp.bitmap_size);
	init_bmp();
	rempli_bmp(&rgb);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	write(fd, bmp.tag, 2);
	write(fd, bmp.header, sizeof(bmp.header));
	write(fd, bmp.bitmap, bmp.bitmap_size * sizeof(char));
}
