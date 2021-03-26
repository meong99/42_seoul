/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:04:32 by mchae             #+#    #+#             */
/*   Updated: 2021/03/26 14:47:49 by mchae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_game *game)
{
	int		x;

	x = -1;
	player_move(game);
	draw_fl_cei(&game->info, &game->ray);
	while (++x < game->info.screen_width)
	{
		raycasting_set(game, x);
		dir_set(game);
		hit_scan(game);
		draw_set(game);
		texture_ctrl(game, x);
		game->ray.sprite_buf[x] = game->ray.perp_wall_dist;
	}
	set_sprite_dist(game);
	sprite_cast(game);
	draw_image(&game->info, &game->img, &game->ray);
}

void	load_texture(t_game *game)
{
	int		i;

	i = -1;
	while (++i <= SPRITE)
		load_xpm_image(&game->tex_info[i], &game->info);
	i = -1;
	while (++i <= SPRITE)
		free(game->tex_info[i].texture_path);
}
