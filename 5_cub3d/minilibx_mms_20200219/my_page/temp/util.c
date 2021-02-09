#include "my_mlx.h"

void	move_x(t_game *game, int dir)
{
	if (game->char_mask_x + dir >= 0 && game->char_mask_x + dir < TILE_SIZE)
	{
		game->char_mask_x += dir;
		game->move = 1;
	}
	else
	{
		if (game->map[game->char_y][game->char_x + dir] != 1)
		{
			game->char_x += dir;
			if (dir > 0)
				game->char_mask_x = 0;
			else
				game->char_mask_x = TILE_SIZE - 1;
			game->move = 1;
		}
	}
}

void	move_y(t_game *game, int dir)
{
	if (game->char_mask_y + dir >= 0 && game->char_mask_y + dir < TILE_SIZE)
	{
		game->char_mask_y += dir;
		game->move = 1;
	}
	else
	{
		if (game->map[game->char_y + dir][game->char_x] != 1)
		{
			game->char_y += dir;
			if (dir > 0)
				game->char_mask_y = 0;
			else
				game->char_mask_y = TILE_SIZE - 1;
			game->move = 1;
		}
	}
}