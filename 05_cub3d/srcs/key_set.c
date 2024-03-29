/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:11:14 by mchae             #+#    #+#             */
/*   Updated: 2021/03/27 20:12:47 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press_set(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		win_close(game);
	else if (key_code == K_W)
		game->player.forward = 1;
	else if (key_code == K_S)
		game->player.back = 1;
	else if (key_code == K_A)
		game->player.left = 1;
	else if (key_code == K_D)
		game->player.right = 1;
	else if (key_code == K_AR_L)
		game->player.left_turn = 1;
	else if (key_code == K_AR_R)
		game->player.right_turn = 1;
	return (0);
}

int		key_release_set(int key_code, t_player *player)
{
	if (key_code == K_W)
		player->forward = 0;
	else if (key_code == K_S)
		player->back = 0;
	else if (key_code == K_A)
		player->left = 0;
	else if (key_code == K_D)
		player->right = 0;
	else if (key_code == K_AR_L)
		player->left_turn = 0;
	else if (key_code == K_AR_R)
		player->right_turn = 0;
	return (0);
}
