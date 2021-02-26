/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:23:24 by mchae             #+#    #+#             */
/*   Updated: 2021/02/26 20:20:25 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_xpm_image(t_game *game, int i, char *tex_path)
{
	if (!(game->tex[i].img = mlx_xpm_file_to_image(game->mlx, tex_path,
		&game->tex[i].texture_width, &game->tex[i].texture_height)))
		error_exit("texture path error");
	game->tex[i].data = (int*)mlx_get_data_addr(game->tex[i].img, &game->tex[i].bpp, &game->tex[i].size_l, &game->tex[i].endian);
	mlx_destroy_image(game->mlx, game->tex[i].img);
}

void	draw_image(t_game *game, int **buffer)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->screen_height)
	{
		j = -1;
		while (++j < game->screen_width)
			game->img.data[i * game->screen_width + j] = buffer[i][j];
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
