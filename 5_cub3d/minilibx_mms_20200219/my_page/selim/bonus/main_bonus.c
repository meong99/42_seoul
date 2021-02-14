/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:44:21 by selim             #+#    #+#             */
/*   Updated: 2021/02/04 16:54:20 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		main(int argc, char **argv)
{
	t_game game;

	check_argument(&game, argc, argv[2]);
	init_player(&game);
	init_config(&game);
	parse_config(&game, &game.config, argv[1]);
	check_values(&game);
	if (!check_map_validation(&game, game.config))
		return (exit_error(&game, 0, "Invalid map"));
	set_sprite(&game);
	init_buffer(&game);
	init_mlx_functions(&game);
	load_texture(&game);
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		return (screenshot(&game));
	play_music(argv[1]);
	start_raycasting(&game);
	all_free(&game);
	return (EXIT_SUCCESS);
}

int		main_loop(t_game *game)
{
	player_move(game, &game->player);
	draw_ceil_floor(game);
	calc_raycasting(game);
	calc_sprite(game);
	draw(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	show_info(game);
	return (0);
}

void	check_argument(t_game *game, int argc, char *option)
{
	if (argc < 2)
		exit_error(game, 0, "Arguments given too little");
	if (argc > 3)
		exit_error(game, 0, "Arguments given too many");
	if (argc == 3 && ft_strncmp(option, "--save", 6) != 0)
		exit_error(game, 0, "Argument only --save");
}

void	start_raycasting(t_game *game)
{
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, &key_release, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}
