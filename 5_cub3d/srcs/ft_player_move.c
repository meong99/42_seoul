/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaemyeongseog <chaemyeongseog@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:46:57 by mchae             #+#    #+#             */
/*   Updated: 2021/03/16 16:16:55 by chaemyeongs      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_move(t_game *game)
{
	player_move_back_forward(&game->info, &game->player);
	player_move_left_right(&game->info, &game->player);
	if (!game->player.right_turn && game->player.left_turn)
		player_cam_left(&game->player);
	else if (!game->player.left_turn && game->player.right_turn)
		player_cam_right(&game->player);
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
		if (info->map[(int)(player->char_pos_y + \
				player->dir_x * (player->move_speed * 2))]\
				[(int)(player->char_pos_x)] == '0')
			player->char_pos_y += player->dir_x * player->move_speed;
		if (info->map[(int)(player->char_pos_y)]\
				[(int)(player->char_pos_x - \
				player->dir_y * (player->move_speed * 2))] == '0')
			player->char_pos_x -= player->dir_y * player->move_speed;
	}
	else if (!player->left && player->right)
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
}

void	player_cam_left(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(player->turn_speed) \
			- player->dir_y * sin(player->turn_speed);
	player->dir_y = old_dir_x * sin(player->turn_speed) + \
			player->dir_y * cos(player->turn_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(player->turn_speed) \
			- player->plane_y * sin(player->turn_speed);
	player->plane_y = old_plane_x * sin(player->turn_speed) + \
			player->plane_y * cos(player->turn_speed);
}

void	player_cam_right(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-player->turn_speed) - \
			player->dir_y * sin(-player->turn_speed);
	player->dir_y = old_dir_x * sin(-player->turn_speed) + \
			player->dir_y * cos(-player->turn_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-player->turn_speed) - \
			player->plane_y * sin(-player->turn_speed);
	player->plane_y = old_plane_x * sin(-player->turn_speed) + \
			player->plane_y * cos(-player->turn_speed);
}
