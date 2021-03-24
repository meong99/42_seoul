/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:40:10 by mchae             #+#    #+#             */
/*   Updated: 2021/03/24 17:24:15 by mchae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mouse_press(int key_code, int x, int y, t_game *game)
{
	int	i;
	int	sprite_dist_x;

	i = -1;
	key_code = 0;
	x = game->player.char_pos_x + game->player.dir_x;
	if (game->info.map[y][x] == '3')
	{
		game->info.map[y][x] = '0';
		game->info.map_mask[y][x] = 0;
		while (++i < game->info.sprite_num)
		{
			sprite_dist_x = (int)game->sprite_dist[i].x;
			if (x == sprite_dist_x)
				game->sprite_dist[i].dist = 0;
		}
	}
	return (0);
}

int	mouse_relrese(int key_code, int x, int y, t_game *game)
{
	game = 0;
	printf("%d", key_code);
	x = 0;
	return (y);
}

int	mouse_move(int x, int y, t_game *game)
{
	if (game->mouse.start == 0)
		game->mouse.old_x = x;
	game->mouse.turn = get_radian(x - game->mouse.old_x);
	game->mouse.old_x = x;
	player_camera_turn(&game->player, game->mouse.turn / game->mouse.speed);
	game->mouse.start = 1;
	return (y);
}
