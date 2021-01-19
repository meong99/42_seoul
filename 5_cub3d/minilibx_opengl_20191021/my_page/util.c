#include "my_mlx.h"

void	redraw(t_game *game)
{
	if (game->move)
	{
		draw_character(game, game->char_x, game->char_y, 0xFF00FF);
		game->move = 0;
	}
}

void	move_x(t_game *game, int dir)
{
	if (game->char_mask_x + dir >= 0 && game->char_mask_x + dir < TILE_SIZE)
	{
		draw_character(game, game->char_x, game->char_y, 0x000000);
		game->char_mask_x += dir;
		game->move = 1;
	}
	else
	{
		if (game->map[game->char_y][game->char_x + dir] != 1)
		{
			draw_character(game, game->char_x, game->char_y, 0x000000);
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
		draw_character(game, game->char_x, game->char_y, 0x000000);
		game->char_mask_y += dir;
		game->move = 1;
	}
	else
	{
		if (game->map[game->char_y + dir][game->char_x] != 1)
		{
			draw_character(game, game->char_x, game->char_y, 0x000000);
			game->char_y += dir;
			if (dir > 0)
				game->char_mask_y = 0;
			else
				game->char_mask_y = TILE_SIZE - 1;
			game->move = 1;
		}
	}
}