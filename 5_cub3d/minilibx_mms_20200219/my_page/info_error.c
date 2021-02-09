#include "cub3d.h"

void	info_error(t_game *game)
{
	parsing_map_info(game);
}

void	empty_error(t_game *game)
{
	char	**temp;
}

void	parsing_map_info(t_game *game)
{
	game->resolution[0] = ft_atoi(ft_strchr(game->info_map[RESOLUTION], ' '));
	game->resolution[1] = ft_atoi(ft_strrchr(game->info_map[RESOLUTION], ' '));
}

void	typing_error(t_game *game)
{

}

void	path_error(t_game *game)
{

}
