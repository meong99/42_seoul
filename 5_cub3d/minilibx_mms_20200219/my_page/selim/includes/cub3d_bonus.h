/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:28:19 by selim             #+#    #+#             */
/*   Updated: 2021/02/04 17:13:50 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define FALSE					0
# define TRUE					1
# define BUFFER_SIZE			16

# define KEY_1					18
# define KEY_2					19
# define KEY_3					20
# define KEY_4					21
# define KEY_Q					12
# define KEY_W					13
# define KEY_E					14
# define KEY_R					15
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_I					34
# define KEY_O					31
# define KEY_P					35
# define KEY_J					38
# define KEY_K					40
# define KEY_L					37
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_UP 				126
# define KEY_DOWN				125
# define KEY_MINUS				27
# define KEY_PLUS				24

# define KEY_TAB				48
# define KEY_MAJ				257
# define KEY_ESC				53

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_RELEASE	5
# define X_EVENT_MOUSE_MOVE		6
# define X_EVENT_GAME_CLEAR		7
# define X_EVENT_KEY_EXIT		17

# define NSEW					"NSEW"
# define MOVESPEED				2

# define SPRITE					2

# define TEXTURES				8
# define TEX_NORTH				0
# define TEX_SOUTH				1
# define TEX_WEST				2
# define TEX_EAST				3
# define TEX_SPRITE				4
# define TEX_EXTRA				5
# define TEX_LB					6
# define TEX_GC					7

# define C_R					6
# define C_NO					0
# define C_SO					1
# define C_WE					2
# define C_EA					3
# define C_S					4
# define C_EXTRA				5
# define C_LB					6
# define C_GC					7
# define C_F 					8
# define C_C					9
# define C_MAP					10

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				bpp;
	int				size_l;
	int				endian;
	int				img_width;
	int				img_height;
}					t_img;

typedef struct		s_ray_sprite
{
	double			relative_dist_x;
	double			relative_dist_y;
	double			inverse_determinant;
	double			trans_x;
	double			trans_y;
	int				screen_x;
	int				height;
	int				width;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	int				tex_x;
	int				tex_y;
	int				sprite_screen_x;
}					t_ray_sprite;

typedef struct		s_player
{
	float			x;
	float			y;
	float			posx;
	float			posy;
	float			width;
	float			height;
	int				turndirection;
	int				walk_forward;
	int				move_lr;
	float			rotationangle;
	float			walkspeed;
	float			turnspeed;
	double			rotationspeed;
	double			move_speed;
	double			rot_speed;
	double			eyelevel;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	char			direction;
}					t_player;

typedef	struct		s_rayy
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				tex_x;
	double			step;
	double			tex_pos;
	int				tex_y;
}					t_rayy;

typedef struct		s_tex
{
	char			*tex_path;
	int				*texture;
	double			width;
	double			height;
}					t_tex;

typedef struct		s_config
{
	int				screenwidth;
	int				screenheight;
	int				rows;
	int				colums;
	double			tile;
	t_tex			tex[TEXTURES];
	int				floor_color;
	int				ceiling_color;
	char			**map;
	double			rotation_speed;
	double			updown_speed;
	double			eyelevel;
	double			fov;
	int				t_num;
	int				istype[C_MAP + 1];
	int				sprite_num;
}					t_config;

typedef struct		s_sprite_y
{
	double			x;
	double			y;
	double			distance;
	int				c_type;
}					t_sprite_y;

typedef struct		s_game
{
	int				**buf;
	double			*z_buf;
	t_config		config;
	void			*mlx;
	void			*win;
	t_img			img;
	t_rayy			rayy;
	t_player		player;
	t_sprite_y		*sprite;
	t_ray_sprite	ray_sprite;
}					t_game;

/*
**calc_raycasting.c calc_sprite.c calc_utils.c
*/
void				calc_raycasting(t_game *g);
void				calc_sprite(t_game *game);
void				set_ray_item(t_game *g, int x);
void				set_sprite(t_game *g);

/*
** draw.c
*/
void				draw(t_game *game);
void				draw_ceil_floor(t_game *game);

/*
** exit.c
*/
int					exit_error(t_game *game, int code, char const *str);
int					exit_error_line(char *line, int code, char const *str);

/*
** free_utils.c
*/
void				free_machine(t_game *game);
void				all_free(t_game *game);
void				free_2stars(char **str);

/*
** get_next_line.c
*/
int					get_next_line(int fd, char **line);

/*
** init.c
*/

void				init_player(t_game *game);
void				init_config(t_game *game);
void				init_mlx_functions(t_game *game);
void				init_buffer(t_game *game);

/*
** keys.c
*/

int					key_press(int key_code, t_game *game);
int					key_release(int key_code, t_game *game);
int					exit_game(t_game *game);

/*
** main.c
*/
int					main_loop(t_game *game);
void				check_argument(t_game *game, int argc, char *option);
void				start_raycasting(t_game *game);

/*
** mapcheck.c
*/

int					mapcheck_02(t_game *game, int i, int j);
int					check_map_validation(t_game *g, t_config c);
int					check_values(t_game *game);

/*
** parse_config.c parse_line.c
*/

int					parse_config\
					(t_game *game, t_config *config, char const *conf_path);
int					parse_line(int ret, t_config *config, int type, char *line);

/*
** parse_str_util.c
*/

int					is_endswith(char const *conf_path, char const *str);
int					digit_check(char *str);
int					check_rgb_range(char **rgb);

/*
** player_move.c
*/
void				player_move(t_game *game, t_player *p);

/*
** screenshot.c
*/

int					screenshot(t_game *game);

/*
** texture.c
*/

void				load_texture(t_game *game);

/*
** utils.c
*/

int					is_upper(int x);
int					is_space(int x);
char				*add_str_back(char *temp, char *line);

/*
** bonus.c
*/
void				play_music(char *str);
void				stop_music(void);
void				show_info(t_game *game);
void				catch_fish(t_game *game, t_player *p);
int					is_okay(char c);

#endif
