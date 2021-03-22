/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaemyeongseog <chaemyeongseog@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:53 by mchae             #+#    #+#             */
/*   Updated: 2021/03/22 15:55:31 by chaemyeongs      ###   ########.fr       */
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
		raycasting_set(game, x);
		dir_set(game);
		hit_scan(game);
		draw_set(game);
		texture_ctrl(game, x);
		game->ray.sprite_buf[x] = game->ray.perp_wall_dist;
	}
	game->sprite_dist =\
	(t_sprite_dist*)var_malloc(sizeof(t_sprite_dist) * \
		game->info.sprite_num + game->info.interactive_sprite_num);
	set_sprite_dist(game);
	sprite_cast(game);
	draw_image(&game->info, &game->img, &game->ray);
	var_free(game->ray.buf, 2, game->info.screen_height, 0);
	var_free(&game->ray.sprite_buf, 1, 0, 0);
	var_free(&game->sprite_dist, 1, 0, 0);
}

void	load_texture(t_game *game)
{
	int		i;

	i = -1;
	while (++i <= SPRITE)
		load_xpm_image(&game->tex_info[i], &game->info);
	i = -1;
	while (++i <= SPRITE)
		var_free(&game->tex_info[i].texture_path, 1, 0, 1);
}
