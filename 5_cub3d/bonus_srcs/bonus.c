/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 23:30:06 by chaemyeongs       #+#    #+#             */
/*   Updated: 2021/03/23 18:56:11 by mchae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_hud(t_game *game)
{
	char	*leftover_sprite;

	leftover_sprite = ft_itoa(game->info.interactive_sprite_num);
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

void	bonus_move(t_game *game, int x, int y)
{
	int i;

	i = -1;
	if (game->info.map[y][x] == '3')
	{
		game->info.map[y][x] = '0';
		game->info.map_mask[y][x] = 0;
		game->info.interactive_sprite_num--;
		// while (++i < game->info.sprite_num)
		// {
		// 	if (y == (int)game->sprite_dist[i].y)
		// 	{
		// 		if (x == (int)game->sprite_dist[i].x)
		// 		{
		// 			game->sprite_dist[i].x = -1;
		// 		}
		// 	}
		// }
	}
}
