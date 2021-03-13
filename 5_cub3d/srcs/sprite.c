#include "cub3d.h"

void   set_sprite(t_game *game)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = -1;
	game->ray.sprite_dist = (t_sprite_dist*)var_malloc(sizeof(t_sprite_dist) * game->info.sprite_num);
	while (++i < game->info.cols)
	{
		j = -1;
		while (++j < game->info.rows[i])
		{
			if (game->info.map[i][j] == '2')
			{
				game->ray.sprite_dist[k].x = 0.5 + j;
				game->ray.sprite_dist[k].y = 0.5 + i;
				game->ray.sprite_dist[k].dist =
					pow(game->ray.sprite_dist[k].x, 2) + pow(game->ray.sprite_dist[k].y, 2);
				k++;
			}
		}
	}
}

void	sprite(t_game *game)
{
	game = 0;
}
