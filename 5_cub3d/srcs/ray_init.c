/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:30:31 by mchae             #+#    #+#             */
/*   Updated: 2021/03/08 15:41:57 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_init(t_game *game)
{
	int		i;

	i = -1;
	game->ray.turn_speed = get_radian(3);
	game->ray.move_speed = 0.05;
	player_dir_init(game);
	while (++i <= SPRITE)
		load_xpm_image(game, i, game->texture_path[i]);
	i = -1;
	while (++i < 5)
		char_free(&game->texture_path[i], 1);
}

void	buf_init(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	game->ray.buf = (int**)val_malloc(sizeof(int*) * game->screen_height);
	while (++i < game->screen_height)
		game->ray.buf[i] =(int*)val_malloc(sizeof(int) * game->screen_width);
	i = -1;
	while (++i < game->screen_height)
	{
		j = -1;
		while (++j < game->screen_width)
			game->ray.buf[i][j] = 0;
	}
}
