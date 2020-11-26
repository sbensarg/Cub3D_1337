/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 02:45:45 by sbensarg          #+#    #+#             */
/*   Updated: 2020/11/14 20:20:25 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	header_bmp()
{
	
}
void    write_bmp(char *filename, char *rgb)
{
	int	bitmap_size;
	int	i = 0;
	int	j = 0;
	int	l = 0;
	//char tag[] = {'B', 'M'};
	char *tag;
	tag = malloc(sizeof(char) * 3);
	 tag[0] = 'B';
	 tag[1] = 'M';
	 tag[2] = '\0';
	//strcpy(tag, "BM");
    // int header[] = {
    //     0, 0, 0x36, 0x28, consts.window_width, consts.window_height, 0x180001, 
    //     0, 0, 0x002e23, 0x002e23, 0, 0
    // };
	int *header;
	header = (int *)malloc(sizeof(int) * 52);
	bitmap_size = consts.window_width * consts.window_height * 3;
	header[0] = 54 + bitmap_size;
	header[1] = 0;
	header[2] = 0;
	header[3] = 0x36;
	header[4] = 0x28;
	header[5] = consts.window_width;
	header[6] = consts.window_height;
	header[7] = 0x180001;
	header[8] = 0;
	header[9] = 0;
	header[10] = 0x002e23;
	header[11] = 0x002e23;
	header[12] = 0;
	header[13] = 0;
	char *bitmap = (char *) malloc(bitmap_size * sizeof(char));
	for (int k = 0; k < bitmap_size; k++) 
		bitmap[k] = 0;
	j = consts.window_height - 1;
	while (j >= 0)
	{
		while (i < consts.window_width)
		{
			int dest = ((l * (consts.window_width * 3) + i * 3));
			int src = ((j * img.line_length + i * (img.bits_per_pixel / 8)));
			bitmap[dest] = rgb[src];
			bitmap[dest + 1] = rgb[src + 1];
			bitmap[dest + 2] = rgb[src + 2];
			i++;
		}
		i = 0;
		j--;
		l++;
	}
	int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	write(fd, tag, 2);
    write(fd, header, 52);
    write(fd, bitmap, bitmap_size * sizeof(char));
}