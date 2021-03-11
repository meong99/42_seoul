/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaemyeongseog <chaemyeongseog@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:48 by mchae             #+#    #+#             */
/*   Updated: 2021/03/11 17:08:12 by chaemyeongs      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	character_error(t_info *info, t_player *player, int character)
{
	if (character != 1)
		error_exit("many info");
	player->char_dir = info->map
		[(int)player->char_pos_y][(int)player->char_pos_x];
	info->map[(int)player->char_pos_y][(int)player->char_pos_x] = '0';
}

void	map_check(t_info *info, int pos_x, int pos_y)
{
	if (pos_y == -1 || pos_y >= info->cols ||
			pos_x == -1 || info->map[pos_y][pos_x] == '\0')
		error_exit("not closed");
	if (info->map[pos_y][pos_x] == '1' ||
		info->map[pos_y][pos_x] == 'X' ||
		info->map[pos_y][pos_x] == 'S')
		return ;
	else if (info->map[pos_y][pos_x] != '0' &&
		info->map[pos_y][pos_x] != '2')
		error_exit("invalid char");
	if (info->map[pos_y][pos_x] == '2')
		info->map[pos_y][pos_x] = 'S';
	else
		info->map[pos_y][pos_x] = 'X';
	map_check(info, pos_x + 1, pos_y);
	map_check(info, pos_x - 1, pos_y);
	map_check(info, pos_x, pos_y - 1);
	map_check(info, pos_x, pos_y + 1);
}

void	map_init_zero(t_info *info)
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
