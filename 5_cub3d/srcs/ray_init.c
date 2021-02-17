#include "cub3d.h"

void	ray_init(t_game *game)
{
	game->ray.hit = 0;
	dir_plane_init(game);
	raycasting(game);
}
