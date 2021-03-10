/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaemyeongseog <chaemyeongseog@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:51 by mchae             #+#    #+#             */
/*   Updated: 2021/03/10 14:34:58 by chaemyeongs      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map(t_info *info, t_player *player, t_tex_info *tex_info, const char *filename)
{
	int	fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		error_exit("map file open error");
	map_parsing(fd, info);
	find_character(info, player);
	map_check(info, player->char_pos_x, player->char_pos_y);
	map_init_zero(info);
	info_error(info, tex_info);
	return ;
}

void	map_parsing(int fd, t_info *info)
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
			char_free(&temp_map, 1);
			info->cols++;
		}
		char_free(&one_line, 1);
	}
	map_mapi(info, (const char*)map);
}

int		check_gnl(t_info *info, char *one_line)
{
	if (!ft_strncmp(one_line, "R ", 2))
		return (overlap_error(info, RESOLUTION));
	else if (!ft_strncmp(one_line, "NO ", 3))
		return (overlap_error(info, NORTH));
	else if (!ft_strncmp(one_line, "SO ", 3))
		return (overlap_error(info, SOUTH));
	else if (!ft_strncmp(one_line, "WE ", 3))
		return (overlap_error(info, WEST));
	else if (!ft_strncmp(one_line, "EA ", 3))
		return (overlap_error(info, EAST));
	else if (!ft_strncmp(one_line, "S ", 2))
		return (overlap_error(info, SPRITE));
	else if (!ft_strncmp(one_line, "F ", 2))
		return (overlap_error(info, FLOOR_COLOR));
	else if (!ft_strncmp(one_line, "C ", 2))
		return (overlap_error(info, CEILING_COLOR));
	else
		error_exit("invalid map info");
	return (-1);
}

void	map_mapi(t_info *info, const char *map)
{
	int	i;

	i = -1;
	info->rows = (int*)val_malloc(sizeof(int) * info->cols);
	info->map = ft_split(map, '\n');
	while (++i < info->cols)
		info->rows[i] = (int)ft_strlen(info->map[i]);
}

void	find_character(t_info *info, t_player *player)
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
		}
	}
	character_error(info, player, character);
}
