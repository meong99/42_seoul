/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:46 by mchae             #+#    #+#             */
/*   Updated: 2021/03/27 20:11:18 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		main(int argc, char *argv[])
{
	t_game game;

	if (argc < 2 || !argv)
		return (-1);
	game.stage = 1;
	game_init(&game, argv[1]);
	mlx_win_img_init(&game.info, &game.img);
	load_texture(&game);
	player_init(&game.player);
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		save_bmp(&game);
	start_loop(&game);
	return (0);
}

int		win_close(t_game *game)
{
	int		i;

	i = -1;
	while (++i <= SPRITE)
		mlx_destroy_image(game->info.mlx, game->tex_info[i].img);
	mlx_destroy_image(game->info.mlx, game->img.img);
	mlx_destroy_window(game->info.mlx, game->info.win);
	system("killall afplay");
	exit(0);
	return (0);
}

int		main_loop(t_game *game)
{
	if (game->next_stage)
		next_stage(game);
	raycasting(game);
	ft_hud(game);
	return (0);
}

void	start_loop(t_game *game)
{
	system("afplay -v 0.40  music/underthesea.mp3 &");
	mlx_hook(game->info.win, X_EVENT_KEY_PRESS, 0, key_press_set, game);
	mlx_hook(game->info.win, X_EVENT_KEY_RELEASE, \
		0, key_release_set, game);
	mlx_hook(game->info.win, X_EVENT_KEY_EXIT, 0, win_close, game);
	mlx_hook(game->info.win, MOTIONNOTIFY, 0, mouse_move, game);
	mlx_loop_hook(game->info.mlx, main_loop, game);
	mlx_loop(game->info.mlx);
}
