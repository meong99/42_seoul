/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:48 by mchae             #+#    #+#             */
/*   Updated: 2021/03/28 00:35:04 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_error(t_info *info, t_player *player, int character)
{
	if (character != 1)
		error_exit("too many players");
	player->char_dir = info->map
		[(int)player->char_pos_y][(int)player->char_pos_x];
	info->map[(int)player->char_pos_y][(int)player->char_pos_x] = '0';
}

void	map_check(t_info *info, int i, int j)
{
	if (i == -1 || i >= info->cols ||
			j == -1 || j > info->rows[i])
		error_exit("not closed");
	if (info->map[i][j] == '1' || info->map_mask[i][j] == 1 || \
		info->map_mask[i][j] == 2)
		return ;
	else if (info->map[i][j] < '0' || info->map[i][j] > '2')
		error_exit("invalid char");
	if (info->map[i][j] == '2')
	{
		info->map_mask[i][j] = 2;
		info->sprite_num++;
	}
	else if (info->map[i][j] == '0')
		info->map_mask[i][j] = 1;
	map_check(info, i + 1, j);
	map_check(info, i - 1, j);
	map_check(info, i, j - 1);
	map_check(info, i, j + 1);
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

void	filename_error(const char *filename)
{
	int		len;
	const char *a;

	len = ft_strlen(filename);
	a = filename + len - 4;
	if (ft_strncmp(filename + len - 4, ".cub", 4))
		error_exit("filename error");
}