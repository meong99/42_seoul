/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:43:05 by selim             #+#    #+#             */
/*   Updated: 2021/02/06 15:31:58 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceil_floor(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->config.screenheight)
	{
		x = 0;
		while (x < game->config.screenwidth)
		{
			if (y > game->config.screenheight / 2 + game->config.eyelevel)
				game->buf[y][x] = game->config.floor_color;
			else
			{
				game->buf[y][x] = game->config.ceiling_color;
			}
			x++;
		}
		y++;
	}
}

void	draw(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->config.screenheight)
	{
		x = 0;
		while (x < game->config.screenwidth)
		{
			game->img.data[y * game->config.screenwidth + x] = game->buf[y][x];
			x++;
		}
		y++;
	}
}
