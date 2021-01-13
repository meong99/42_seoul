#include "cub3d.h"

int	main_loop(t_game *game)
{
	int x;

	x = 0;
	while (x < SCREENWIDTH / 2)
	{
		ray_init(x, game);
		get_side_dist(game);
		dda(game);
		draw_init(x, game);
		x++;
	}
	return (0);
}

int main()
{
	t_game		game;
	
	map_init(&game);
	game_init(&game);
	window_init(&game);
	main_loop(&game);

	mlx_hook(game.win, EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, EVENT_KEY_EXIT, 0, &win_close, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}