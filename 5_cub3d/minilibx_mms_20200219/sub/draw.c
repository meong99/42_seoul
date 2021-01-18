#include "cub3d.h"

void	verline(t_game *info, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(info->mlx, info->win, x, y, color);
		y++;
	}
}

void	draw_init(int x, t_game *game)
{
	game->line_height = (int)(WALL_SIZE / game->perp_wall_dist);
	game->draw_start = -game->line_height / 2 + WALL_SIZE / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + WALL_SIZE / 2;
	if (game->draw_end >= WALL_SIZE)
		game->draw_end = WALL_SIZE - 1;
	verline(game, x, game->draw_start, game->draw_end, 0xFFF333);
}

void	draw_wall(t_game *game)
{
	img_init(game);
	// draw_rectangles(game);
}
