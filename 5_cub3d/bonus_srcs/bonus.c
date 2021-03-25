/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 23:30:06 by chaemyeongs       #+#    #+#             */
/*   Updated: 2021/03/25 12:15:55 by mchae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_hud(t_game *game)
{
	char	*leftover_sprite;
	char	*mouse_speed;

	leftover_sprite = ft_itoa(game->info.bonus_sprite_num);
	mouse_speed = ft_itoa(game->mouse.speed);
	mlx_string_put(game->info.mlx, game->info.win,\
		10, 15, 0xFFFFFF, leftover_sprite);
	mlx_string_put(game->info.mlx, game->info.win,\
		35, 15, 0xFFFFFF, "sprites left");
	mlx_string_put(game->info.mlx, game->info.win,\
		game->info.screen_width - 30, \
		15, 0xFFFFFF, mouse_speed);
	free(leftover_sprite);
	free(mouse_speed);
}

void	bonus_key_set(int key_code, t_game *game)
{
	if (key_code == 33 && game->mouse.speed > 1)
		game->mouse.speed--;
	else if (key_code == 30 && game->mouse.speed < 10)
		game->mouse.speed++;
	else if (key_code == K_SPACE)
		bonus_attack(key_code, 0, 0, game);
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
