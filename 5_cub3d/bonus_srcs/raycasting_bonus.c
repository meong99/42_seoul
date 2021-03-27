/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:53 by mchae             #+#    #+#             */
/*   Updated: 2021/03/28 01:34:46 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	raycasting(t_game *game)
{
	int		x;

	x = -1;
	player_move(game);
	draw_fl_cei(&game->info, &game->ray, &game->player);
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
	load_bonus_sprite(game);
	i = -1;
	while (++i <= BONUS_SPRITE)
		free(game->tex_info[i].texture_path);
}
