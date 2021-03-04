/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:46 by mchae             #+#    #+#             */
/*   Updated: 2021/03/04 17:00:10 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char *argv[])
{
	t_game game;

	if (argc < 2 || !argv)
		return (-1);
	game_init(&game, argv[1]);
	mwi_init(&game);
	ray_init(&game);
	raycasting(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &event_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &win_close, 0);

	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}

int		event_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	else
		player_event_key(game, key_code);
	raycasting(game);
	return (0);
}

int		win_close(void)
{
	exit(0);
	return (0);
}

int		main_loop(t_game *game)
{
	game = 0;
	return (0);
}
