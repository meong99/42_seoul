/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:46:57 by mchae             #+#    #+#             */
/*   Updated: 2021/03/24 11:34:17 by mchae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	double	x;
	double	y;
	double	x_move;
	double	y_move;

	x = player->char_pos_x;
	y = player->char_pos_y;
	x_move = player->dir_x * player->move_speed;
	y_move = player->dir_y * player->move_speed;
	if (!player->back && player->forward)
	{
		if (info->map[(int)y][(int)(x + x_move * 2)] == '0')
			player->char_pos_x += x_move;
		if (info->map[(int)(y + y_move * 2)][(int)x] == '0')
			player->char_pos_y += y_move;
	}
	else if (!player->forward && player->back)
	{
		if (info->map[(int)y][(int)(x - x_move * 2)] == '0')
			player->char_pos_x -= x_move;
		if (info->map[(int)(y - y_move * 2)][(int)x] == '0')
			player->char_pos_y -= y_move;
	}
}

void	player_move_left_right(t_info *info, t_player *player)
{
	double	x;
	double	y;
	double	x_move;
	double	y_move;

	x = player->char_pos_x;
	y = player->char_pos_y;
	x_move = player->dir_x * player->move_speed;
	y_move = player->dir_y * player->move_speed;
	if (!player->right && player->left)
	{
		if (info->map[(int)(y - x_move * 2)][(int)x] == '0')
			player->char_pos_y -= x_move;
		if (info->map[(int)y][(int)(x + y_move * 2)] == '0')
			player->char_pos_x += y_move;
	}
	else if (!player->left && player->right)
	{
		if (info->map[(int)(y + x_move * 2)][(int)x] == '0')
			player->char_pos_y += x_move;
		if (info->map[(int)y][(int)(x - y_move * 2)] == '0')
			player->char_pos_x -= y_move;
	}
}

void	player_camera_turn(t_player *player, double radian)
{
	double	temp;

	temp = player->dir_x;
	player->dir_x = player->dir_x * cos(radian) - player->dir_y * sin(radian);
	player->dir_y = temp * sin(radian) + player->dir_y * cos(radian);
	temp = player->plane_x;
	player->plane_x =\
		player->plane_x * cos(radian) - player->plane_y * sin(radian);
	player->plane_y = temp * sin(radian) + player->plane_y * cos(radian);
}
