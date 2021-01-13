#include "cub3d.h"

int		deal_key(int key_code, t_game *game)
{
	game = 0;
	if (key_code == K_ESC || key_code == EVENT_KEY_EXIT)
		exit(0);
	return (0);
}

int 	win_close(t_game *game)
{
	exit(0);
}