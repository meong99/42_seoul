/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaemyeongseog <chaemyeongseog@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:53 by mchae             #+#    #+#             */
/*   Updated: 2021/03/10 18:20:14 by chaemyeongs      ###   ########.fr       */
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
	var_free(game->ray.buf, 2, game->info.screen_height, TYPE_INT);
	var_free(&game->ray.sprite_buf, 1, 0, TYPE_DOUBLE);
}

void	check_wall(t_game *game)
{
	game = 0;
}

void	distance(t_game *game)
{
	game = 0;
}
