/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaemyeongseog <chaemyeongseog@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:30:31 by mchae             #+#    #+#             */
/*   Updated: 2021/03/10 18:22:20 by chaemyeongs      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_init(t_game *game)
{
	int		i;

	i = -1;
	game->player.turn_speed = get_radian(3);
	game->player.move_speed = 0.5f;
	player_dir_init(&game->player);
	while (++i <= SPRITE)
		load_xpm_image(&game->tex_info[i], &game->info);
	i = -1;
	while (++i < 5)
		var_free(&game->tex_info[i].texture_path, 1, 0, TYPE_CHAR);
}

void	buf_init(t_info *info, t_ray *ray)
{
	int		i;
	int		j;

	i = -1;
	ray->buf = (int**)var_malloc(sizeof(int*) * info->screen_height);
	while (++i < info->screen_height)
		ray->buf[i] =(int*)var_malloc(sizeof(int) * info->screen_width);
	i = -1;
	while (++i < info->screen_height)
	{
		j = -1;
		while (++j < info->screen_width)
			ray->buf[i][j] = 0;
	}
	ray->sprite_buf = (double*)var_malloc(sizeof(double) * info->screen_width);
}
