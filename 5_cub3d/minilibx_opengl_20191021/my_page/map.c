#include "cub3d.h"

void	get_map(t_game *game, const char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	map_parsing(fd, game);
	game->map = (int**)malloc(sizeof(int*) * game->cols);
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
			str_free(&temp_map);
			game->cols += 1;
		}
		str_free(&one_line);
	}
	map_mapi(game, (const char*)map);
}

int		check_gnl(char *one_line)
{
	if (*one_line == 'R')
		return (RESOLUTION);
	else if (*one_line == 'N')
		return (NORTH);
	else if (one_line[0] == 'S' && one_line[1] == 'O')
		return (SOUTH);
	else if (*one_line == 'W')
		return (WEST);
	else if (*one_line == 'E')
		return (EAST);
	else if (*one_line == 'S')
		return (SPRITE);
	else if (*one_line == 'F')
		return (FLOOR_COLOR);
	else
		return (CEILING_COLOR);	
}

void	map_mapi(t_game *game, const char *map)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	game->char_map = ft_split(map, '\n');
	while (game->char_map[++i])
		game->map[i] = todigit(game->char_map[i]);
	i = -1;
	while (++i < game->cols)
	{
		j = -1;
		k = ft_strlen(game->char_map[i]);
		while (++j < k)
		{
			if (game->map[i][j] == CHARACTER)
			{
				game->ray.map_x = j;
				game->ray.map_y = i;
			}
		}
	}
}

void	get_mapmask(t_game *game)
{
	game = 0;
}