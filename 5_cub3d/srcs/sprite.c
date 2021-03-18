/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:15:30 by mchae             #+#    #+#             */
/*   Updated: 2021/03/19 04:06:51 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_cast(t_game *game)
{
	int		i;
	int		stripe;

	i = -1;
	stripe = -1;
	while (++i < game->info.sprite_num)
	{
		sprite_set(game, i);
		sprite_draw_set(game);
		stripe = game->ray.sprite.sprite_draw_start_x - 1;
		while (++stripe < game->ray.sprite.sprite_draw_end_x)
		{
			game->ray.sprite.sprite_tex_x =\
				(int)(256 * (stripe - (-game->ray.sprite.sprite_width /\
				2 + game->ray.sprite.sprite_screen_x)) *\
				game->tex_info[SPRITE].texture_width /\
				game->ray.sprite.sprite_width) / 256;
			if (game->ray.sprite.transform_y > 0 &&\
				stripe > 0 && stripe < game->info.screen_width &&\
				game->ray.sprite.transform_y < game->ray.sprite_buf[stripe])
				draw_sprite(game, stripe);
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
			if (game->info.map[i][j] == '2')
			{
				game->ray.sprite_dist[++k].x = 0.5 + j;
				game->ray.sprite_dist[k].y = 0.5 + i;
				game->ray.sprite_dist[k].dist = (int)\
					(pow(game->player.char_pos_x - \
					game->ray.sprite_dist[k].x, 2) \
					+ pow(game->player.char_pos_y - \
					game->ray.sprite_dist[k].y, 2));
			}
		}
	}
	quick_sort(game->ray.sprite_dist, 0, game->info.sprite_num - 1);
}
