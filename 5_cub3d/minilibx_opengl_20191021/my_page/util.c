#include "my_mlx.h"

void	redraw(t_game *game)
{

}

void	move_x(t_game *game, int dir)
{
	if (game->char_mask_x + dir > 0 && game->char_mask_x + dir < TILE_SIZE - 1)
		game->char_mask_x += dir;
	else
	{
		if (game->char_x + dir != 1)
		{
			game->char_x += dir;
			if (dir > 0)
				game->char_mask_x = 0;
			else
				game->char_mask_x = TILE_SIZE - 1;
		}
	}
}

void	move_y(t_game *game, int dir)
{
	if (game->char_mask_y + dir > 0 && game->char_mask_y + dir < TILE_SIZE - 1)
		game->char_mask_y += dir;
	else
	{
		if (game->char_y + dir != 1)
		{
			game->char_y += dir;
			if (dir > 0)
				game->char_mask_y = 0;
			else
				game->char_mask_y = TILE_SIZE - 1;
		}
	}
}