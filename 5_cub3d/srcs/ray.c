/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:53 by mchae             #+#    #+#             */
/*   Updated: 2021/03/13 17:36:53 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_game *game)
{
	int		x;

	x = -1;
	player_move(game);
	buf_init(&game->info, &game->ray);
	draw_fl_cei(&game->info, &game->ray);
	while (++x < game->info.screen_width)
	{
		play_set(game, x);
		dir_set(game);
		hit_scan(game);
		draw_set(game);
		texture_set(game, x);
		game->ray.sprite_buf[x] = game->ray.perp_wall_dist;
	}
	set_sprite(game);
	sprite_cast(game);
	draw_image(&game->info, &game->img, &game->ray);
	var_free(game->ray.buf, 2, game->info.screen_height, 0);
	var_free(&game->ray.sprite_buf, 1, 0, 0);
	var_free(&game->ray.sprite_dist, 1, 0, 0);
}
