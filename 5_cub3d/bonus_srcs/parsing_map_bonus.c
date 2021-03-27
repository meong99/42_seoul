/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:51 by mchae             #+#    #+#             */
/*   Updated: 2021/03/28 04:00:02 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	map_parsing(t_game *game, const char *filename)
{
	int	fd;

	filename_error(filename);
	if ((fd = open(filename, O_RDONLY)) == -1)
		error_exit("map file open error");
	get_map(fd, &game->info);
	find_player(&game->info, &game->player);
	map_check(&game->info, game->player.char_pos_y, game->player.char_pos_x);
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
			free(temp_map);
			info->cols++;
		}
		free(one_line);
	}
	free(one_line);
	split_map_get_rows(info, map);
}

void	split_map_get_rows(t_info *info, char *map)
{
	int	i;

	i = -1;
	info->rows = (int*)var_malloc(sizeof(int) * info->cols);
	info->map = ft_split(map, '\n');
	while (++i < info->cols)
		info->rows[i] = (int)ft_strlen(info->map[i]);
	i = -1;
	info->map_mask = (int**)var_malloc(sizeof(int*) * info->cols);
	while (++i < info->cols)
		info->map_mask[i] = (int*)var_malloc(sizeof(int) * info->rows[i]);
	free(map);
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
			if (!ft_strchr("0123WESN ", info->map[i][j]))
				error_exit("invalid char");
			if (ft_strchr(CHARACTER_DIRS, info->map[i][j]))
			{
				character++;
				player->char_pos_x = 0.5f + j;
				player->char_pos_y = 0.5f + i;
			}
		}
	}
	player_error(info, player, character);
}
