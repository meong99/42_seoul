/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_more_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaemyeongseog <chaemyeongseog@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:52:46 by chaemyeongs       #+#    #+#             */
/*   Updated: 2021/03/25 21:54:42 by chaemyeongs      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	load_bonus_sprite(t_game *game)
{
	int	fd;

	fd = open("textures/orangefish.xpm", O_RDONLY);
	game->tex_info[BONUS_SPRITE].texture_path = \
		ft_strdup("textures/orangefish.xpm");
	load_xpm_image(&game->tex_info[BONUS_SPRITE], &game->info);
	var_free(&game->tex_info[BONUS_SPRITE].texture_path, 1, 0, 1);
	close(fd);
	game->tex_info[LIFE].texture_path = \
		ft_strdup("textures/orangefish.xpm");
	load_xpm_image(&game->tex_info[LIFE], &game->info);
	var_free(&game->tex_info[LIFE].texture_path, 1, 0, 1);
	close(fd);
}
