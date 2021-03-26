/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_more_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:52:46 by chaemyeongs       #+#    #+#             */
/*   Updated: 2021/03/26 13:47:43 by mchae            ###   ########seoul.kr  */
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

void	next_stage(t_game *game)
{
	int i;

	i = -1;
	game->stage++;
	game->next_stage = 0;
	all_free(game);
	win_close(game);
	if (game->stage == 2)
	{
		game_init(game, "./maps/next_stage.cub");
		mlx_win_img_init(&game->info, &game->img);
		load_texture(game);
		player_init(&game->player);
		start_loop(game);
	}
}
