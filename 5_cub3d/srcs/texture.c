/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:53:28 by mchae             #+#    #+#             */
/*   Updated: 2021/03/18 12:06:32 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_set(t_game *game)
{
	int		texture_dir;

	texture_dir = game->img.texture_dir;
	if (game->ray.side == 0)
		game->ray.wall_x = game->player.char_pos_y +\
		game->ray.perp_wall_dist * game->ray.ray_dir_y;
	else
		game->ray.wall_x = game->player.char_pos_x +\
		game->ray.perp_wall_dist * game->ray.ray_dir_x;
	game->ray.wall_x -= floor((game->ray.wall_x));
	game->ray.tex_x = (int)(game->ray.wall_x *\
	game->tex_info[texture_dir].texture_width);
	if (texture_dir == SOUTH || texture_dir == WEST)
		game->ray.tex_x = \
		game->tex_info[texture_dir].texture_width -\
		game->ray.tex_x - 1;
}

void	texture_ctrl(t_game *game, int x)
{
	int		y;
	int		color;
	int		texture_dir;

	texture_dir = game->img.texture_dir;
	texture_set(game);
	game->ray.step =\
	1.0 * game->tex_info[texture_dir].texture_height\
	/ game->ray.line_height;
	game->ray.tex_pos =\
	(game->ray.draw_start - (game->info.screen_height >> 1)\
	+ (game->ray.line_height >> 1)) * game->ray.step;
	y = game->ray.draw_start - 1;
	while (++y < game->ray.draw_end)
	{
		game->ray.tex_y = (int)game->ray.tex_pos &\
		(game->tex_info[texture_dir].texture_height - 1);
		game->ray.tex_pos += game->ray.step;
		color = game->tex_info[texture_dir].data\
		[game->tex_info[texture_dir].texture_height *\
		game->ray.tex_y + game->ray.tex_x];
		game->ray.buf[y][x] = color;
	}
}
