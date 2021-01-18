#ifndef CUB3D_H
# define CUB3D_H

#include "../mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "key_macos.h"
# include "../../get_next_line/get_next_line.h"
# include "../../libft/libft.h"

#define ERROR -1
#define RESOLUTION 0
#define NORTH 1
#define SOUTH 2
#define WEST 3
#define EAST 4
#define SPRITE 5
#define FLOOR_COLOR 6
#define CEILLING_COLOR 7
#define MAP 8

#define WALL_SIZE 10

#define EVENT_KEY_PRESS		2
#define EVENT_KEY_EXIT		17 //Exit program key code

#define SCREENWIDTH 640
#define SCREENHEIGHT 480

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		**map;
	char	**map_info;
	int		map_rows;
	int		*map_cols;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	time;
	double	oldtime;
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
}				t_game;

/*
** get_map
*/
char	**get_map(t_game *game);

/*
** init
*/
void	map_init(t_game *game);
void	window_init(t_game *game);
void	game_init(t_game *game);
void	img_init(t_game *game);

/*
** util
*/
void	atoi_mapi(t_game *game);
void	get_pos(t_game *game);
void	put_error(const char *str);

/*
**key_event
*/
int		deal_key(int key_code, t_game *game);
int 	win_close(t_game *game);

/*
**raycast
*/
void	ray_init(int x, t_game *game);
void	get_side_dist(t_game *game);
void	dda(t_game *game);
/*
**draw
*/
void	draw_init(int x, t_game *game);
void	draw_wall(t_game *game);
void	draw_rectangles(t_game *game);
void	draw_rectangle(t_game *game, int x, int y);

#endif