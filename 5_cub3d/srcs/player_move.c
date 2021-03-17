/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:46:57 by mchae             #+#    #+#             */
/*   Updated: 2021/03/17 17:32:45 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_move(t_game *game)
{
	player_move_back_forward(&game->info, &game->player);
	player_move_left_right(&game->info, &game->player);
	if (!game->player.right_turn && game->player.left_turn)
		player_camera_turn(&game->player, -game->player.turn_speed);
	else if (!game->player.left_turn && game->player.right_turn)
		player_camera_turn(&game->player, game->player.turn_speed);
}

void	player_move_back_forward(t_info *info, t_player *player)
{
	if (!player->back && player->forward)
	{
		if (info->map[(int)(player->char_pos_y)]\
				[(int)(player->char_pos_x + \
				player->dir_x * (player->move_speed * 2))] == '0')
			player->char_pos_x += player->dir_x * player->move_speed;
		if (info->map[(int)(player->char_pos_y + \
				player->dir_y * (player->move_speed * 2))]\
					[(int)(player->char_pos_x)] == '0')
			player->char_pos_y += player->dir_y * player->move_speed;
	}
	else if (!player->forward && player->back)
	{
		if (info->map[(int)(player->char_pos_y)]\
				[(int)(player->char_pos_x - \
				player->dir_x * (player->move_speed * 2))] == '0')
			player->char_pos_x -= player->dir_x * player->move_speed;
		if (info->map[(int)(player->char_pos_y - \
				player->dir_y * (player->move_speed * 2))]\
				[(int)(player->char_pos_x)] == '0')
			player->char_pos_y -= player->dir_y * player->move_speed;
	}
}

void	player_move_left_right(t_info *info, t_player *player)
{
	if (!player->right && player->left)
	{
		if (info->map[(int)(player->char_pos_y - \
				player->dir_x * (player->move_speed * 2))]\
				[(int)(player->char_pos_x)] == '0')
			player->char_pos_y -= player->dir_x * player->move_speed;
		if (info->map[(int)(player->char_pos_y)]\
				[(int)(player->char_pos_x + \
				player->dir_y * (player->move_speed * 2))] == '0')
			player->char_pos_x += player->dir_y * player->move_speed;
	}
	else if (!player->left && player->right)
	{
		if (info->map[(int)(player->char_pos_y + \
				player->dir_x * (player->move_speed * 2))]\
				[(int)(player->char_pos_x)] == '0')
			player->char_pos_y += player->dir_x * player->move_speed;
		if (info->map[(int)(player->char_pos_y)]\
				[(int)(player->char_pos_x - \
				player->dir_y * (player->move_speed * 2))] == '0')
			player->char_pos_x -= player->dir_y * player->move_speed;
	}
}
