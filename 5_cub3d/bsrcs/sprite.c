/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:15:30 by mchae             #+#    #+#             */
/*   Updated: 2021/03/23 14:23:59 by mchae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_bonus_sprite(t_game *game, int *kind, int i)
{
	int		x;
	int		y;

	x = (int)game->sprite_dist[i].x;
	y = (int)game->sprite_dist[i].y;
	if (game->info.map[y][x] == '3')
	{
		*kind = BONUS_SPRITE;
		game->sprite.u_div = 2;
		game->sprite.v_div = 2;
		game->sprite.v_move = 0;
	}
	else
	{
		*kind = SPRITE;
		game->sprite.u_div = 1;
		game->sprite.v_div = 1;
		game->sprite.v_move = 0;
	}
}

void	set_sprite_dist(t_game *game)
{
	int		i;
	int		j;
	int		k;

	k = -1;
	i = -1;
	while (++i < game->info.cols)
	{
		j = -1;
		while (++j < game->info.rows[i])
		{
			if (game->info.map_mask[i][j] == 2)
			{
				game->sprite_dist[++k].x = 0.5 + j;
				game->sprite_dist[k].y = 0.5 + i;
				game->sprite_dist[k].dist = (int)\
					(pow(game->player.char_pos_x - \
					game->sprite_dist[k].x, 2) \
					+ pow(game->player.char_pos_y - \
					game->sprite_dist[k].y, 2));
			}
		}
	}
	quick_sort(game->sprite_dist, 0, game->info.sprite_num - 1);
}

void	sprite_cast(t_game *game)
{
	int		i;
	int		stripe;
	int		kind;

	i = -1;
	stripe = -1;
	while (++i < game->info.sprite_num)
	{
		set_bonus_sprite(game, &kind, i);
		sprite_set(game, i);
		sprite_draw_set(game);
		stripe = game->sprite.sprite_draw_start_x - 1;
		while (++stripe < game->sprite.sprite_draw_end_x)
		{
			game->sprite.sprite_tex_x =\
				(int)(256 * (stripe - (-game->sprite.sprite_width /\
				2 + game->sprite.sprite_screen_x)) *\
				game->tex_info[kind].texture_width /\
				game->sprite.sprite_width) / 256;
			if (game->sprite.transform_y > 0 &&\
				stripe > 0 && stripe < game->info.screen_width &&\
				game->sprite.transform_y < game->ray.sprite_buf[stripe])
				draw_sprite(game, stripe, kind);
		}
	}
}
