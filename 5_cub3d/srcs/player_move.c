#include "cub3d.h"

void	player_event_key(t_game *game, int key_code)
{
	if (key_code == K_W || key_code == K_A || key_code == K_S || key_code == K_D)
		player_move(game, key_code);
	else if (key_code == K_AR_U || key_code == K_AR_D || key_code == K_AR_L || key_code == K_AR_R)
		player_cam(game, key_code);
}

void	player_move(t_game *game, int key_code)
{
	if (key_code == K_W)
	{
		if(!(game->map[(int)(game->ray.char_pos_x + game->ray.dir_x * game->ray.move_speed)][(int)(game->ray.char_pos_y)]))
			game->ray.char_pos_x += game->ray.dir_x * game->ray.move_speed;
		if(!(game->map[(int)(game->ray.char_pos_x)][(int)(game->ray.char_pos_y + game->ray.dir_y * game->ray.move_speed)]))
			game->ray.char_pos_y += game->ray.dir_y * game->ray.move_speed;
	}
	else if (key_code == K_S)
	{
		if(!(game->map[(int)(game->ray.char_pos_x - game->ray.dir_x * game->ray.move_speed)][(int)(game->ray.char_pos_y)]))
			game->ray.char_pos_x -= game->ray.dir_x * game->ray.move_speed;
		if(!(game->map[(int)(game->ray.char_pos_x)][(int)(game->ray.char_pos_y - game->ray.dir_y * game->ray.move_speed)]))
			game->ray.char_pos_y -= game->ray.dir_y * game->ray.move_speed;
	}
	else if (key_code == K_A)
	{
		if(!(game->map[(int)(game->ray.char_pos_x)][(int)(game->ray.char_pos_y + game->ray.dir_x * game->ray.move_speed)]))
			game->ray.char_pos_y += game->ray.dir_x * game->ray.move_speed;
		if(!(game->map[(int)(game->ray.char_pos_x + game->ray.dir_y * game->ray.move_speed)][(int)(game->ray.char_pos_y)]))
			game->ray.char_pos_x -= game->ray.dir_y * game->ray.move_speed;
	}
	else if (key_code == K_D)
	{
		if(!(game->map[(int)(game->ray.char_pos_x)][(int)(game->ray.char_pos_y - game->ray.dir_x * game->ray.move_speed)]))
			game->ray.char_pos_y -= game->ray.dir_x * game->ray.move_speed;
		if(!(game->map[(int)(game->ray.char_pos_x - game->ray.dir_y * game->ray.move_speed)][(int)(game->ray.char_pos_y)]))
			game->ray.char_pos_x += game->ray.dir_y * game->ray.move_speed;
	}
}

void	player_cam(t_game *game, int key_code)
{
	if (key_code == K_AR_L)
	{
		game->ray.old_dir_x = game->ray.dir_x;
		game->ray.dir_x = game->ray.dir_x * cos(game->ray.turn_speed) - game->ray.dir_y * sin(game->ray.turn_speed);
		game->ray.dir_y = game->ray.old_dir_x * sin(game->ray.turn_speed) + game->ray.dir_y * cos(game->ray.turn_speed);
		game->ray.old_plane_x = game->ray.plane_x;
		game->ray.plane_x = game->ray.plane_x * cos(game->ray.turn_speed) - game->ray.plane_y * sin(game->ray.turn_speed);
		game->ray.plane_y = game->ray.old_plane_x * sin(game->ray.turn_speed) + game->ray.plane_y * cos(game->ray.turn_speed);
	}
	else if (key_code == K_AR_R)
	{
		game->ray.old_dir_x = game->ray.dir_x;
		game->ray.dir_x = game->ray.dir_x * cos(-game->ray.turn_speed) - game->ray.dir_y * sin(-game->ray.turn_speed);
		game->ray.dir_y = game->ray.old_dir_x * sin(-game->ray.turn_speed) + game->ray.dir_y * cos(-game->ray.turn_speed);
		game->ray.old_plane_x = game->ray.plane_x;
		game->ray.plane_x = game->ray.plane_x * cos(-game->ray.turn_speed) - game->ray.plane_y * sin(-game->ray.turn_speed);
		game->ray.plane_y = game->ray.old_plane_x * sin(-game->ray.turn_speed) + game->ray.plane_y * cos(-game->ray.turn_speed);
	}
}
