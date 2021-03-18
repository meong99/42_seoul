/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:24:09 by mchae             #+#    #+#             */
/*   Updated: 2021/03/18 15:24:39 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_set(t_game *game, int i)
{
	game->ray.sprite.sprite_x = \
		game->ray.sprite_dist[i].x - game->player.char_pos_x;
	game->ray.sprite.sprite_y = \
		game->ray.sprite_dist[i].y - game->player.char_pos_y;
	game->ray.sprite.inverse_determinant = \
		1.0 / (game->player.plane_x * game->player.dir_y -\
		game->player.dir_x * game->player.plane_y);
	game->ray.sprite.transform_x = game->ray.sprite.inverse_determinant *\
		(game->player.dir_y * game->ray.sprite.sprite_x - \
			game->player.dir_x * game->ray.sprite.sprite_y);
	game->ray.sprite.transform_y = game->ray.sprite.inverse_determinant *\
		(-game->player.plane_y * game->ray.sprite.sprite_x + \
			game->player.plane_x * game->ray.sprite.sprite_y);
	game->ray.sprite.sprite_screen_x = \
		(int)((game->info.screen_width / 2) *\
		(1 + game->ray.sprite.transform_x / game->ray.sprite.transform_y));
	game->ray.sprite.sprite_height = \
		abs((int)(game->info.screen_height / game->ray.sprite.transform_y));
	game->ray.sprite.sprite_draw_start_y = \
		-game->ray.sprite.sprite_height / 2 + game->info.screen_height / 2;
}

void	sprite_draw_set(t_game *game)
{
	if (game->ray.sprite.sprite_draw_start_y < 0)
		game->ray.sprite.sprite_draw_start_y = 0;
	game->ray.sprite.sprite_draw_end_y = game->ray.sprite.sprite_height /\
		2 + game->info.screen_height / 2;
	if (game->ray.sprite.sprite_draw_end_y >= game->info.screen_height)
		game->ray.sprite.sprite_draw_end_y = game->info.screen_height - 1;
	game->ray.sprite.sprite_width = abs((int)(game->info.screen_height /\
		game->ray.sprite.transform_y));
	game->ray.sprite.sprite_draw_start_x = -game->ray.sprite.sprite_width /\
		2 + game->ray.sprite.sprite_screen_x;
	if (game->ray.sprite.sprite_draw_start_x < 0)
		game->ray.sprite.sprite_draw_start_x = 0;
	game->ray.sprite.sprite_draw_end_x = game->ray.sprite.sprite_width /\
		2 + game->ray.sprite.sprite_screen_x;
	if (game->ray.sprite.sprite_draw_end_x >= game->info.screen_width)
		game->ray.sprite.sprite_draw_end_x = game->info.screen_width - 1;
}

void	draw_sprite(t_game *game, int stripe)
{
	int		color;
	int		j;

	j = game->ray.sprite.sprite_draw_start_y - 1;
	while (++j < game->ray.sprite.sprite_draw_end_y)
	{
		game->ray.sprite.d = (j) * 256 - game->info.screen_height *\
			128 + game->ray.sprite.sprite_height * 128;
		game->ray.sprite.sprite_tex_y =\
			((game->ray.sprite.d *\
			game->tex_info[SPRITE].texture_height) /\
			game->ray.sprite.sprite_height) / 256;
		color = game->tex_info[SPRITE].data\
			[game->tex_info[SPRITE].size_l / (game->tex_info[SPRITE].bpp / 8) *\
			game->ray.sprite.sprite_tex_y +\
			game->ray.sprite.sprite_tex_x];
		if ((color & 0x00FFFFFF) != 0)
			game->ray.buf[j][stripe] = color;
	}
}
