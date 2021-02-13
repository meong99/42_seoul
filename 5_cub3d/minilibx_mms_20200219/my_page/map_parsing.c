#include "cub3d.h"

void	parsing_map_info(t_game *game)
{
	char	*tmp;

	tmp = ft_strchr(game->info_map[RESOLUTION], ' ');
	game->resolution[0] = ft_atoi(tmp);
	tmp = ft_strrchr(game->info_map[RESOLUTION], ' ');
	game->resolution[1] = ft_atoi(tmp);
	tmp = ft_strchr(game->info_map[NORTH], ' ');
	game->north_texture = ft_strdup(tmp);
	tmp = ft_strchr(game->info_map[SOUTH], ' ');
	game->north_texture = ft_strdup(tmp);
	tmp = ft_strchr(game->info_map[WEST], ' ');
	game->north_texture = ft_strdup(tmp);
	tmp = ft_strchr(game->info_map[EAST], ' ');
	game->north_texture = ft_strdup(tmp);
	tmp = ft_strchr(game->info_map[SPRITE], ' ');
	game->north_texture = ft_strdup(tmp);
}

void	parsing_color(t_game *game)
{
	char	*tmp;
	
	tmp = ft_strchr(game->info_map[FLOOR_COLOR], ' ');
	game->north_texture = ft_strdup(tmp);
	tmp = ft_strchr(game->info_map[CEILING_COLOR], ' ');
	game->north_texture = ft_strdup(tmp);
}