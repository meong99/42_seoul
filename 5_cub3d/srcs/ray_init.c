/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:30:31 by mchae             #+#    #+#             */
/*   Updated: 2021/02/23 19:30:31 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_init(t_game *game)
{
	dir_plane_init(game);
	raycasting(game);
}

void	dir_plane_init(t_game *game)
{
	dir_check_init(game);
	if (game->ray.dir_x)
		game->ray.dir_y = 0;
	else
		game->ray.dir_x = 0;
	if (game->ray.plane_x)
		game->ray.plane_y = 0;
	else
		game->ray.plane_x = 0;
}

void	dir_check_init(t_game *game)
{
	if (game->char_dir == 'S')
	{
		game->ray.dir_y = 1;
		game->ray.plane_x = 0.66;
	}
	else if (game->char_dir == 'N')
	{
		game->ray.dir_y = -1;
		game->ray.plane_x = -0.66;
	}
	else if (game->char_dir == 'W')
	{
		game->ray.dir_x = -1;
		game->ray.plane_y = 0.66;
	}
	else
	{
		game->ray.dir_x = 1;
		game->ray.plane_y = -0.66;
	}
}
