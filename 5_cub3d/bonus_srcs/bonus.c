/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 23:30:06 by chaemyeongs       #+#    #+#             */
/*   Updated: 2021/03/24 11:36:15 by mchae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_hud(t_game *game)
{
	char	*leftover_sprite;

	leftover_sprite = ft_itoa(game->info.bonus_sprite_num);
	mlx_string_put(game->info.mlx, game->info.win,\
		10, 15, 0xFFFFFF, leftover_sprite);
	mlx_string_put(game->info.mlx, game->info.win,\
		35, 15, 0xFFFFFF, "sprites left");
	free(leftover_sprite);
}

void	bonus_key_set(int key_code, t_player *player)
{
	if (key_code == K_AR_U)
		player->eye_level += 10;
	else if (key_code == K_AR_D)
		player->eye_level -= 10;
}

void	bonus_move(t_game *game, int i)
{
	int x;
	int y;

	x = game->sprite_dist[i].x;
	y = game->sprite_dist[i].y;
	game->info.map[y][x] = '0';
	game->info.map_mask[y][x] = 0;
	game->info.bonus_sprite_num--;
}
