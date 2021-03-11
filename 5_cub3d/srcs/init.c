/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaemyeongseog <chaemyeongseog@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:30 by mchae             #+#    #+#             */
/*   Updated: 2021/03/11 16:39:09 by chaemyeongs      ###   ########.fr       */
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
	game->info.sprite_num = 0;
	get_map(game, filename);
}

void	mwi_init(t_info *info, t_img *img)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->screen_width,
		info->screen_height, info->map_name);
	img->img = mlx_new_image(info->mlx, info->screen_width, info->screen_height);
	img->data = (int*)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
}
