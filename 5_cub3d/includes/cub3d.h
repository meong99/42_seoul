/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:32:08 by mchae             #+#    #+#             */
/*   Updated: 2021/02/23 23:34:55 by mchae            ###   ########.fr       */
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

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17 //Exit program key code
# define KEY_ESC			53
# define CHARACTER_DIRS "SNWE"
# define TRUE 1
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define RESOLUTION 0
# define NORTH 1
# define SOUTH 2
# define WEST 3
# define EAST 4
# define SPRITE 5
# define FLOOR_COLOR 6
# define CEILING_COLOR 7
# define H 10

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		*image_data[5];
}				t_img;

typedef struct	s_ray
{
	double	char_pos_x;
	double	char_pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
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
	int		texture_color;
	int		texture_width;
	int		texture_height;
}				t_ray;
typedef struct	s_game
{
	t_img	img;
	t_ray	ray;

	void	*mlx;
	void	*win;

	char	*map_name;
	int		*rows;
	int		cols;
	char	char_dir;
	int		**map;
	char	**char_map;
	char	*info_map[8];
	int		info_check[8];
	int		resolution[2];
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*sprite_texture;
	int		floor_color[3];
	int		ceiling_color[3];
	int		**pixel_map;
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
void	mwi_init(t_game *game);

/*
**	map.c
*/
void	get_map(t_game *game, const char *filename);
int		check_gnl(t_game *game, char *one_line);
void	map_parsing(int fd, t_game *game);
void	map_mapi(t_game *game, const char *map);
void	find_character(t_game *game);

/*
** map_error.c
*/
void	map_check(t_game *game, int pos_x, int pos_y);
void	character_error(t_game *game, int character);

/*
** info_error.c
*/
void	info_error(t_game *game);
void	element_count_error(t_game *game);
void	screen_size_and_color_error(t_game *game);
int		overlap_error(t_game *game, int type);
void	invalid_char_error(const char *info, int type);

/*
** map_parsing.c
*/
void	parsing_map_info(t_game *game);
void	parsing_color(t_game *game, int type, int *p_color);

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
void	load_xpm_image(t_game *game);
void	draw_image(t_game *game, int *buffer);

/*
**	ray_init.c
*/
void	ray_init(t_game *game);
void	dir_plane_init(t_game *game);
void	dir_check_init(t_game *game);

/*
**	util.c
*/
void	val_free(char **val, int i);
int		*todigit(t_game *game, char *s, int index);
int		count_element(char **element);
void	error_exit(char *massege);

#endif
