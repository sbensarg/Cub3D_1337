/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:08:03 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/23 00:22:34 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int putray_forsprite(float dist, float angle)
{
    int xa;
    int ya;
    int j = 0;
    int found = 0;
    
   	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle = (2 * PI) + angle;
    while(j < dist)
    {
        xa = player.x - cos(angle) * (j);
        ya = player.y - sin(angle) * (j);
        if(iswall(xa, ya) == 1)   
            return (0);
        j++;
    }
    return(1);
}

void ft_bubble_sorte(double *distance)
{
    int i;
    int j;
    int temp;
    i = 0;
    j = 0;
    while(i + 1 < sprite.num_sprites)
    {
        if(distance[i] < distance[i+1])
        {
            temp = distance[i];
            distance[i] = distance[i+1];
            distance[i+1] = temp;

            temp = sprite.sprite_map[i][0];
            sprite.sprite_map[i][0] = sprite.sprite_map[i + 1][0];
            sprite.sprite_map[i + 1][0] = temp;

            temp = sprite.sprite_map[i][1];
            sprite.sprite_map[i][1] = sprite.sprite_map[i + 1][1];
            sprite.sprite_map[i + 1][1] = temp;

            i = -1;
        }
        i++;
    }
}

void ft_sortsprites()
{
    int l;
    
    l = 0;
    sprite.spritedistance = malloc(sizeof(double) * sprite.num_sprites);
    while (l < sprite.num_sprites)
    {
       sprite.spritedistance[l] = sqrt((player.x - sprite.sprite_map[l][1]) * (player.x - sprite.sprite_map[l][1]) + (player.y - sprite.sprite_map[l][0]) * (player.y - sprite.sprite_map[l][0]));
        l++;
    }
    ft_bubble_sorte(sprite.spritedistance);
    
} 

void draw_sprite(int x, int y, int height, int ray, int nbrofrays)
{
    int j;
    unsigned int color;
    int i;
    
    j = 0;
    i = 0;
    while (j < height)
    {
        if (y + j >= 0 && y + j < consts.display_window_height)
        {
            color = ft_read_from_memory(texture[4],texture[4].tw * ray / nbrofrays,texture[4].th * j / height);
            if (color != 0x0000)
                my_mlx_pixel_put(x, y + j, color);
        }
        j++;
    }
}
void    rendersprites()
{
    float   spriteangle;
    float   firstangle;
    float   lastangle;
    float   size_sprite = 0;
    float     startfov;
    float      endfov;
    float   ray_lenght = 0;
    float   distanceprojectionplane;
    float   correctdist;
    float   stripheight;
    int x;
    int l;
    int xa;
    int ya;
    int firstrayanglesprite;
    int lastrayanglesprite;
    int fxa, fya;
    int lxa, lya;
    int v = 0;
    int     *spriteorder;
    double  *spritedistance;
    
    ft_sortsprites();
    l = 0;
    int j = 0;
    int i = 0;
    spriteangle = 0;
    startfov = player.rotationangle - (consts.fov_ang / 2);
    startfov = fmod(startfov, 2 * PI);
	if (startfov < 0)
		startfov = (2 * PI) + startfov;
    endfov = player.rotationangle + (consts.fov_ang / 2);
    endfov = fmod(endfov, 2 * PI);
	if (endfov < 0)
		endfov = (2 * PI) + endfov;
    while (l < sprite.num_sprites)
    {
        spriteangle =  atan2(player.y - sprite.sprite_map[l][0], player.x - sprite.sprite_map[l][1]);
        spriteangle = fmod(spriteangle, 2 * PI);
        if (spriteangle < 0)
            spriteangle = (2 * PI) + spriteangle;
     
                fxa = sprite.sprite_map[l][1] - cos(spriteangle - 1.5708) * (consts.tile_size/2);
                fya = sprite.sprite_map[l][0] - sin(spriteangle - 1.5708) * (consts.tile_size/2);
                firstangle =  atan2(player.y - fya, player.x - fxa);
                lxa = sprite.sprite_map[l][1] - cos(spriteangle + 1.5708) * (consts.tile_size/2);
                lya = sprite.sprite_map[l][0] - sin(spriteangle + 1.5708) * (consts.tile_size/2);
                lastangle =  atan2(player.y - lya, player.x - lxa);
                 
                lastangle = fmod(lastangle, 2 * PI);
                x = -1;
                if(lastangle < firstangle)
                    lastangle +=  (2 * PI);
                    if (lastangle < 0)
                    lastangle = (2 * PI) + lastangle;
                    j= 0;
                int nbrofrays = fabs(firstangle - lastangle) / consts.angleinc;
                while (j < nbrofrays)
                {
                    firstangle = fmod(firstangle, 2 * PI); 
                    if (firstangle < 0)
                        firstangle = (2 * PI) + firstangle;
                    correctdist =  sprite.spritedistance[l] / cos(fabs(spriteangle - firstangle));
                    distanceprojectionplane = (consts.window_width / 2) / tan(consts.fov_ang / 2);
		            size_sprite = (consts.tile_size / correctdist) * distanceprojectionplane;
                    stripheight = (size_sprite * consts.display_window_width) / consts.window_width;
                    if ((firstangle >= startfov && firstangle <= startfov + consts.fov_ang))
                    {
                        x = fabs(startfov - firstangle) / consts.angleinc;
                        break;
                    }
                    else if(firstangle <= fmod(startfov + consts.fov_ang, 2 * PI) && startfov + consts.fov_ang > 2 * PI)
                    {
                        x = consts.display_window_width - (fabs(firstangle - fmod(startfov + consts.fov_ang, 2 * PI)) / consts.angleinc);
                        break;
                    }
                    j++;
                    firstangle += consts.angleinc;
              }
              while (j < nbrofrays)
              {
                    if (x != -1 && raydistance[x] > sprite.spritedistance[l])
                        draw_sprite(x, consts.display_window_height/2 - stripheight/2, stripheight, j, nbrofrays);
                    x++;
                    j++;
              }
         l++;
    }
    free(raydistance);
}