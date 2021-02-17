#include "cub3d.h"

void	info_error(t_game *game)
{
	element_count_error(game);
	screen_size_and_color_error(game);
}

void	element_count_error(t_game *game)
{
	char	**temp;
	int		i;

	i = -1;
	while (++i <= CEILING_COLOR)
	{
		temp = ft_split(game->info_map[i], ' ');
		if (i == 0 && count_element(temp) != 3)
			error_exit(7);
		else if (i != 0 && count_element(temp) != 2)
			error_exit(7);
		val_free(temp, 2);
	}
	parsing_map_info(game);
}

void	screen_size_and_color_error(t_game *game)
{
	int		i;
	int		resol_x;
	int		resol_y;

	i = -1;
	mlx_get_screen_size(game->mlx, &resol_x, &resol_y);
	if (game->resolution[0] > resol_x)
		game->resolution[0] = resol_x;
	if (game->resolution[1] > resol_y)
		game->resolution[1] = resol_y;
	while (++i < 3)
	{
		if (game->floor_color[i] > 255 || game->floor_color[i] < 0 ||
			game->ceiling_color[i] > 255 || game->ceiling_color[i] < 0)
			error_exit(8);
	}
}

int		overlap_error(t_game *game, int type)
{
	if (game->info_check[type] == type)
		error_exit(9);
	else
		game->info_check[type] = type;
	return (type);
}

void	invalid_char_error(const char *info, int type)
{
	if (type == RESOLUTION)
	{	
		while (*info)
		{
			if (*info != ' ' && !ft_isdigit(*info))
				error_exit(5);
			info++;
		}
	}
	else
	{
		while (*info)
		{
			if (*info != ' ' && *info != ',' && !ft_isdigit(*info))
				error_exit(5);
			info++;
		}
	}
}
