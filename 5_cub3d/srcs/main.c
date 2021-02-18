#include "cub3d.h"

int		main(int argc, char *argv[])
{
	t_game game;

	if (argc < 2 || !argv)
		return (-1);
	game_init(&game, argv[1]);
	mwi_init(&game);
	ray_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &event_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &win_close, 0);

	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}

int		event_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	game = 0;
	return (0);
}

int		win_close()
{
	exit(0);
	return (0);
}

int		main_loop(t_game *game)
{
	game = 0;
	return (0);
}
