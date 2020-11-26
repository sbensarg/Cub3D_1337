#include "cub3d.h"

void            my_mlx_pixel_put(int x, int y, int color)
{
    char    *dst;

    dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
unsigned int    ft_read_from_memory(t_data texture, int x, int y)
{
    char    *dst;

    dst = texture.addr + (y * texture.line_length + x * (texture.bits_per_pixel / 8));
    return (*(unsigned int*)dst);
}


int		nextposallowed(float newplayerx, float newplayery)
{
	int	gridx;
	int	gridy;

	if (newplayerx < 0 || newplayerx > consts.window_width
	|| newplayery < 0 || newplayery > consts.window_height)
		return (1);
	if (player.x - newplayerx <= 0)
		newplayerx += player.radius + 1;
	else
		newplayerx -= player.radius + 1;
	if (player.y - newplayery <= 0)
		newplayery += player.radius + 1;
	else
		newplayery -= player.radius + 1;
	gridx = floor(newplayerx / consts.tile_size);
	gridy = floor(newplayery / consts.tile_size);
	return (data_cub.map[gridy][gridx]);
}

int		iswall(float x,	float y)
{
	int	gridx;
	int	gridy;

	if (x < 0 || x > consts.window_width || y < 0 || y > consts.window_height)
		return (1);
	gridx = floor(x / consts.tile_size);
	gridy = floor(y / consts.tile_size);

	return (data_cub.map[gridy][gridx]);
}


