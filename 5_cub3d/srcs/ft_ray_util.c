/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:40:17 by mchae             #+#    #+#             */
/*   Updated: 2021/03/14 18:06:42 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting_set(t_game *game, int x)
{
	game->ray.hit = 0;
	game->ray.camera_x = 2 * x / (double)game->info.screen_width - 1;
	game->ray.ray_dir_x =\
	game->player.dir_x + game->player.plane_x * game->ray.camera_x;
	game->ray.ray_dir_y =\
	game->player.dir_y + game->player.plane_y * game->ray.camera_x;
	game->ray.map_x = game->player.char_pos_x;
	game->ray.map_y = game->player.char_pos_y;
	game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
	game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
	game->ray.step_x = 0;
	game->ray.step_y = 0;
}

void	dir_set(t_game *game)
{
	if (game->ray.ray_dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x =\
		(game->player.char_pos_x - game->ray.map_x) * game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (game->ray.map_x + 1.0 -\
		game->player.char_pos_x) * game->ray.delta_dist_x;
	}
	if (game->ray.ray_dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->player.char_pos_y -\
		game->ray.map_y) * game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (game->ray.map_y + 1.0 -\
		game->player.char_pos_y) * game->ray.delta_dist_y;
	}
}

void	hit_scan(t_game *game)
{
	while (!game->ray.hit)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->info.map[game->ray.map_y][game->ray.map_x] == '1')
			game->ray.hit = 1;
	}
}

void	perp_dist_and_texture_num(t_game *game)
{
	if (game->ray.side == 0)
	{
		game->ray.perp_wall_dist =\
		(game->ray.map_x - game->player.char_pos_x +\
		(1 - game->ray.step_x) / 2) / game->ray.ray_dir_x;
		if (game->ray.step_x > 0)
			game->img.texture_dir = EAST;
		else
			game->img.texture_dir = WEST;
	}
	else
	{
		game->ray.perp_wall_dist = (game->ray.map_y -\
		game->player.char_pos_y + (1 - game->ray.step_y) / 2)\
		/ game->ray.ray_dir_y;
		if (game->ray.step_y > 0)
			game->img.texture_dir = NORTH;
		else
			game->img.texture_dir = SOUTH;
	}
}

void	draw_set(t_game *game)
{
	perp_dist_and_texture_num(game);
	game->ray.line_height =\
	(int)(game->info.screen_height / game->ray.perp_wall_dist);
	game->ray.draw_start =\
	-game->ray.line_height / 2 + game->info.screen_height / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end =\
	game->ray.line_height / 2 + game->info.screen_height / 2;
	if (game->ray.draw_end >= game->info.screen_height)
		game->ray.draw_end = game->info.screen_height - 1;
}
