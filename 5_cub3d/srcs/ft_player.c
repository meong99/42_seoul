/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:39:41 by mchae             #+#    #+#             */
/*   Updated: 2021/03/14 18:03:10 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_init(t_player *player)
{
	int		angle;

	player->turn_speed = get_radian(3);
	player->move_speed = 0.05;
	player->dir_x = 1.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = -0.66;
	if (player->char_dir == 'E')
		angle = 0;
	else if (player->char_dir == 'N')
		angle = 90;
	else if (player->char_dir == 'W')
		angle = 180;
	else
		angle = 270;
	player_set_dir(player, get_radian(angle));
}

void	player_set_dir(t_player *player, double radian)
{
	int		temp;

	temp = player->dir_x;
	player->dir_x = player->dir_x * cos(radian) - player->dir_y * sin(radian);
	player->dir_y = temp * sin(radian) + player->dir_y * cos(radian);
	temp = player->plane_x;
	player->plane_x =\
		player->plane_x * cos(radian) - player->plane_y * sin(radian);
	player->plane_y = temp * sin(radian) + player->plane_y * cos(radian);
}
