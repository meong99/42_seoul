#include "cub3d.h"

void	get_map(t_game *game, const char *filename)
{
	int		fd;
	char	*map;

	fd = open(filename, O_RDONLY);
	map = 0;
	game->map = (int**)malloc(sizeof(int*) * map_parsing(fd, game, &map));
	map_mapi(game, map);
	return ;
}

int		map_parsing(int fd, t_game *game, char **map)
{
	char	*one_line;
	int		i;
	char	*temp_map;

	i = 0;
	one_line = 0;
	while (get_next_line(fd, &one_line) || *one_line != '\0')
	{
		if (i <= CEILING_COLOR && *one_line != '\0')
		{
			i++;
			game->info_map[check_gnl(one_line)] = ft_strdup(one_line);
		}
		else if(one_line[0] != '\0')
		{
			temp_map = *map;
			if (!*map)
				*map = ft_strdup(one_line);
			else
				*map = ft_strjoin(*map, one_line);
			str_free(&temp_map);
			i++;
		}
		str_free(&one_line);
	}
	return (--i - CEILING_COLOR);
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

void	map_mapi(t_game *game, char *map)
{
	char	**temp_map;
	int		i;

	i = -1;
	temp_map = ft_split(map, '\n');
	while (temp_map[++i])
		game->map[i] = todigit(temp_map[i]);
}

void	get_mapmask(t_game *game)
{
	game = 0;
}