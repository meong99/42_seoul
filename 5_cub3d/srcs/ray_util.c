#include "cub3d.h"

void	play_set(t_game *game, int x)
{
	game->ray.hit = 0;
	game->ray.camera_x = 2 * x / (double)game->screen_width - 1;
	game->ray.ray_dir_x = game->ray.dir_x + game->ray.plane_x * game->ray.camera_x;
	game->ray.ray_dir_y = game->ray.dir_y + game->ray.plane_y * game->ray.camera_x;
	game->ray.map_x = game->ray.char_pos_x;
	game->ray.map_y = game->ray.char_pos_y;
	game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
	game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
}

void	dir_set(t_game *game)
{
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

void	hit_scan(t_game *game)
{
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
}

void	draw_set(t_game *game)
{
	if (game->ray.side == 0)
	{
		game->ray.perp_wall_dist = (game->ray.map_x - game->ray.char_pos_x +(1 - game->ray.step_x) / 2) / game->ray.ray_dir_x;
		if (game->ray.step_x > 0)
			game->img.dir_texture = NORTH;
		else
			game->img.dir_texture = SOUTH;
	}
	else
	{
		game->ray.perp_wall_dist = (game->ray.map_y - game->ray.char_pos_y +(1 - game->ray.step_y) / 2) / game->ray.ray_dir_y;
		if (game->ray.step_y > 0)
			game->img.dir_texture = EAST;
		else
			game->img.dir_texture = WEST;
	}
	game->ray.line_height = (int)(game->screen_height / game->ray.perp_wall_dist);
	game->ray.draw_start = -game->ray.line_height / 2 + game->screen_height / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.line_height / 2 + game->screen_height / 2;
	if (game->ray.draw_end >= game->screen_height)
		game->ray.draw_end = game->screen_height - 1;
	if (game->ray.side == 0)
		game->ray.wall_x = game->ray.char_pos_y + game->ray.perp_wall_dist * game->ray.ray_dir_y;
	else
		game->ray.wall_x =  game->ray.char_pos_x+ game->ray.perp_wall_dist * game->ray.dir_x;
}

void	texture_set(t_game *game, int x)
{
	int		y;
	int		color;

	game->ray.wall_x -= floor((game->ray.wall_x));
	game->ray.tex_x = (int)(game->ray.wall_x * (double)game->tex[game->img.dir_texture].texture_width);
	if (game->ray.side == 0 && game->ray.ray_dir_x > 0)
		game->ray.tex_x = game->tex[game->img.dir_texture].texture_width - game->ray.tex_x - 1;
	if (game->ray.side == 1 && game->ray.ray_dir_y < 0)
		game->ray.tex_x = game->tex[game->img.dir_texture].texture_width - game->ray.tex_x - 1;
	game->ray.step = 1.0 * game->tex[game->img.dir_texture].texture_height / game->ray.line_height;
	game->ray.tex_pos = (game->ray.draw_start - game->screen_height / 2 + game->ray.line_height / 2) * game->ray.step;
	y = game->ray.draw_start - 1;
	while (++y < game->ray.draw_end)
	{
		game->ray.tex_y = (int)game->ray.tex_pos & (game->tex[game->img.dir_texture].texture_height - 1);
		game->ray.tex_pos += game->ray.step;
		color = game->tex[game->img.dir_texture].data[game->tex[game->img.dir_texture].size_l / (game->tex[game->img.dir_texture].bpp / 8) * game->ray.tex_y + game->ray.tex_x];
		game->ray.buf[y][x] = color;
	}
}
