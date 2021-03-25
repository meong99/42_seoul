/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:40:10 by mchae             #+#    #+#             */
/*   Updated: 2021/03/25 12:25:28 by mchae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	bonus_attack(int key_code, int x, int y, t_game *game)
{
	int	i;
	int	sprite_dist_x;

	i = -1;
	x = (int)(game->player.char_pos_x + game->player.dir_x);
	y = (int)(game->player.char_pos_y + game->player.dir_y);
	if (game->info.map[y][x] == '3')
	{
		game->info.map[y][x] = '0';
		game->info.map_mask[y][x] = 0;
		while (++i < game->info.sprite_num)
		{
			sprite_dist_x = (int)game->sprite_dist[i].x;
			if (x == sprite_dist_x)
			{
				game->sprite_dist[i].dist = 0;
				game->info.bonus_sprite_num--;
			}
		}
	}
	return (key_code);
}

int	mouse_move(int x, int y, t_game *game)
{
	double radian;

	if (game->mouse.start == 0)
		game->mouse.old_x = x;
	game->mouse.turn = get_radian(x - game->mouse.old_x);
	game->mouse.old_x = x;
	radian = game->mouse.turn / game->mouse.speed;
	if (radian < 10)
		player_camera_turn(&game->player, radian);
	game->mouse.start = 1;
	return (y);
}
