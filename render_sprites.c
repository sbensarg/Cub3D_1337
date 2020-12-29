/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chicky <chicky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:08:03 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/29 15:47:12 by chicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void ft_sortsprites()
{
    int l;
    
    l = 0;
    sprite.spritedistance = malloc(sizeof(double) * sprite.num_sprites);
    while (l < sprite.num_sprites)
    {
       sprite.spritedistance[l] = sqrt((player.x - sprite.sprite_map[l][1])
       * (player.x - sprite.sprite_map[l][1])
       + (player.y - sprite.sprite_map[l][0])
       * (player.y - sprite.sprite_map[l][0]));
        l++;
    }
    ft_bubble_sorte(sprite.spritedistance);
    
} 

void calc_sprite_angle()
{
    sprite.spriteangle =  atan2(player.y - sprite.sprite_map[sprite.l][0],
    player.x - sprite.sprite_map[sprite.l][1]);
    sprite.spriteangle = fmod_angle(sprite.spriteangle);
    sprite.fxa = sprite.sprite_map[sprite.l][1]
    - cos(sprite.spriteangle - 1.5708) * (consts.tile_size/2);
    sprite.fya = sprite.sprite_map[sprite.l][0]
    - sin(sprite.spriteangle - 1.5708) * (consts.tile_size/2);
    sprite.firstangle =  atan2(player.y - sprite.fya, player.x - sprite.fxa);
    sprite.lxa = sprite.sprite_map[sprite.l][1]
    - cos(sprite.spriteangle + 1.5708) * (consts.tile_size/2);
    sprite.lya = sprite.sprite_map[sprite.l][0]
    - sin(sprite.spriteangle + 1.5708) * (consts.tile_size/2);
    sprite.lastangle =  atan2(player.y - sprite.lya, player.x - sprite.lxa);
    sprite.firstangle = fmod_angle(sprite.firstangle);
    sprite.lastangle = fmod_angle(sprite.lastangle);
            if(sprite.lastangle < sprite.firstangle)
            sprite.lastangle += (2 * PI);
}

void    calc_x()
{
    while (sprite.j < sprite.nbrofrays)
    {
        sprite.firstangle = fmod_angle(sprite.firstangle);
        calc_stripheight();
        if ((sprite.firstangle >= sprite.startfov
        && sprite.firstangle <= sprite.startfov + consts.fov_ang))
        {
            sprite.x = fabs(sprite.startfov - sprite.firstangle)
            / consts.angleinc;
            break;
        }
        else if(sprite.firstangle <= sprite.endfov
        && sprite.startfov + consts.fov_ang > 2 * PI)
        {
            sprite.x = consts.display_window_width - (fabs(sprite.firstangle
            - fmod(sprite.startfov + consts.fov_ang, 2 * PI))
            / consts.angleinc);
            break;
        }
        sprite.j++;
        sprite.firstangle += consts.angleinc;
    }
}

void draw_sprite()
{
    while (sprite.j < sprite.nbrofrays)
    {
        if (sprite.x != -1 &&
        raydistance[sprite.x] > sprite.spritedistance[sprite.l])
        {
            putpixel_sprite(sprite.x,
            consts.display_window_height/2 - sprite.stripheight/2,
            sprite.stripheight);
        }
        sprite.x++;
        sprite.j++;
    }
}

void    rendersprites()
{    
    ft_sortsprites();
    sprite.l = 0;
    sprite.j = 0;
    sprite.spriteangle = 0;
    sprite.size_sprite = 0;
    sprite.ray_lenght = 0;
    while (sprite.l < sprite.num_sprites)
    {
        calc_sprite_angle();
        sprite.x = -1;
        sprite.j = 0;
        sprite.nbrofrays = fabs(sprite.firstangle - sprite.lastangle)
        / consts.angleinc; 
        calc_x();   
        draw_sprite();
    sprite.l++;
    }
    free(raydistance);
}