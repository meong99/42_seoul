#include "cub3d.h"

void	ray_init(t_game *game)
{
	dir_plane_init(game);
	raycasting(game);
}
