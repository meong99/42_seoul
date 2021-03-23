/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 23:30:06 by chaemyeongs       #+#    #+#             */
/*   Updated: 2021/03/23 10:57:47 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_hud(t_game *game)
{
	char	*leftover_sprite;

	leftover_sprite = ft_itoa(game->info.interactive_sprite_num);
	mlx_string_put(game->info.mlx, game->info.win,\
		10, 15, 0xFFFFFF, leftover_sprite);
	mlx_string_put(game->info.mlx, game->info.win,\
		35, 15, 0xFFFFFF, "sprites left");
	free(leftover_sprite);
}
