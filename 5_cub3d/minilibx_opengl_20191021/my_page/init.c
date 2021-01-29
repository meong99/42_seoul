#include "cub3d.h"

void	game_init(t_game *game, char *filename)
{
	get_map(game, filename);
}

void	mwi_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 500, 500, "asd");
}

void	ray_init(t_game *game)
{
	game = 0;
}