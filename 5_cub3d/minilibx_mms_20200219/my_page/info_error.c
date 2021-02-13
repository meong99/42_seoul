#include "cub3d.h"

void	info_error(t_game *game)
{
	element_count_error(game);
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
			error_exit();
		else if (i != 0 && count_element(temp) != 2)
			error_exit();
		val_free(temp, 2);
	}
	parsing_map_info(game);
}

void	max_error(int *val, int count, int is_resol)
{
	int		i;

	i = -1;
	if (is_resol)
	{
		if (val[0])
	}
}

void	typing_error(t_game *game)
{
	game = 0;
}

void	path_error(t_game *game)
{
	game = 0;
}
