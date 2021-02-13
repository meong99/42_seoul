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
		if (i != 0 && count_element(temp) != 2)
			map_error_exit();
		else if (count_element(temp) != 3)
			map_error_exit();
		val_free(temp, 2);
	}
	parsing_map_info(game);
}

void	typing_error(t_game *game)
{

}

void	path_error(t_game *game)
{

}
