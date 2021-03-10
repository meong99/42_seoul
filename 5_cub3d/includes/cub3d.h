/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaemyeongseog <chaemyeongseog@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:32:08 by mchae             #+#    #+#             */
/*   Updated: 2021/03/10 18:21:27 by chaemyeongs      ###   ########.fr       */
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

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17 //Exit program key code
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
# define TYPE_CHAR 0
# define TYPE_INT 1
# define TYPE_DOUBLE 2

typedef struct	s_tex_info
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		texture_color;
	int		texture_width;
	int		texture_height;
	char	*texture_path;
}				t_tex_info;

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		dir_texture;
}				t_img;

typedef struct	s_player
{
	double	char_pos_x;
	double	char_pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	turn_speed;
	double	move_speed;
	char	char_dir;
}				t_player;

typedef struct	s_info
{
	int		color[2];
	char	*map_name;
	int		*rows;
	int		cols;
	char	**map;
	char	*info_map[8];
	int		info_check[8];
	void	*mlx;
	void	*win;
	int		screen_width;
	int		screen_height;
}				t_info;

typedef struct	s_ray
{
	int		**buf;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		wall_color;
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	double	*sprite_buf;
}				t_ray;

typedef struct	s_game
{
	t_img		img;
	t_tex_info	tex_info[5];
	t_ray		ray;
	t_info		info;
	t_player	player;
}				t_game;

/*
**	main.c
*/
int		event_key(int key_code, t_game *game);
int		win_close(void);
int		main_loop(t_game *game);

/*
**	2d_image.c
*/
void	draw_2d_map(t_game *game);
void	draw_2d_char(t_game *game);
void	draw_2d_ray(t_game *game);

/*
**	init.c
*/
void	game_init(t_game *game, char *filename);
void	mwi_init(t_info *info, t_img *img);

/*
**	map.c
*/
void	get_map(t_info *info, t_player *player, t_tex_info *tex_info, const char *filename);
int		check_gnl(t_info *info, char *one_line);
void	map_parsing(int fd, t_info *info);
void	map_mapi(t_info *info, const char *map);
void	find_character(t_info *info, t_player *player);

/*
** map_error.c
*/
void	map_check(t_info *info, int pos_x, int pos_y);
void	character_error(t_info *info, t_player *player, int character);
void	map_init_zero(t_info *info);

/*
** info_error.c
*/
void	info_error(t_info *info, t_tex_info *tex_info);
void	element_count_error(t_info *info, t_tex_info *tex_info);
void	screen_size_error(t_info *info);
int		overlap_error(t_info *info, int type);
void	invalid_char_error(const char *info, int type);

/*
** map_parsing.c
*/
void	parsing_map_info(t_info *info, t_tex_info *tex_info);
void	parsing_color(t_info *info, int type);
void	get_color(int *temp_color, int *color);

/*
**	ray.c
*/
void	raycasting(t_game *game);
void	ver_line(t_game *game, int x, int y1, int y2, int color);
void	check_wall(t_game *game);
void	distance(t_game *game);

/*
**  image.c
*/
void	load_xpm_image(t_tex_info *tex_info, t_info *info);
void	draw_image(t_info *info, t_img *img, t_ray *ray);
void	draw_fl_cei(t_info *info, t_ray *ray);

/*
**	ray_init.c
*/
void	ray_init(t_game *game);
void	buf_init(t_info *info, t_ray *ray);

/*
** ray_util.c
*/
void	play_set(t_game *game, int x);
void	dir_set(t_game *game);
void	hit_scan(t_game *game);
void	draw_set(t_game *game);
void	texture_set(t_game *game, int x);

/*
**	util.c
*/
int		count_element(char **element);
void	error_exit(char *massege);
double	get_radian(int angle);

/*
** malloc_free.c
*/
void	var_free(void *val, int pointer_num, int index, int type);
void	*var_malloc(size_t size);
/*
** player.c
*/
void	player_dir_init(t_player *player);
void	player_set_dir(t_player *player, double angle);

/*
** player_move.c
*/
void	player_event_key(t_game *game, int key_code);
void	player_move(t_info *info, t_player *player, int key_code);
void	player_cam(t_player *player, int key_code);

#endif
