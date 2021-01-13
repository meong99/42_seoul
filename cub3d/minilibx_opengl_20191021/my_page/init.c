#include "my_mlx.h"

void	atoi_mapi(char **c_map, int **map)
{
	int map_cols;
	int i;
	int j;

	i = 0;
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			map[i][j] = c_map[i][j] - '0';
			j++;
		}
		i++;
	}
}

void	game_init(t_game *game)
{	
	char **map = get_map();
	game->map = (int**)malloc(sizeof(int*) * ROWS);
	for (int i = 0; i < ROWS; i++)
	{
		game->map[i] = (int*)malloc(sizeof(int) * COLS);
	}
	atoi_mapi(map, game->map);
	game->character[g_char_init] = 0;
	game->char_mask[0] = TILE_SIZE / 2;
	game->char_mask[1] = TILE_SIZE / 2;
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "mlx 42");
}

void	img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}
