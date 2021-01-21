#include "my_mlx.h"

void	ray_init(t_game *game)
{
	game->ray.char_pos_x = (double)((game->char_x + 1) * game->char_mask_x);
	game->ray.char_pos_y = (double)((game->char_y + 1) * game->char_mask_y);
	game->ray.dir_x = -1;
	game->ray.dir_y = 0;
	game->ray.plane_x = 0;
	game->ray.plane_y = 0.66;
	game->ray.hit = 0;
	game->ray.map_x = (int)game->ray.char_pos_x;
	game->ray.map_y = (int)game->ray.char_pos_y;
}

void	raycast(t_game *game)
{
	int		x;

	x = -1;
	ray_init(game);
	while (++x < WIDTH)
	{
		game->ray.camera_x = 2 * x / (double)WIDTH - 1;
		game->ray.ray_dir_x = game->ray.dir_x + game->ray.plane_x * game->ray.camera_x;
		game->ray.ray_dir_y = game->ray.dir_y + game->ray.plane_y * game->ray.camera_x;
		game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
		game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
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
		while (game->ray.hit == 0)
		{
			if (game->ray.side_dist_x < game->ray.side_dist_y)
			{
				game->ray.side_dist_x += game->ray.delta_dist_x;
				game->ray.map_x += game->ray.step_x;
				game->ray.side = 0;
			}
			else
			{
				game->ray.side_dist_y += game->ray.delta_dist_y;
				game->ray.map_y += game->ray.step_y;
				game->ray.side = 1;
			}
			if (game->img.data[(game->ray.map_y + game->char_mask_y) * WIDTH + (game->ray.map_x + game->char_mask_x)] == 0xFFFFFF)
				game->ray.hit = 1;
			else
				game->img.data[(game->ray.map_y + game->char_mask_y) * WIDTH + (game->ray.map_x + game->char_mask_x)] = 0x00FF00;
		}
	}
}