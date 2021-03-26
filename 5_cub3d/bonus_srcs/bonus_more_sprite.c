/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_more_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:52:46 by chaemyeongs       #+#    #+#             */
/*   Updated: 2021/03/26 12:56:11 by mchae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	load_bonus_sprite(t_game *game)
{
	int	fd;

	fd = open("textures/orangefish.xpm", O_RDONLY);
	game->tex_info[BONUS_SPRITE].texture_path = \
		ft_strdup("textures/orangefish.xpm");
	load_xpm_image(&game->tex_info[BONUS_SPRITE], &game->info);
	var_free(&game->tex_info[BONUS_SPRITE].texture_path, 1, 0, 1);
	close(fd);
}

void	all_free(t_game *game)
{
	var_free(&game->sprite_dist, 1, game->info.sprite_num, 0);
	var_free(game->ray.buf, 2, game->info.screen_height, 0);
	var_free(&game->info.rows, 1, 0, 0);
	var_free(game->info.map, 2, 0, 1);
	var_free(game->info.map_mask, 2, game->info.cols, 0);
}

void	next_stage(t_game *game)
{
	game = 0;
}

