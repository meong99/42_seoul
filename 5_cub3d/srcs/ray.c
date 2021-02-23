/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:53 by mchae             #+#    #+#             */
/*   Updated: 2021/02/23 23:18:30 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_game *game)
{
	int		x;
	int		y;
	int		buffer[game->resolution[0]][game->resolution[1]];

	x = -1;
	while (++x < game->resolution[0])
	{
		game->ray.hit = 0;
		game->ray.camera_x = 2 * x / (double)game->resolution[0] - 1;
		game->ray.ray_dir_x = game->ray.dir_x + game->ray.plane_x * game->ray.camera_x;
		game->ray.ray_dir_y = game->ray.dir_y + game->ray.plane_y * game->ray.camera_x;
		game->ray.map_x = game->ray.char_pos_x;
		game->ray.map_y = game->ray.char_pos_y;
		game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
		game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
		if (game->ray.ray_dir_x < 0)
		{
			game->ray.step_x = -1;
			game->ray.side_dist_x = (game->ray.char_pos_x - game->ray.map_x) * game->ray.delta_dist_x;
		}
		else
		{
			game->ray.step_x = 1;
			game->ray.side_dist_x = (game->ray.map_x + 1.0 - game->ray.char_pos_x) * game->ray.delta_dist_x;
		}
		if (game->ray.ray_dir_y < 0)
		{
			game->ray.step_y = -1;
			game->ray.side_dist_y = (game->ray.char_pos_y - game->ray.map_y) * game->ray.delta_dist_y;
		}
		else
		{
			game->ray.step_y = 1;
			game->ray.side_dist_y = (game->ray.map_y + 1.0 - game->ray.char_pos_y) * game->ray.delta_dist_y;
		}
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
			if (game->map[game->ray.map_y][game->ray.map_x] > 0)
					game->ray.hit = 1;
		}
		if (game->ray.side == 0)
			game->ray.perp_wall_dist = (game->ray.map_x - game->ray.char_pos_x +(1 - game->ray.step_x) / 2) / game->ray.ray_dir_x;
		else
			game->ray.perp_wall_dist = (game->ray.map_y - game->ray.char_pos_y +(1 - game->ray.step_y) / 2) / game->ray.ray_dir_y;
		game->ray.line_height = (int)(game->resolution[1] / game->ray.perp_wall_dist);
		game->ray.draw_start = -game->ray.line_height / 2 + game->resolution[1] / 2;
		if (game->ray.draw_start < 0)
			game->ray.draw_start = 0;
		game->ray.draw_end = game->ray.line_height / 2 + game->resolution[1] / 2;
		if (game->ray.draw_end >= game->resolution[1])
			game->ray.draw_end = game->resolution[1] - 1;
		if (game->ray.side == 0) game->ray.wall_x = game->ray.char_pos_y + game->ray.perp_wall_dist * game->ray.ray_dir_y;
		else           game->ray.wall_x =  game->ray.char_pos_x+ game->ray.perp_wall_dist * game->ray.dir_x;
		game->ray.wall_x -= floor((game->ray.wall_x));

		game->ray.tex_x = (int)(game->ray.wall_x * (double)TEX_WIDTH);
		if (game->ray.side == 0 && game->ray.ray_dir_x > 0) game->ray.tex_x = TEX_WIDTH - game->ray.tex_x - 1;
		if (game->ray.side == 1 && game->ray.ray_dir_y < 0) game->ray.tex_x = TEX_WIDTH - game->ray.tex_x - 1;
		game->ray.step = 1.0 * TEX_HEIGHT / game->ray.line_height;

		game->ray.tex_pos = (game->ray.draw_start - game->resolution[1] / 2 + game->ray.line_height / 2) * game->ray.step;
		y = game->ray.draw_start - 1;
		while (++y < game->ray.draw_end)
		{
		game->ray.tex_y = (int)game->ray.tex_pos & (TEX_HEIGHT - 1);
		game->ray.tex_pos += game->ray.step;
		game->ray.texture_color = game->img.image_data[NORTH][game->img.size_l / (game->img.bpp / 8) * game->ray.tex_y + game->ray.tex_x];
		if (game->ray.side == 1) game->ray.texture_color = (game->ray.texture_color >> 1) & 8355711;
		buffer[y][x] = game->ray.texture_color;
		}
	}
}

void	check_wall(t_game *game)
{
	game = 0;
}

void	distance(t_game *game)
{
	game = 0;
}
