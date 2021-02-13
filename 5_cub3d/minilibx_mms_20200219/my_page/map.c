#include "cub3d.h"

void	get_map(t_game *game, const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	map_parsing(fd, game);
	find_character(game);
	map_check(game, game->ray.map_x, game->ray.map_y);
	return ;
}

void	map_parsing(int fd, t_game *game)
{
	char	*one_line;
	int		i;
	char	*temp_map;
	char	*map;

	i = -1;
	map = 0;
	while (get_next_line(fd, &one_line) || *one_line != '\0')
	{
		if (*one_line != '\0' && ++i <= CEILING_COLOR)
			game->info_map[check_gnl(one_line)] = ft_strdup(one_line);
		else if(*one_line != '\0')
		{
			temp_map = map;
			if (!map)
				map = ft_strdup(one_line);
			else
				map = ft_strjoin(map, one_line);
			val_free(&temp_map, 1);
			game->cols += 1;
		}
		val_free(&one_line, 1);
	}
	game->map = (int**)malloc(sizeof(int*) * game->cols);
	map_mapi(game, (const char*)map);
}

int		check_gnl(char *one_line)
{
	if (ft_strncmp(one_line, "R ", 2))
		return (RESOLUTION);
	else if (ft_strncmp(one_line, "N ", 2))
		return (NORTH);
	else if (ft_strncmp(one_line, "SO ", 3))
		return (SOUTH);
	else if (ft_strncmp(one_line, "W ", 2))
		return (WEST);
	else if (ft_strncmp(one_line, "E ", 2))
		return (EAST);
	else if (ft_strncmp(one_line, "S ", 2))
		return (SPRITE);
	else if (ft_strncmp(one_line, "F ", 2))
		return (FLOOR_COLOR);
	else if (ft_strncmp(one_line, "C ", 2))
		return (CEILING_COLOR);	
	else
		map_error_exit(4);
	return (-1);
}

void	map_mapi(t_game *game, const char *map)
{
	int	i;

	i = -1;
	game->rows = (int*)malloc(sizeof(int) * game->cols);
	game->char_map = ft_split(map, '\n');
	while (game->char_map[++i])
		game->map[i] = todigit(game, game->char_map[i], i);
}

void	find_character(t_game *game)
{
	int	i;
	int	j;
	int	character;

	i = -1;
	character = 0;
	while (++i < game->cols)
	{
		j = -1;
		while (++j < game->rows[i])
		{
			if (game->map[i][j] != 0 && game->map[i][j] != 2 
			&& ft_strchr(CHARACTER_DIRS, game->char_map[i][j]))
			{
				character++;
				game->ray.map_x = j;
				game->ray.map_y = i;
			}
		}
	}
	character_error(game, character);
}