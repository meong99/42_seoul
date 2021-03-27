/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:46 by mchae             #+#    #+#             */
/*   Updated: 2021/03/28 03:52:53 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char *argv[])
{
	t_game game;

	if (argc < 2 || !argv)
		error_exit("arg error");
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
	all_free(game);
	exit(0);
	return (0);
}

int		main_loop(t_game *game)
{
	raycasting(game);
	return (0);
}

void	start_loop(t_game *game)
{
	mlx_hook(game->info.win, X_EVENT_KEY_PRESS, 0, &key_press_set, game);
	mlx_hook(game->info.win, X_EVENT_KEY_RELEASE, \
		0, &key_release_set, &game->player);
	mlx_hook(game->info.win, X_EVENT_KEY_EXIT, 0, &win_close, game);
	mlx_loop_hook(game->info.mlx, &main_loop, game);
	mlx_loop(game->info.mlx);
}
