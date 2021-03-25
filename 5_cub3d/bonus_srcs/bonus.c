/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 23:30:06 by chaemyeongs       #+#    #+#             */
/*   Updated: 2021/03/25 13:00:35 by mchae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_hud(t_game *game)
{
	char	*leftover_sprite;
	char	*mouse_speed;

	leftover_sprite = ft_itoa(game->info.bonus_sprite_num);
	mouse_speed = ft_itoa(game->mouse.speed);
	mlx_string_put(game->info.mlx, game->info.win,\
		10, 15, 0xFFFFFF, leftover_sprite);
	mlx_string_put(game->info.mlx, game->info.win,\
		35, 15, 0xFFFFFF, "sprites left");
	mlx_string_put(game->info.mlx, game->info.win,\
		game->info.screen_width - 30, \
		15, 0xFFFFFF, mouse_speed);
	free(leftover_sprite);
	free(mouse_speed);
}

void	bonus_key_set(int key_code, t_game *game)
{
	if (key_code == 33 && game->mouse.speed > 1)
		game->mouse.speed--;
	else if (key_code == 30 && game->mouse.speed < 10)
		game->mouse.speed++;
	else if (key_code == K_SPACE)
		bonus_attack(key_code, 0, 0, game);
}

int	bonus_attack(int key_code, int x, int y, t_game *game)
{
	int	i;
	int	sprite_dist_x;

	i = -1;
	x = (int)(game->player.char_pos_x + game->player.dir_x);
	y = (int)(game->player.char_pos_y + game->player.dir_y);
	if (game->info.map[y][x] == '3')
	{
		game->info.map[y][x] = '0';
		game->info.map_mask[y][x] = 0;
		while (++i < game->info.sprite_num)
		{
			sprite_dist_x = (int)game->sprite_dist[i].x;
			if (x == sprite_dist_x)
			{
				game->sprite_dist[i].dist = 0;
				game->info.bonus_sprite_num--;
			}
		}
	}
	return (key_code);
}

int	mouse_move(int x, int y, t_game *game)
{
	double radian;

	if (game->mouse.start == 0)
		game->mouse.old_x = x;
	game->mouse.turn = get_radian(x - game->mouse.old_x);
	game->mouse.old_x = x;
	radian = game->mouse.turn / game->mouse.speed;
	if (radian < 10)
		player_camera_turn(&game->player, radian);
	game->mouse.start = 1;
	return (y);
}
