/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:48 by mchae             #+#    #+#             */
/*   Updated: 2021/03/17 14:23:42 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	character_error(t_info *info, t_player *player, int character)
{
	if (character != 1)
		error_exit("too many players");
	player->char_dir = info->map
		[(int)player->char_pos_y][(int)player->char_pos_x];
	info->map[(int)player->char_pos_y][(int)player->char_pos_x] = '0';
}

void	map_check(t_info *info, int j, int i)
{
	if (i == -1 || i >= info->cols ||
			j == -1 || info->map[i][j] == '\0')
		error_exit("not closed");
	if (info->map[i][j] == '1' ||
		info->map[i][j] == 'X' ||
		info->map[i][j] == 'S')
		return ;
	else if (info->map[i][j] != '0' &&
		info->map[i][j] != '2')
		error_exit("invalid char");
	if (info->map[i][j] == '2')
		info->map[i][j] = 'S';
	else
		info->map[i][j] = 'X';
	map_check(info, i + 1, j);
	map_check(info, i - 1, j);
	map_check(info, i, j - 1);
	map_check(info, i, j + 1);
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
