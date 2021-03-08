/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:48 by mchae             #+#    #+#             */
/*   Updated: 2021/03/08 18:09:48 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	character_error(t_info *info, t_player *player, int character)
{
	if (character != 1)
		error_exit("many info");
	player->char_dir = info->char_map
		[(int)player->char_pos_y][(int)player->char_pos_x];
	info->char_map[(int)player->char_pos_y][(int)player->char_pos_x] = '0';
}

/*
** void	asdasd(t_game *game)
** {
** 	int i = -1;
** 	while (game->char_map[++i])
** 		printf("%s\n", game->char_map[i]);
** }
*/
/*
** 	asdasd(game);
** 	usleep(5000);
*/

void	map_check(t_info *info, int pos_x, int pos_y)
{
	if (pos_y == -1 || pos_y >= info->cols ||
			pos_x == -1 || info->char_map[pos_y][pos_x] == '\0')
		error_exit("not closed");
	if (info->char_map[pos_y][pos_x] == '1' ||
		info->char_map[pos_y][pos_x] == 'X' ||
		info->char_map[pos_y][pos_x] == 'S')
		return ;
	else if (info->char_map[pos_y][pos_x] != '0' &&
		info->char_map[pos_y][pos_x] != '2')
		error_exit("invalid char");
	if (info->char_map[pos_y][pos_x] == '2')
		info->char_map[pos_y][pos_x] = 'S';
	else
		info->char_map[pos_y][pos_x] = 'X';
	map_check(info, pos_x + 1, pos_y);
	map_check(info, pos_x - 1, pos_y);
	map_check(info, pos_x, pos_y - 1);
	map_check(info, pos_x, pos_y + 1);
}
