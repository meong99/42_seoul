/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaemyeongseog <chaemyeongseog@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:32:08 by mchae             #+#    #+#             */
/*   Updated: 2021/03/22 01:13:24 by chaemyeongs      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "key_macos.h"
# include "get_next_line.h"
# include "libft.h"
# include <time.h>
# include <unistd.h>

# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define KEY_ESC 53
# define CHARACTER_DIRS "SNWE"
# define TRUE 1

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define SPRITE 4
# define RESOLUTION 5
# define FLOOR_COLOR 6
# define CEILING_COLOR 7
# define FLOOR 0
# define CEILING 1
# define V_DIV 2
# define U_DIV 2
# define V_MOVE 0.0
typedef struct	s_tex_info
{
	void			*img;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				texture_color;
	int				texture_width;
	int				texture_height;
	char			*texture_path;
}				t_tex_info;

typedef struct	s_img
{
	void			*img;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				texture_dir;
	int				padding;
}				t_img;

typedef struct	s_player
{
	int				forward;
	int				back;
	int				left;
	int				right;
	int				left_turn;
	int				right_turn;
	double			char_pos_x;
	double			char_pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			turn_speed;
	double			move_speed;
	char			char_dir;
}				t_player;

typedef struct	s_info
{
	int				color[2];
	int				*rows;
	int				cols;
	char			**map;
	char			*info_map[8];
	int				info_check[8];
	void			*mlx;
	void			*win;
	int				screen_width;
	int				max_screen_width;
	int				screen_height;
	int				max_screen_height;
	int				sprite_num;
}				t_info;

typedef struct	s_sprite
{
	double			sprite_x;
	double			sprite_y;
	int				texture;
	double			inverse_determinant;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	int				sprite_draw_start_x;
	int				sprite_draw_start_y;
	int				sprite_draw_end_x;
	int				sprite_draw_end_y;
	int				sprite_tex_x;
	int				sprite_tex_y;
	int				d;
	int				u_div;
	int				v_div;
	int				v_move_screen;
	double			v_move;
}				t_sprite;

typedef struct	s_sprite_dist
{
	double			x;
	double			y;
	int				dist;
}				t_sprite_dist;

typedef struct	s_ray
{
	int				**buf;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
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
	int				wall_color;
	double			wall_x;
	double			step;
	double			tex_pos;
	int				tex_x;
	int				tex_y;
	double			*sprite_buf;
}				t_ray;

typedef struct	s_game
{
	t_sprite_dist	*sprite_dist;
	t_sprite		sprite;
	t_img			img;
	t_tex_info		tex_info[5];
	t_ray			ray;
	t_info			info;
	t_player		player;
}				t_game;

/*
** bonus.c
*/
void			ft_hud(t_game *game);

/*
**  image.c
*/
void			load_xpm_image(t_tex_info *tex_info, t_info *info);
void			draw_image(t_info *info, t_img *img, t_ray *ray);
void			draw_fl_cei(t_info *info, t_ray *ray);

/*
** info_error.c
*/
void			element_count_error(t_info *info);
void			screen_size_error(t_info *info);
int				overlap_error(t_info *info, int type);
void			invalid_char_error(const char *info, int type);

/*
**	init.c
*/
void			game_init(t_game *game, char *filename);
void			mlx_win_img_init(t_info *info, t_img *img);
void			player_init(t_player *player);
void			buf_init(t_info *info, t_ray *ray);

/*
** key_set.c
*/
int				key_press_set(int key_code, t_game *game);
int				key_release_set(int key_code, t_player *player);

/*
**	main.c
*/
int				win_close(t_game *game);
int				main_loop(t_game *game);
void			start_loop(t_game *game);

/*
** malloc_free.c
*/
void			var_free(void *val, int pointer_num, int index, int is_char);
void			*var_malloc(size_t size);

/*
** map_error.c
*/
void			map_check(t_info *info, int pos_x, int pos_y);
void			player_error(t_info *info, t_player *player, int character);
int				check_gnl(t_info *info, char *one_line);

/*
** parsing_info.c
*/
void			parsing_map_info(t_info *info, t_tex_info *tex_info);
void			parsing_color(t_info *info, int type);
void			get_color(int *temp_color, int *color);

/*
**	parsing_map.c
*/
void			map_parsing(t_game *game, const char *filename);
void			get_map(int fd, t_info *info);
void			split_map_get_rows(t_info *info, const char *map);
void			find_player(t_info *info, t_player *player);
void			reset_map(t_info *info);

/*
** player.c
*/
void			player_move(t_game *game);
void			player_move_back_forward(t_info *info, t_player *player);
void			player_move_left_right(t_info *info, t_player *player);
void			player_camera_turn(t_player *player, double angle);

/*
** ray_util.c
*/
void			raycasting_set(t_game *game, int x);
void			dir_set(t_game *game);
void			hit_scan(t_game *game);
void			perp_dist_and_texture_num(t_game *game);
void			draw_set(t_game *game);

/*
**	raycasting.c
*/
void			raycasting(t_game *game);
void			load_texture(t_game *game);

/*
** save.c
*/
void			save_bmp(t_game *game);

/*
** sort.c
*/
void			quick_sort(void *value, int left_index, int right_index);

/*
** sprite_casting.c
*/
void			sprite_set(t_game *game, int i);
void			sprite_draw_set(t_game *game);
void			draw_sprite(t_game *game, int stripe);

/*
** sprite.c
*/
void			sprite_cast(t_game *game);
void			set_sprite_dist(t_game *game);

/*
** texture.c
*/
void			texture_wall_tex_x(t_game *game, int texture_dir);
void			texture_ctrl(t_game *game, int x);
void			draw_texture(t_game *game, int texture_dir, int y, int x);
void			texture_step_pos_set(t_game *game, int texture_dir);

/*
**	util.c
*/
int				count_element(char **element);
void			error_exit(char *massege);
double			get_radian(int angle);
int				color_div(int color, double perp_wall_dist);

#endif
