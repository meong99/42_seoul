#include "my_mlx.h"

void	draw_rectangle(t_game *game, int x, int y, int color)
{
	int i;
	int j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[(y + i) * WIDTH + x + j] = color;
			j++;
		}
		i++;
	}
}

void	draw_character(t_game *game, int x, int y, int color)
{
	int i;
	int j;
	
	i = -4;
	while (++i < TILE_SIZE + 3)
	{
		j = -4;
		while (++j < TILE_SIZE + 3)
		{
			if ((pow(abs(game->char_mask_y - i), 2) + pow(abs(game->char_mask_x - j), 2)) <= 3 * 3)
			{
				if (game->img.data[((y * TILE_SIZE) + i) * WIDTH + (x * TILE_SIZE) + j] != 0xFFFFFF)
					game->img.data[((y * TILE_SIZE) + i) * WIDTH + (x * TILE_SIZE) + j] = color;
			}
		}
	}
}

void	draw_rectangles(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			if (game->map[i][j] == 1)
				draw_rectangle(game, j, i, 0xFFFFFF);
			else if (game->map[i][j] == 0)
				draw_rectangle(game, j, i, 0x000000);
			else if (game->map[i][j] == CHARACTER)
			{
				game->char_x = j;
				game->char_y = i;
				game->map[i][j] = 0;
			}
			j++;
		}
		i++;
	}
	draw_character(game, game->char_x, game->char_y, 0xFF00FF);
}
