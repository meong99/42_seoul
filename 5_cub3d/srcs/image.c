/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:23:24 by mchae             #+#    #+#             */
/*   Updated: 2021/02/23 23:23:18 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_xpm_image(t_game *game)
{
	int		i;
	void	*image[5];

	i = 0;
	while (++i <= SPRITE)
	{
		if (!(image[i] = mlx_xpm_file_to_image(game->mlx, game->
			north_texture, game->ray.texture_width, game->ray.texture_height)))
			error_exit("texture path error");
		game->img.image_data[i] = (int*)mlx_get_data_addr(image[i], game->img.bpp, game->img.size_l, game->img.endian);
		mlx_destroy_image(game->mlx, image[i]);
	}
}

void	draw_image(t_game *game, int *buffer)
{
	for (int y = 0; y < game->resolution[1]; y++)
	{
		for (int x = 0; x < game->resolution[0]; x++)
		{
			game->img.data[y * game->resolution[0] + x] = buffer[y][x];
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
