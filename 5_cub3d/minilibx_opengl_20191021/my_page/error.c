#include "cub3d.h"

void	map_check(t_game *game, int pos_x, int pos_y)
{
	int	result;

	if (pos_y = -1 || pos_y > game->cols ||
			pos_x == -1 || game->char_map[pos_y][pos_x] == '\0')
		exit(-1);
	if (game->map[pos_y][pos_x] == 1 || game->map[pos_y][pos_x] == 'X')
		return ;
	game->map[pos_y][pos_x] = 'X';
	map_check(game, pos_x + 1, pos_y - 1);
	map_check(game, pos_x, pos_y);
	map_check(game, pos_x - 1, pos_y);
	map_check(game, pos_x, pos_y + 1);
}