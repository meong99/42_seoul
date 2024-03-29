/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:05:25 by mchae             #+#    #+#             */
/*   Updated: 2021/03/28 03:48:41 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_cast(t_game *game)
{
	int		i;
	int		x;

	i = -1;
	x = -1;
	while (++i < game->info.sprite_num)
	{
		sprite_set(game, i);
		sprite_draw_set(game);
		x = game->sprite.sprite_draw_start_x - 1;
		while (++x < game->sprite.sprite_draw_end_x)
		{
			game->sprite.sprite_tex_x =\
				(int)(256 * (x - (-game->sprite.sprite_width /\
				2 + game->sprite.sprite_screen_x)) *\
				game->tex_info[SPRITE].texture_width /\
				game->sprite.sprite_width) / 256;
			if (game->sprite.transform_y > 0 &&\
				x > 0 && x < game->info.screen_width &&\
				game->sprite.transform_y < game->ray.sprite_buf[x])
				draw_sprite(game, x);
		}
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
