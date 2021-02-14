/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_fish_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:59:45 by selim             #+#    #+#             */
/*   Updated: 2021/02/04 17:00:09 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int			is_okay(char c)
{
	if (c == '0' || c == '3')
		return (1);
	return (0);
}

void		catch_fish(t_game *game, t_player *p)
{
	t_sprite_y temp;

	if (game->config.map[(int)p->posx][(int)p->posy] == '3')
	{
		temp = game->sprite[game->config.sprite_num - 1];
		game->sprite[game->config.sprite_num - 1] = game->sprite[0];
		game->sprite[0] = game->sprite[game->config.sprite_num - 1];
		game->config.sprite_num--;
		game->config.map[(int)p->posx][(int)p->posy] = '0';
	}
}
