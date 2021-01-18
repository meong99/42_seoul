#include "cub3d.h"

void	ray_init(int x, t_game *game)
{
		game->camera_x = 2 * x / (double)SCREENWIDTH - 1;
		game->ray_dir_x = game->dir_x + game->plane_x * game->camera_x;
		game->ray_dir_y = game->dir_y + game->plane_y * game->camera_x;
		game->map_x = (int)game->pos_x;
		game->map_y = (int)game->pos_y;
		game->delta_dist_x = fabs(1 / game->ray_dir_x);
		game->delta_dist_y = fabs(1 / game->ray_dir_y);
		game->hit = 0;
}

void	get_side_dist(t_game *game)
{
	if (game->ray_dir_x < 0)
      {
        game->step_x = -1;
        game->side_dist_x = (game->pos_x - game->map_x) * game->delta_dist_x;
      }
      else
      {
        game->step_x = 1;
        game->side_dist_x = (game->map_x + 1.0 - game->pos_x) * game->delta_dist_x;
      }
      if (game->ray_dir_y < 0)
      {
        game->step_y = -1;
        game->side_dist_y = (game->pos_y - game->map_y) * game->delta_dist_y;
      }
      else
      {
        game->step_y = 1;
        game->side_dist_y = (game->map_y + 1.0 - game->pos_y) * game->delta_dist_y;
      }
}

void	dda(t_game *game)
{
	while (game->hit == 0)
      {
        if (game->side_dist_x < game->side_dist_y)
        {
          game->side_dist_x += game->delta_dist_x;
          game->map_x += game->step_x;
          game->side = 0;
        }
        else
        {
          game->side_dist_y += game->delta_dist_y;
          game->map_y += game->step_y;
          game->side = 1;
        }
        if (game->map[game->map_x][game->map_y] > 0)
		{
			if (game->side == 0)
				game->perp_wall_dist = (game->map_x - game->pos_x + (1 - game->step_x) / 2) / game->ray_dir_x;
			else
				game->perp_wall_dist = (game->map_y - game->pos_y + (1 - game->step_y) / 2) / game->ray_dir_y;
			break ;
		}
      } 
}
