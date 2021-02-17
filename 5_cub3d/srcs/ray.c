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
		while (!game->ray.hit)
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
			if (game->map[game->ray.map_y][game->ray.map_x] > 0)
					game->ray.hit = 1;
		}
		if (game->ray.side == 0)
			game->ray.perp_wall_dist = (game->ray.map_x - game->ray.char_pos_x +(1 - game->ray.step_x) / 2) / game->ray.ray_dir_x;
		else
			game->ray.perp_wall_dist = (game->ray.map_y - game->ray.char_pos_y +(1 - game->ray.step_y) / 2) / game->ray.ray_dir_y;
		game->ray.line_height = (int)(game->resolution[1] / game->ray.perp_wall_dist);
		game->ray.draw_start = -game->ray.line_height / 2 + game->resolution[1] / 2;
		if (game->ray.draw_start < 0)
			game->ray.draw_start = 0;
		game->ray.draw_end = game->ray.line_height / 2 + game->resolution[1] / 2;
		if (game->ray.draw_end >= game->resolution[1])
			game->ray.draw_end = game->resolution[1] - 1;
		if (game->map[game->ray.map_y][game->ray.map_x] == 1)
			game->ray.wall_color = 0x66FFFF;
		else
			game->ray.wall_color = 0x00FF33;
		if (game->ray.side)
			game->ray.wall_color /= 2;
		ver_line(game, x, game->ray.draw_start, game->ray.draw_end, game->ray.wall_color);
	}
}

void	ver_line(t_game *game, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(game->mlx, game->win, x, y, color);
		y++;
	}
}

void	check_wall(t_game *game)
{
	game = 0;
}

void	distance(t_game *game)
{
	game = 0;
}
