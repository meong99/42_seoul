/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:52:46 by chaemyeongs       #+#    #+#             */
/*   Updated: 2021/03/23 13:26:12 by mchae            ###   ########seoul.kr  */
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
	mlx_put_image_to_window(game->info.mlx, game->info.win, game->tex_info[BONUS_SPRITE].img, 10, 10);
}
