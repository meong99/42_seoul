#include "cub3d.h"

void	character_error(t_game *game, int character)
{
	if (character != 1)
		error_exit();
	game->char_dir = game->char_map[game->ray.map_y][game->ray.map_x];
	game->map[game->ray.map_y][game->ray.map_x] = 0;
}

void	map_check(t_game *game, int pos_x, int pos_y)
{
	if (pos_y == -1 || pos_y >= game->cols ||
			pos_x == -1 || game->char_map[pos_y][pos_x] == '\0')
		error_exit();
	if (game->map[pos_y][pos_x] == 1 || game->map[pos_y][pos_x] == 'X' ||
		game->map[pos_y][pos_x] == 'S')
		return ;
	else if (game->map[pos_y][pos_x] != 0 && game->map[pos_y][pos_x] != 2)
		error_exit();
	if (game->map[pos_y][pos_x] == 2)
	{
		game->map[pos_y][pos_x] = 'S';
		game->char_map[pos_y][pos_x] = 'S';
	}
	else
	{
		game->map[pos_y][pos_x] = 'X';
		game->char_map[pos_y][pos_x] = 'X';
	}
	map_check(game, pos_x + 1, pos_y);
	map_check(game, pos_x - 1, pos_y);
	map_check(game, pos_x, pos_y - 1);
	map_check(game, pos_x, pos_y + 1);
}
