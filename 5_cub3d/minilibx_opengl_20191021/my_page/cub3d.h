#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
#include "key_macos.h"
# include "../../get_next_line/get_next_line.h"
# include "../../libft/libft.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17 //Exit program key code
# define KEY_ESC			53

# define RESOLUTION 0
# define NORTH 1
# define SOUTH 2
# define WEST 3
# define EAST 4
# define SPRITE 5
# define FLOOR_COLOR 6
# define CEILING_COLOR 7

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
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
}				t_ray;
typedef struct	s_game
{
	t_img	img;
	t_ray	ray;

	void	*mlx;
	void	*win;

	int		**pixel_map;
	int		**map;
	char	*info_map[8];
}				t_game;

/*
**	main.c
*/
int		event_key(int key_code, t_game *game);
int		win_close();
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
void	ray_init(t_game *game);
void	mwi_init(t_game *game);

/*
**	map.c
*/
void	get_map(t_game *game, const char *filename);
int		check_gnl(char *one_line);
int		map_parsing(int fd, t_game *game, char **map);
void	map_mapi(t_game *game, char *map);
void	get_mapmask(t_game *game);
/*
** error.c
*/
int		map_check(t_game *game, int pos_x, int pos_y);

/*
**	ray.c
*/
void	raycasting(t_game *game);
void	get_dir_ray(t_game *game);
void	check_wall(t_game *game);
void	distance(t_game *game);

/*
**	util.c
*/
void	move_char(t_game *game);
void	str_free(char **val);
int		*todigit(char *s);

#endif