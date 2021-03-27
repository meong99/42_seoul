/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_more_sprite_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:52:46 by chaemyeongs       #+#    #+#             */
/*   Updated: 2021/03/27 22:26:41 by mchae            ###   ########.fr       */
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
	close(fd);
}

void	next_stage(t_game *game)
{
	int i;

	i = -1;
	game->stage++;
	game->next_stage = 0;
	all_free(game);
	while (++i <= SPRITE)
		mlx_destroy_image(game->info.mlx, game->tex_info[i].img);
	mlx_destroy_image(game->info.mlx, game->img.img);
	mlx_destroy_window(game->info.mlx, game->info.win);
	system("killall afplay");
	if (game->stage > 2)
	{
		while (1);
		exit(0);
	}
	if (game->stage == 2)
	{
		game_init(game, "./maps/next_stage.cub");
		mlx_win_img_init(&game->info, &game->img);
		load_texture(game);
		player_init(&game->player);
		start_loop(game);
	}
}
