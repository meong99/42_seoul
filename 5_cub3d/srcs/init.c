#include "cub3d.h"

void	game_init(t_game *game, char *filename)
{
	int i;

	i = -1;
	game->cols = 0;
	while (++i < 8)
		game->info_check[i] = -1;
	get_map(game, filename);
}

void	mwi_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 500, 500, "cub3d");
}

void	ray_init(t_game *game)
{
	game = 0;
}