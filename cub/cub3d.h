/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:25:51 by sbensarg          #+#    #+#             */
/*   Updated: 2021/01/07 16:26:46 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx_beta/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

# define MAX_VALUE 2147483647

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define ESC 53

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define PI 3.14159

int					g_texturenum;
int					g_color;
int					g_textureoffsetx;
int					g_textureofssety;
int					g_nbr_element;
float				*g_raydistance;
typedef struct		s_consts
{
	int		tile_size;
	int		map_num_rows;
	int		map_num_cols;
	int		window_width;
	int		window_height;
	int		display_window_width;
	int		display_window_height;
	int		ray_width;
	int		num_of_rays;
	double	fov_ang;
	double	angleinc;
	float	maxvalue;
	float	first_ray_ang;
	float	last_ray_ang;
}					t_consts;

typedef struct		s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		tw;
	int		th;
}					t_data;

typedef struct		s_pos
{
	int		angleisup;
	int		angleisleft;
	int		angleisdown;
	int		angleisright;
}					t_pos;

typedef struct		s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
}					t_mlx;

typedef struct		s_player
{
	float	x;
	float	y;
	float	radius;
	float	turndirection;
	float	walkdirection;
	float	rotationangle;
	float	movespeed;
	float	rotationspeed;
	float	strafe;
	float	movestep;
	float	newplayerx;
	float	newplayery;
	float	checkplayerx;
	float	checkplayery;
	int		posallowed;
	float	angle;
}					t_player;

typedef struct		s_ray
{
	float	angel;
	int		ray;
	float	v_wallhitx;
	float	v_wallhity;
	float	h_wallhitx;
	float	h_wallhity;
	float	distance;
	float	horz_hit_distance;
	float	vert_hit_distance;
	int		vert;
	float	ray_lenght;
	float	distanceprojectionplane;
	int		wallstripheight;
	int		wallstripheight_d;
	float	correctdist;
}					t_ray;

typedef struct		s_datacub
{
	long	r_x;
	long	r_y;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		f;
	int		c;
	int		**map;
	int		map_i;
	int		map_j;
	char	*string_map;
	int		playeri;
	int		playerj;
	int		playerdirect;
}					t_datacub;

typedef struct		s_sprite
{
	int		**sprite_map;
	int		num_sprites;
	double	*spritedistance;
	float	spriteangle;
	float	firstangle;
	float	lastangle;
	float	size_sprite;
	float	startfov;
	float	endfov;
	float	ray_lenght;
	float	distanceprojectionplane;
	float	correctdist;
	float	stripheight;
	int		nbrofrays;
	int		x;
	int		j;
	int		l;
	int		fxa;
	int		fya;
	int		lxa;
	int		lya;
}					t_sprite;

typedef struct		s_hozinter{
	int		foundhorzwallhit;
	float	xstep;
	float	ystep;
	float	nexthorztouchy;
	float	nexthorztouchx;
}					t_hozinter;

typedef struct		s_vertinter{
	int		foundvertwallhit;
	float	xstep;
	float	ystep;
	float	nextverttouchy;
	float	nextverttouchx;
}					t_vertinter;

typedef struct		s_bmp_file{
	int		bitmap_size;
	char	tag[2];
	int		header[13];
	char	*bitmap;
	int		dest;
	int		src;
}					t_bmp_file;

typedef struct		s_freeall{
	void				*addr;
	struct s_freeall	*next;
}					t_freeall;

t_player			g_player;
t_data				g_img;
t_data				g_texture[5];
t_mlx				g_data;
t_pos				g_pos;
t_consts			g_consts;
t_ray				g_ray;
t_datacub			g_data_cub;
t_sprite			g_sprite;
t_hozinter			g_hozinter;
t_vertinter			g_vertinter;
t_bmp_file			g_bmp;
t_freeall			*g_freeall;
t_freeall			*g_list;
void				my_mlx_pixel_put(int x, int y, int color);
int					ft_read_from_dotcub(char *filename);
long				ft_atoi(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen1(const char *str);
char				*ft_strjoin1(char const *s1, char const *s2);
void				*ft_memcpy1(void *dest, const void *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strdup1(char *s1);
void				ft_isdigit(char *c);
void				init_consts(void);
void				init_player(void);
void				render_map();
void				render_player(int color);
void				check_derection(float angle);
void				render_rays(void);
int					iswall(float x, float y);
int					nextposallowed(float newplayerx, float newplayery);
unsigned int		ft_read_from_memory(t_data texture, int x, int y);
void				write_bmp(char *filename, char rgb[]);
float				fmod_angle(float angle);
void				rendersprites();
float				putray(float angle);
void				ft_print_err(char *s);
void				check_spaces(char *str);
void				check_border(char *str);
void				check_tab_spaces();
void				init_data();
void				ft_check_param();
int					len_num(long long nbr);
void				check_ext(char *ext);
int					check_path(char *path);
void				init_sprite();
void				sprite_position(int *i, int *j, int *k, int *l);
int					ft_checksprite(char *str);
void				init_p(int *i, int *j, int *k);
void				check_player();
int					is_all();
int					is_all1();
int					is_valide(char *str);
int					is_player(int *k);
void				ft_read_map(char *str);
void				ft_init_map();
void				map(int *i, int *j, int *k, int *l);
void				ft_rempli_map();
void				ft_rempli_spaces();
void				ft_getresolution(char *str);
int					ft_getcolorintegerfromrgb_f(char *str);
int					ft_getcolorintegerfromrgb_c(char *str);
void				ft_read_texture_from_cub(char *str);
char				*check_identifer(char *str);
char				*check_s(char *str);
void				ft_read_no(char **str);
void				ft_read_so(char **str);
void				ft_read_we(char **str);
void				ft_read_ea(char **str);
void				ft_read_s(char **str);
void				draw_wall(int tilex, int tiley, int height);
int					ft_nexthorztinter(float *horzwallhitx, float *horzwallhity);
int					ft_nextvertinter(float *vertwallhitx, float *vertwallhity);
void				calc_stripheight();
void				putpixel_sprite(int x, int y, int height);
void				ft_bubble_sorte(double *distance);
void				init_texture(void);
void				init_rotationangle(void);
int					ft_close(void);
int					ft_keypressed(int keycode, void *lol);
int					ft_keyreleased(int keycode, void *lol);
int					update(void);
void				init_struct(void);
void				ft_add_to_freeall(void *addr);
void				freestrct();
void				ft_getmap(char **str, char **ret);
#endif
