/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:30 by mchae             #+#    #+#             */
/*   Updated: 2021/03/08 18:24:49 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_init(t_game *game, char *filename)
{
	int i;

	i = -1;
	game->info.cols = 0;
	game->info.map_name = filename;
	while (++i < 8)
		game->info.info_check[i] = -1;
	get_map(&game->info, &game->player, game->tex_info, filename);
}

void	mwi_init(t_info *info, t_img *img)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->screen_width,
		info->screen_height, info->map_name);
	img->img = mlx_new_image(info->mlx, info->screen_width, info->screen_height);
	img->data = (int*)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
}
