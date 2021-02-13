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
	game->south_texture = ft_strdup(tmp);
	tmp = ft_strchr(game->info_map[WEST], ' ');
	game->west_texture = ft_strdup(tmp);
	tmp = ft_strchr(game->info_map[EAST], ' ');
	game->east_texture = ft_strdup(tmp);
	tmp = ft_strchr(game->info_map[SPRITE], ' ');
	game->sprite_texture = ft_strdup(tmp);
}

void	parsing_color(t_game *game)
{
	char	*tmp;
	char	**tmp_split;
	int		i;

	i = -1;
	tmp = ft_strchr(game->info_map[FLOOR_COLOR], ' ');
	tmp_split = ft_split(tmp, ',');
	while (++i < 3)
		game->floor_color[i] = ft_atoi(tmp_split[i]);
	val_free(tmp_split, 2);
	i = -1;
	tmp = ft_strchr(game->info_map[CEILING_COLOR], ' ');
	tmp_split = ft_split(tmp, ',');
	while (++i < 3)
		game->floor_color[i] = ft_atoi(tmp_split[i]);
	val_free(tmp_split, 2);
}