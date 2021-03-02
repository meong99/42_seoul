/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaemyeongseog <chaemyeongseog@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:30:31 by mchae             #+#    #+#             */
/*   Updated: 2021/02/28 17:13:28 by chaemyeongs      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_init(t_game *game)
{
	int		i;

	i = -1;
	dir_plane_init(game);
	while (++i < SPRITE)
		load_xpm_image(game, i, game->texture_path[i]);
	i = -1;
	while (++i < 5)
		char_free(&game->texture_path[i], 1);
	buf_init(game);
	raycasting(game);
}

void	buf_init(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	game->ray.buf = (int**)val_malloc(sizeof(int*) * game->screen_height);
	while (++i < game->screen_height)
		game->ray.buf[i] =(int*)val_malloc(sizeof(int) * game->screen_width);
	i = -1;
	while (++i < game->screen_height)
	{
		j = -1;
		while (++j < game->screen_width)
			game->ray.buf[i][j] = 0;
	}
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
