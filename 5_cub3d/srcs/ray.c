/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:53 by mchae             #+#    #+#             */
/*   Updated: 2021/03/08 18:22:33 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_game *game)
{
	int		x;

	x = -1;
	buf_init(&game->info, &game->ray);
	draw_fl_cei(&game->info, &game->ray);
	while (++x < game->info.screen_width)
	{
		play_set(game, x);
		dir_set(game);
		hit_scan(game);
		draw_set(game);
		texture_set(game, x);
	}
	draw_image(&game->info, &game->img, &game->ray);
	int_free(game->ray.buf, 2, game->info.screen_height);
}

void	check_wall(t_game *game)
{
	game = 0;
}

void	distance(t_game *game)
{
	game = 0;
}
