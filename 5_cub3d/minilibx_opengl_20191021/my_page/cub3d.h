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

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;

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
}				t_game;

/*
**	main.c
*/
int		event_key(int key_code, t_game *game);
int		win_close();
int		main_loop(t_game *game);

// /*
// **	2d_image.c
// */
// void	draw_2d_map(t_game *game);
// void	draw_2d_char(t_game *game);
// void	draw_2d_ray(t_game *game);

/*
**	init.c
*/
void	game_init(t_game *game, char *filename);
// void	ray_init(t_game *game);
void	mwi_init(t_game *game);

// /*
// **	map.c
// */
// void	get_map(t_game *game, char *filename);
// void	map_mapi(t_game *game);
// void	get_mapmask(t_game *game);

// /*
// **	ray.c
// */
// void	raycasting(t_game *game);
// void	get_dir_ray(t_game *game);
// void	check_wall(t_game *game);
// void	distance(t_game *game);

// /*
// **	util.c
// */
// void	mvoe_char(t_game *game);

#endif