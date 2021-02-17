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
	game->win = mlx_new_window(game->mlx, game->resolution[0], game->resolution[1], "cub3d");
	game->img.img = mlx_new_image(game->mlx, game->resolution[0], game->resolution[1]);
}

void	dir_plane_init(t_game *game)
{
	dir_check_init(game);
	if (game->ray.dir_x)
		game->ray.dir_y = 0;
	else
		game->ray.dir_x = 0;
	if (game->ray.plane_x)
		game->ray.plane_y = 0;
	else
		game->ray.plane_x = 0;
}

void	dir_check_init(t_game *game)
{
	if (game->char_dir == 'N')
	{
		game->ray.dir_y = 1;
		game->ray.plane_x = 0.66;
	}
	else if (game->char_dir == 'S')
	{
		game->ray.dir_y = -1;
		game->ray.plane_x = -0.66;
	}
	else if (game->char_dir == 'W')
	{
		game->ray.dir_x = -1;
		game->ray.plane_y = 0.66;
	}
	else
	{
		game->ray.dir_x = 1;
		game->ray.plane_y = -0.66;
	}
}
