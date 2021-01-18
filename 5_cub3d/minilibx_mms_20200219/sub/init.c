#include "cub3d.h"

void	game_init(t_game *game)
{
	get_pos(game);
	game->dir_x = -1;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66;
	game->time = 0;
	game->oldtime = 0;
}

void	map_init(t_game *game)
{
	int i;

	i = 0;
	game->map_info = get_map(game);
	if (!(game->map = (int**)malloc(sizeof(int*) * game->map_rows)))
		put_error("map **malloc error!");
	while (i < game->map_rows)
	{
		game->map_cols[i] = ft_strlen(game->map_info[MAP + i]);
		if (!(game->map[i] = (int*)malloc(sizeof(int) * game->map_cols[i])))
			put_error("map *malloc error!");
		i++;
	}
	atoi_mapi(game);
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREENWIDTH, SCREENHEIGHT, "mlx_42");
}

void	img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WALL_SIZE, WALL_SIZE);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}
