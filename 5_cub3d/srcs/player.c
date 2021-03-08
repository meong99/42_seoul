#include "cub3d.h"


void	player_dir_init(t_game *game)
{
	int		angle;

	game->ray.dir_x = 1.0;
	game->ray.dir_y = 0.0;
	game->ray.plane_x = 0.0;
	game->ray.plane_y = -0.66;
	if (game->char_dir == 'E')
		angle = 0;
	else if (game->char_dir == 'S')
		angle = 90;
	else if (game->char_dir == 'W')
		angle = 180;
	else
		angle = 270;
	player_set_dir(game, get_radian(angle));
}

void	player_set_dir(t_game *game, double radian)
{
	int		temp;

	temp = game->ray.dir_x;
	game->ray.dir_x = game->ray.dir_x * cos(radian) - game->ray.dir_y * sin(radian);
	game->ray.dir_y = temp * sin(radian) + game->ray.dir_y * cos(radian);
	temp = game->ray.plane_x;
	game->ray.plane_x = game->ray.plane_x * cos(radian) - game->ray.plane_y * sin(radian);
	game->ray.plane_y = temp * sin(radian) + game->ray.plane_y * cos(radian);
}

