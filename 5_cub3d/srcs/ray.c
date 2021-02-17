#include "cub3d.h"

void	raycasting(t_game *game)
{
	int		x;

	x = -1;
	while (++x < game->resolution[0])
	{
		game->ray.camera_x = 2 * x / (double)game->resolution[0] - 1;
		game->ray.ray_dir_x = game->ray.dir_x + game->ray.plane_x * game->ray.camera_x;
		game->ray.ray_dir_y = game->ray.dir_y + game->ray.plane_y * game->ray.camera_x;
		game->ray.map_x = game->ray.char_pos_x;
		game->ray.map_y = game->ray.char_pos_y;
		game->ray.delta_dist_x = abs(1 / game->ray.ray_dir_x);
		game->ray.delta_dist_y = abs(1 / game->ray.ray_dir_y);
		if (game->ray.ray_dir_x < 0)
		{
			game->ray.step_x = -1;
			game->ray.side_dist_x = (game->ray.char_pos_x - game->ray.map_x) * game->ray.delta_dist_x;
		}
		else
		{
			game->ray.step_x = 1;
			game->ray.side_dist_x = (game->ray.map_x + 1.0 - game->ray.char_pos_x) * game->ray.delta_dist_x;
		}
		if (game->ray.ray_dir_y < 0)
		{
			game->ray.step_y = -1;
			game->ray.side_dist_y = (game->ray.char_pos_y - game->ray.map_y) * game->ray.delta_dist_y;
		}
		else
		{
			game->ray.step_y = 1;
			game->ray.side_dist_y = (game->ray.map_y + 1.0 - game->ray.char_pos_y) * game->ray.delta_dist_y;
		}
	}
}

void	get_dir_ray(t_game *game)
{
	game = 0;
}

void	check_wall(t_game *game)
{
	game = 0;
}

void	distance(t_game *game)
{
	game = 0;
}
