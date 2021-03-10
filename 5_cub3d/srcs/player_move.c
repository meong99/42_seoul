#include "cub3d.h"

void	player_event_key(t_game *game, int key_code)
{
	if (key_code == K_W || key_code == K_A || key_code == K_S || key_code == K_D)
		player_move(&game->info, &game->player, key_code);
	else if (key_code == K_AR_U || key_code == K_AR_D || key_code == K_AR_L || key_code == K_AR_R)
		player_cam(&game->player, key_code);
}

void	player_move(t_info *info, t_player *player, int key_code)
{
	if (key_code == K_W)
	{
		if(info->map[(int)(player->char_pos_y)][(int)(player->char_pos_x + player->dir_x * player->move_speed)] == '0')
			player->char_pos_x += player->dir_x * player->move_speed;
		if(info->map[(int)(player->char_pos_y + player->dir_y * player->move_speed)][(int)(player->char_pos_x)] == '0')
			player->char_pos_y += player->dir_y * player->move_speed;
	}
	else if (key_code == K_S)
	{
		if(info->map[(int)(player->char_pos_y)][(int)(player->char_pos_x - player->dir_x * player->move_speed)] == '0')
			player->char_pos_x -= player->dir_x * player->move_speed;
		if(info->map[(int)(player->char_pos_y - player->dir_y * player->move_speed)][(int)(player->char_pos_x)] == '0')
			player->char_pos_y -= player->dir_y * player->move_speed;
	}
	else if (key_code == K_A)
	{
		if(info->map[(int)(player->char_pos_y + player->dir_x * player->move_speed)][(int)(player->char_pos_x)] == '0')
			player->char_pos_y += player->dir_x * player->move_speed;
		if(info->map[(int)(player->char_pos_y)][(int)(player->char_pos_x + player->dir_y * player->move_speed)] == '0')
			player->char_pos_x -= player->dir_y * player->move_speed;
	}
	else if (key_code == K_D)
	{
		if(info->map[(int)(player->char_pos_y - player->dir_x * player->move_speed)][(int)(player->char_pos_x)] == '0')
			player->char_pos_y -= player->dir_x * player->move_speed;
		if(info->map[(int)(player->char_pos_y)][(int)(player->char_pos_x - player->dir_y * player->move_speed)] == '0')
			player->char_pos_x += player->dir_y * player->move_speed;
	}
}

void	player_cam(t_player *player, int key_code)
{
	double	old_dir_x;
	double	old_plane_x;

	if (key_code == K_AR_L)
	{
		old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(player->turn_speed) - player->dir_y * sin(player->turn_speed);
		player->dir_y = old_dir_x * sin(player->turn_speed) + player->dir_y * cos(player->turn_speed);
		old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(player->turn_speed) - player->plane_y * sin(player->turn_speed);
		player->plane_y = old_plane_x * sin(player->turn_speed) + player->plane_y * cos(player->turn_speed);
	}
	else if (key_code == K_AR_R)
	{
		old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-player->turn_speed) - player->dir_y * sin(-player->turn_speed);
		player->dir_y = old_dir_x * sin(-player->turn_speed) + player->dir_y * cos(-player->turn_speed);
		old_plane_x = player->plane_x;
		player->plane_x = player->plane_x * cos(-player->turn_speed) - player->plane_y * sin(-player->turn_speed);
		player->plane_y = old_plane_x * sin(-player->turn_speed) + player->plane_y * cos(-player->turn_speed);
	}
}
