/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:40:45 by selim             #+#    #+#             */
/*   Updated: 2021/02/04 13:24:35 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	key_press_bonus(int key_code, t_game *game)
{
	if (key_code == KEY_UP)
		game->player.eyelevel = 1;
	else if (key_code == KEY_DOWN)
		game->player.eyelevel = -1;
	else if (key_code == KEY_MINUS)
		game->player.move_speed > 0.02 ? game->player.move_speed -= 0.006 : 0;
	else if (key_code == KEY_PLUS)
		game->player.move_speed < 0.1 ? game->player.move_speed += 0.006 : 0;
	return (0);
}

int			key_press(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
	{
		exit_game(game);
		exit(0);
	}
	else if (key_code == KEY_W)
		game->player.walk_forward = 1;
	else if (key_code == KEY_S)
		game->player.walk_forward = -1;
	else if (key_code == KEY_D)
	{
		game->player.move_lr = -1;
	}
	else if (key_code == KEY_A)
	{
		game->player.move_lr = 1;
	}
	else if (key_code == KEY_RIGHT)
		game->player.turndirection = 1;
	else if (key_code == KEY_LEFT)
		game->player.turndirection = -1;
	key_press_bonus(key_code, game);
	return (0);
}

static int	key_release_bonus(int key_code, t_game *game)
{
	if (key_code == KEY_UP)
		game->player.eyelevel = 0;
	else if (key_code == KEY_DOWN)
		game->player.eyelevel = 0;
	else if (key_code == KEY_MINUS)
		game->player.move_speed -= 0;
	else if (key_code == KEY_PLUS)
		game->player.move_speed += 0;
	return (0);
}

int			key_release(int key_code, t_game *game)
{
	if (key_code == KEY_W)
		game->player.walk_forward = 0;
	else if (key_code == KEY_S)
		game->player.walk_forward = 0;
	else if (key_code == KEY_D)
	{
		game->player.move_lr = 0;
	}
	else if (key_code == KEY_A)
	{
		game->player.move_lr = 0;
	}
	else if (key_code == KEY_RIGHT)
		game->player.turndirection = 0;
	else if (key_code == KEY_LEFT)
		game->player.turndirection = 0;
	key_release_bonus(key_code, game);
	return (0);
}
