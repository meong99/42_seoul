#include "cub3d.h"

void	player_move(t_game *game)
{
	player_move_set(&game->info, &game->player);
	player_cam(&game->player);
}

void	player_move_set(t_info *info, t_player *player)
{
	if (!player->reverse && player->forward)
	{
		if(info->map[(int)(player->char_pos_y)][(int)(player->char_pos_x + player->dir_x * player->move_speed)] == '0')
			player->char_pos_x += player->dir_x * player->move_speed;
		if(info->map[(int)(player->char_pos_y + player->dir_y * player->move_speed)][(int)(player->char_pos_x)] == '0')
			player->char_pos_y += player->dir_y * player->move_speed;
	}
	else if (!player->forward && player->reverse)
	{
		if(info->map[(int)(player->char_pos_y)][(int)(player->char_pos_x - player->dir_x * player->move_speed)] == '0')
			player->char_pos_x -= player->dir_x * player->move_speed;
		if(info->map[(int)(player->char_pos_y - player->dir_y * player->move_speed)][(int)(player->char_pos_x)] == '0')
			player->char_pos_y -= player->dir_y * player->move_speed;
	}
	if (!player->right && player->left)
	{
		if(info->map[(int)(player->char_pos_y + player->dir_x * player->move_speed)][(int)(player->char_pos_x)] == '0')
			player->char_pos_y += player->dir_x * player->move_speed;
		if(info->map[(int)(player->char_pos_y)][(int)(player->char_pos_x + player->dir_y * player->move_speed)] == '0')
			player->char_pos_x -= player->dir_y * player->move_speed;
	}
	else if (!player->left && player->right)
	{
		if(info->map[(int)(player->char_pos_y - player->dir_x * player->move_speed)][(int)(player->char_pos_x)] == '0')
			player->char_pos_y -= player->dir_x * player->move_speed;
		if(info->map[(int)(player->char_pos_y)][(int)(player->char_pos_x - player->dir_y * player->move_speed)] == '0')
			player->char_pos_x += player->dir_y * player->move_speed;
	}
}

void	player_cam(t_player *player)
{
	double	old_dir_x;
	double	old_plane_x;

	if (!player->right_turn && player->left_turn)
	{
		old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(player->turn_speed) - player->dir_y * sin(player->turn_speed);
		player->dir_y = old_dir_x * sin(player->turn_speed) + player->dir_y * cos(player->turn_speed);
		old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(player->turn_speed) - player->plane_y * sin(player->turn_speed);
		player->plane_y = old_plane_x * sin(player->turn_speed) + player->plane_y * cos(player->turn_speed);
	}
	else if (!player->left_turn && player->right_turn)
	{
		old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-player->turn_speed) - player->dir_y * sin(-player->turn_speed);
		player->dir_y = old_dir_x * sin(-player->turn_speed) + player->dir_y * cos(-player->turn_speed);
		old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(-player->turn_speed) - player->plane_y * sin(-player->turn_speed);
		player->plane_y = old_plane_x * sin(-player->turn_speed) + player->plane_y * cos(-player->turn_speed);
	}
}
