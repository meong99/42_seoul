/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:53:28 by mchae             #+#    #+#             */
/*   Updated: 2021/03/28 01:56:41 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	texture_ctrl(t_game *game, int x)
{
	int		y;
	int		texture_dir;

	texture_dir = game->img.texture_dir;
	texture_wall_tex_x(game, texture_dir);
	texture_step_pos_set(game, texture_dir);
	y = game->ray.draw_start - 1;
	while (++y < game->ray.draw_end)
		draw_texture(game, texture_dir, y, x);
}

void	texture_wall_tex_x(t_game *game, int texture_dir)
{
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

void	texture_step_pos_set(t_game *game, int texture_dir)
{
	game->ray.step =\
	1.0 * game->tex_info[texture_dir].texture_height\
	/ game->ray.line_height;
	game->ray.tex_pos =\
	(game->ray.draw_start - game->info.screen_height / 2\
	+ game->ray.line_height / 2 - game->player.eye_level) * game->ray.step;
}

void	draw_texture(t_game *game, int texture_dir, int y, int x)
{
	int		color;

	game->ray.tex_y = (int)game->ray.tex_pos &\
	(game->tex_info[texture_dir].texture_height - 1);
	game->ray.tex_pos += game->ray.step;
	color = game->tex_info[texture_dir].data\
	[game->tex_info[texture_dir].texture_height *\
	game->ray.tex_y + game->ray.tex_x];
	game->ray.buf[y][x] = color;
}
