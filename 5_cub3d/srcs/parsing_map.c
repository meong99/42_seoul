/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaemyeongseog <chaemyeongseog@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:51 by mchae             #+#    #+#             */
/*   Updated: 2021/03/22 03:19:45 by chaemyeongs      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_parsing(t_game *game, const char *filename)
{
	int	fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		error_exit("map file open error");
	get_map(fd, &game->info);
	find_player(&game->info, &game->player);
	map_check(&game->info, game->player.char_pos_x, game->player.char_pos_y);
	reset_map(&game->info);
	element_count_error(&game->info);
	parsing_map_info(&game->info, game->tex_info);
	screen_size_error(&game->info);
	close(fd);
}

void	get_map(int fd, t_info *info)
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
			info->info_map[check_gnl(info, one_line)] = ft_strdup(one_line);
		else if (*one_line != '\0')
		{
			temp_map = map;
			if (!map)
				map = ft_strdup(one_line);
			else
				map = ft_strjoin(map, one_line);
			var_free(&temp_map, 1, 0, 1);
			info->cols++;
		}
		var_free(&one_line, 1, 0, 1);
	}
	split_map_get_rows(info, (const char*)map);
	free(map);
}

void	split_map_get_rows(t_info *info, const char *map)
{
	int	i;

	i = -1;
	info->rows = (int*)var_malloc(sizeof(int) * info->cols);
	info->map = ft_split(map, '\n');
	while (++i < info->cols)
		info->rows[i] = (int)ft_strlen(info->map[i]);
}

void	find_player(t_info *info, t_player *player)
{
	int	i;
	int	j;
	int	character;

	i = -1;
	character = 0;
	while (++i < info->cols)
	{
		j = -1;
		while (++j < info->rows[i])
		{
			if (info->map[i][j] != '0' && info->map[i][j] != '2'
			&& ft_strchr(CHARACTER_DIRS, info->map[i][j]))
			{
				character++;
				player->char_pos_x = 0.5f + j;
				player->char_pos_y = 0.5f + i;
			}
			else if (info->map[i][j] == '2')
				info->sprite_num++;
		}
	}
	player_error(info, player, character);
}

void	reset_map(t_info *info)
{
	int		i;
	int		j;

	i = -1;
	while (++i < info->cols)
	{
		j = -1;
		while (++j < info->rows[i])
		{
			if (info->map[i][j] == 'X')
				info->map[i][j] = '0';
			else if (info->map[i][j] == 'S')
				info->map[i][j] = '2';
		}
	}
}
