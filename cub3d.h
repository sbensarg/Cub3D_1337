/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chicky <chicky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:25:51 by sbensarg          #+#    #+#             */
/*   Updated: 2020/12/28 22:02:31 by chicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_VALUE 2147483647

// #define KEY_UP 126
// #define KEY_DOWN 125
// #define KEY_LEFT 123
// #define KEY_RIGHT 124
// #define esc 53

// #define KEY_W 13
// #define KEY_S 1
// #define KEY_A 0
// #define KEY_D 2
// #define PI 3.14159

//for ununtu
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363

#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100
#define esc 65307
#define PI 3.14159


int		texturenum;
int		color;
int		textureoffsetx;
int		textureofssety;
int		nbr_element;
typedef struct
{
	int tile_size;
	int map_num_rows;
	int map_num_cols;
	int window_width;
	int window_height;
	int display_window_width;
	int display_window_height;
	int ray_width;
	int num_of_rays;
	double fov_ang;
	double	angleinc;
	float	maxvalue;
	float	first_ray_ang;
	float	last_ray_ang;
	
}					t_consts;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
	int			tw;
	int			th;
}               t_data;

typedef struct
{
    int			angleisup;
    int			angleisleft;
    int			angleisdown;
    int			angleisright;
}               t_pos;

typedef struct
{
	void          *mlx_ptr;
	void          *mlx_win;
}					t_mlx;

typedef struct
{
	float                   x;
	float 				    y;
	float 			   radius;
	float 		turndirection;
	float		walkdirection;
	float 		rotationangle;
	float 			movespeed;
	float 		rotationspeed;
	float		strafe;
}					 t_player;

typedef struct
{
	float	angel;
	int		ray;
}					t_ray;

typedef struct  s_datacub {
    long		R_x;
    long		R_y;
    char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*S;
	int 	F;
	int		C;
	int**	map;
	int     map_i;
	int		map_j;
	char    *string_map;
	int		playerI;
	int		playerJ;
	int		playerdirect;
}              t_datacub;

typedef struct s_sprite {
int**	sprite_map;
int		num_sprites;
double 	*spritedistance;
}				t_sprite;

t_player	player;
t_data		img;
t_data		texture[5];
t_mlx		data;
t_pos		pos;
t_consts	consts;
t_ray		ray;
t_datacub	data_cub;
t_sprite	sprite;

void            my_mlx_pixel_put(int x, int y, int color);
int				ft_read_from_dotcub(char *filename);
long			ft_atoi(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen1(const char *str);
char			*ft_strjoin1(char const *s1, char const *s2);
void			*ft_memcpy1(void *dest, const void *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strdup1(char *s1);
void			ft_isdigit(char *c);
void			init_consts(void);
void			init_player(void);
void			render_map();
void			render_player(int color);
void			check_derection(float angle);
void			render_rays(void);
int				iswall(float x,	float y);
int				nextposallowed(float newplayerx, float newplayery);
unsigned int    ft_read_from_memory(t_data texture, int x, int y);
void			write_bmp(char *filename, char rgb[]);
void			fmod_angle(float angle);
void			rendersprites();
float			putray(float angle);
void			ft_print_err(char *s);
void			check_spaces(char *str);
void			check_border(char *str);
void			check_tab_spaces();
void			init_data();
void			ft_check_param();
int				len_num(long long nbr);
void			check_ext(char *ext);
int				check_path(char *path);
void			init_sprite();
void			sprite_position(int *i, int *j, int *k, int *l);
int				ft_checksprite(char *str);
void			init_p(int *i, int *j,int *k);
void			check_player();
int				is_all();
int				is_all1();
int				is_valide(char *str);
int				is_player(int *k);
void			ft_read_map(char *str);
void			ft_init_map();
void			map(int *i, int *j, int *k, int *l);
void			ft_rempli_map();
void			ft_rempli_spaces();
void			ft_getresolution(char *str);
int				ft_getColorIntegerFromRGB_F(char *str);
int				ft_getColorIntegerFromRGB_C(char *str);
void			ft_read_texture_from_cub(char *str);
char			*check_identifer(char *str);
char			*check_S(char *str);
void			ft_read_NO(char **str);
void			ft_read_SO(char **str);
void			ft_read_WE(char **str);
void			ft_read_EA(char **str);
void			ft_read_S(char **str);

float *raydistance;
#endif
