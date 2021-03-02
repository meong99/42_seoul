/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:53 by mchae             #+#    #+#             */
/*   Updated: 2021/03/02 14:28:03 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_game *game)
{
	int		x;

	x = -1;
	buf_init(game);
	while (++x < game->screen_width)
	{
		play_set(game, x);
		dir_set(game);
		hit_scan(game);
		draw_set(game);
		texture_set(game, x);
	}
	draw_image(game);
	int_free(game->ray.buf, 2, game->screen_height);
}

void	check_wall(t_game *game)
{
	game = 0;
}

void	distance(t_game *game)
{
	game = 0;
}
