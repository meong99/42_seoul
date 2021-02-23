/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:51 by mchae             #+#    #+#             */
/*   Updated: 2021/02/23 19:48:09 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map(t_game *game, const char *filename)
{
	int	fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		error_exit("map file open error");
	map_parsing(fd, game);
	find_character(game);
	map_check(game, game->ray.char_pos_x, game->ray.char_pos_y);
	info_error(game);
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
			game->info_map[check_gnl(game, one_line)] = ft_strdup(one_line);
		else if (*one_line != '\0')
		{
			temp_map = map;
			if (!map)
				map = ft_strdup(one_line);
			else
				map = ft_strjoin(map, one_line);
			val_free(&temp_map, 1);
			game->cols++;
		}
		val_free(&one_line, 1);
	}
	game->map = (int**)malloc(sizeof(int*) * game->cols);
	map_mapi(game, (const char*)map);
}

int		check_gnl(t_game *game, char *one_line)
{
	if (!ft_strncmp(one_line, "R ", 2))
		return (overlap_error(game, RESOLUTION));
	else if (!ft_strncmp(one_line, "NO ", 3))
		return (overlap_error(game, NORTH));
	else if (!ft_strncmp(one_line, "SO ", 3))
		return (overlap_error(game, SOUTH));
	else if (!ft_strncmp(one_line, "WE ", 3))
		return (overlap_error(game, WEST));
	else if (!ft_strncmp(one_line, "EA ", 3))
		return (overlap_error(game, EAST));
	else if (!ft_strncmp(one_line, "S ", 2))
		return (overlap_error(game, SPRITE));
	else if (!ft_strncmp(one_line, "F ", 2))
		return (overlap_error(game, FLOOR_COLOR));
	else if (!ft_strncmp(one_line, "C ", 2))
		return (overlap_error(game, CEILING_COLOR));
	else
		error_exit("invalid map info");
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
				game->ray.char_pos_x = j;
				game->ray.char_pos_y = i;
			}
		}
	}
	character_error(game, character);
}
