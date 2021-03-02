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
		if(!(game->map[(int)(game->ray.char_pos_x + game->ray.dir_x * MOVE_SPEED)][(int)(game->ray.char_pos_y)]))
			game->ray.char_pos_x += game->ray.dir_x * MOVE_SPEED;
		if(!(game->map[(int)(game->ray.char_pos_x)][(int)(game->ray.char_pos_y + game->ray.dir_y * MOVE_SPEED)]))
			game->ray.char_pos_y += game->ray.dir_y * MOVE_SPEED;
	}
	else if (key_code == K_S)
	{
		if(!(game->map[(int)(game->ray.char_pos_x - game->ray.dir_x * MOVE_SPEED)][(int)(game->ray.char_pos_y)]))
			game->ray.char_pos_x -= game->ray.dir_x * MOVE_SPEED;
		if(!(game->map[(int)(game->ray.char_pos_x)][(int)(game->ray.char_pos_y - game->ray.dir_y * MOVE_SPEED)]))
			game->ray.char_pos_y -= game->ray.dir_y * MOVE_SPEED;
	}
	else if (key_code == K_A)
	{
		if(!(game->map[(int)(game->ray.char_pos_x)][(int)(game->ray.char_pos_y + game->ray.dir_x * MOVE_SPEED)]))
			game->ray.char_pos_y += game->ray.dir_x * MOVE_SPEED;
		if(!(game->map[(int)(game->ray.char_pos_x + game->ray.dir_y * MOVE_SPEED)][(int)(game->ray.char_pos_y)]))
			game->ray.char_pos_x += game->ray.dir_y * MOVE_SPEED;
	}
	else if (key_code == K_D)
	{
		if(!(game->map[(int)(game->ray.char_pos_x)][(int)(game->ray.char_pos_y - game->ray.dir_x * MOVE_SPEED)]))
			game->ray.char_pos_y -= game->ray.dir_x * MOVE_SPEED;
		if(!(game->map[(int)(game->ray.char_pos_x - game->ray.dir_y * MOVE_SPEED)][(int)(game->ray.char_pos_y)]))
			game->ray.char_pos_x -= game->ray.dir_y * MOVE_SPEED;
	}
}

void	player_cam(t_game *game, int key_code)
{
	if (key_code == K_AR_L)
	{
		game->ray.old_dir_x = game->ray.dir_x;
		game->ray.dir_x = game->ray.dir_x * cos(ROT_SPEED) - game->ray.dir_y * sin(ROT_SPEED);
		game->ray.dir_y = game->ray.old_dir_x * sin(ROT_SPEED) + game->ray.dir_y * cos(ROT_SPEED);
		game->ray.old_plane_x = game->ray.plane_x;
		game->ray.plane_x = game->ray.plane_x * cos(ROT_SPEED) - game->ray.plane_y * sin(ROT_SPEED);
		game->ray.plane_y = game->ray.old_plane_x * sin(ROT_SPEED) + game->ray.plane_y * cos(ROT_SPEED);
	}
	else if (key_code == K_AR_R)
	{
		game->ray.old_dir_x = game->ray.dir_x;
		game->ray.dir_x = game->ray.dir_x * cos(-ROT_SPEED) - game->ray.dir_y * sin(-ROT_SPEED);
		game->ray.dir_y = game->ray.old_dir_x * sin(-ROT_SPEED) + game->ray.dir_y * cos(-ROT_SPEED);
		game->ray.old_plane_x = game->ray.plane_x;
		game->ray.plane_x = game->ray.plane_x * cos(-ROT_SPEED) - game->ray.plane_y * sin(-ROT_SPEED);
		game->ray.plane_y = game->ray.old_plane_x * sin(-ROT_SPEED) + game->ray.plane_y * cos(-ROT_SPEED);
	}
}
