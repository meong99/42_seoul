/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:48 by mchae             #+#    #+#             */
/*   Updated: 2021/02/23 19:49:48 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	character_error(t_game *game, int character)
{
	if (character != 1)
		error_exit("many player");
	game->char_dir = game->char_map
		[(int)game->ray.char_pos_y][(int)game->ray.char_pos_x];
	game->char_map[(int)game->ray.char_pos_y][(int)game->ray.char_pos_x] = '0';
	game->map[(int)game->ray.char_pos_y][(int)game->ray.char_pos_x] = 0;
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

void	map_check(t_game *game, int pos_x, int pos_y)
{
	if (pos_y == -1 || pos_y >= game->cols ||
			pos_x == -1 || game->char_map[pos_y][pos_x] == '\0')
		error_exit("not closed");
	if (game->char_map[pos_y][pos_x] == '1' ||
		game->char_map[pos_y][pos_x] == 'X' ||
		game->char_map[pos_y][pos_x] == 'S')
		return ;
	else if (game->char_map[pos_y][pos_x] != '0' &&
		game->char_map[pos_y][pos_x] != '2')
		error_exit("invalid char");
	if (game->char_map[pos_y][pos_x] == '2')
		game->char_map[pos_y][pos_x] = 'S';
	else
		game->char_map[pos_y][pos_x] = 'X';
	map_check(game, pos_x + 1, pos_y);
	map_check(game, pos_x - 1, pos_y);
	map_check(game, pos_x, pos_y - 1);
	map_check(game, pos_x, pos_y + 1);
}
