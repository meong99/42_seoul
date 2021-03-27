/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:05:13 by mchae             #+#    #+#             */
/*   Updated: 2021/03/28 03:50:13 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_set(t_game *game, int i)
{
	game->sprite.sprite_x = \
		game->sprite_dist[i].x - game->player.char_pos_x;
	game->sprite.sprite_y = \
		game->sprite_dist[i].y - game->player.char_pos_y;
	game->sprite.inverse_determinant = \
		1.0 / (game->player.plane_x * game->player.dir_y -\
		game->player.dir_x * game->player.plane_y);
	game->sprite.transform_x = game->sprite.inverse_determinant *\
		(game->player.dir_y * game->sprite.sprite_x - \
			game->player.dir_x * game->sprite.sprite_y);
	game->sprite.transform_y = game->sprite.inverse_determinant *\
		(-game->player.plane_y * game->sprite.sprite_x + \
			game->player.plane_x * game->sprite.sprite_y);
	game->sprite.sprite_screen_x = \
		(int)((game->info.screen_width / 2) *\
		(1 + game->sprite.transform_x / game->sprite.transform_y));
	game->sprite.v_move_screen = (int)V_MOVE / game->sprite.transform_y;
	game->sprite.sprite_height = \
		abs((int)(game->info.screen_height / game->sprite.transform_y)) / V_DIV;
	game->sprite.sprite_draw_start_y = \
		-game->sprite.sprite_height / 2 + game->info.screen_height / 2\
		+ game->sprite.v_move_screen;
}

void	sprite_draw_set(t_game *game)
{
	if (game->sprite.sprite_draw_start_y < 0)
		game->sprite.sprite_draw_start_y = 0;
	game->sprite.sprite_draw_end_y = game->sprite.sprite_height /\
		2 + game->info.screen_height / 2 + game->sprite.v_move_screen;
	if (game->sprite.sprite_draw_end_y >= game->info.screen_height)
		game->sprite.sprite_draw_end_y = game->info.screen_height - 1;
	game->sprite.sprite_width = abs((int)(game->info.screen_height /\
		game->sprite.transform_y)) / U_DIV;
	game->sprite.sprite_draw_start_x = -game->sprite.sprite_width /\
		2 + game->sprite.sprite_screen_x;
	if (game->sprite.sprite_draw_start_x < 0)
		game->sprite.sprite_draw_start_x = 0;
	game->sprite.sprite_draw_end_x = game->sprite.sprite_width /\
		2 + game->sprite.sprite_screen_x;
	if (game->sprite.sprite_draw_end_x >= game->info.screen_width)
		game->sprite.sprite_draw_end_x = game->info.screen_width - 1;
}

void	draw_sprite(t_game *game, int x)
{
	int		color;
	int		y;

	y = game->sprite.sprite_draw_start_y - 1;
	while (++y < game->sprite.sprite_draw_end_y)
	{
		game->sprite.d = (y - game->sprite.v_move_screen) \
			* 256 - game->info.screen_height *\
			128 + game->sprite.sprite_height * 128;
		game->sprite.sprite_tex_y =\
			((game->sprite.d *\
			game->tex_info[SPRITE].texture_height) /\
			game->sprite.sprite_height) / 256;
		color = game->tex_info[SPRITE].data\
			[game->tex_info[SPRITE].size_l / (game->tex_info[SPRITE].bpp / 8) *\
			game->sprite.sprite_tex_y +\
			game->sprite.sprite_tex_x];
		if ((color & 0x00FFFFFF) != 0)
			game->ray.buf[y][x] = color;
	}
}
