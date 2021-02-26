/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:30 by mchae             #+#    #+#             */
/*   Updated: 2021/02/26 20:21:49 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_init(t_game *game, char *filename)
{
	int i;

	i = -1;
	game->cols = 0;
	game->map_name = filename;
	while (++i < 8)
		game->info_check[i] = -1;
	get_map(game, filename);
}

void	mwi_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->screen_width,
		game->screen_height, game->map_name);
	game->img.img = mlx_new_image(game->mlx, game->screen_width, game->screen_height);
	game->img.data = (int*)mlx_get_data_addr(game->img.img, game->img.bpp, game->img.size_l, game->img.endian);
}
