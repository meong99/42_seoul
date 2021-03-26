/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 23:30:06 by chaemyeongs       #+#    #+#             */
/*   Updated: 2021/03/26 15:47:28 by mchae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_hud(t_game *game)
{
	char	*leftover_sprite;
	char	*mouse_speed;
	char	*stage;

	leftover_sprite = ft_itoa(game->info.bonus_sprite_num);
	mouse_speed = ft_itoa(11 - game->mouse.speed);
	stage = ft_itoa(game->stage);
	mlx_string_put(game->info.mlx, game->info.win,\
		10, 15, 0xFFFFFF, leftover_sprite);
	mlx_string_put(game->info.mlx, game->info.win, 35, 15, 0xFFFFFF, "sprites");
	mlx_string_put(game->info.mlx, game->info.win, 10, 35, 0xFFFFFF, "mouse speed");
	mlx_string_put(game->info.mlx, game->info.win, 130, 35, 0xFFFFFF, mouse_speed);
	mlx_string_put(game->info.mlx, game->info.win, 10, 55, 0xFFFFFF, "stage");
	mlx_string_put(game->info.mlx, game->info.win, 70, 55, 0xFFFFFF, stage);
	free(leftover_sprite);
	free(mouse_speed);
	free(stage);
}

void	bonus_key_set(int key_code, t_game *game)
{
	if (key_code == 33 && game->mouse.speed < 10)
		game->mouse.speed++;
	else if (key_code == 30 && game->mouse.speed > 1)
		game->mouse.speed--;
	else if (key_code == K_SPACE)
		bonus_attack(key_code, 0, 0, game);
	else if (!game->player.down && key_code == K_AR_U)
		game->player.up = 1;
	else if (!game->player.up && key_code == K_AR_D)
		game->player.down = 1;
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
				if (game->info.bonus_sprite_num == 0)
					game->next_stage = 1;
			}
		}
	}
	return (key_code);
}

int	mouse_move(int x, int y, t_game *game)
{
	double radian;
	double eye_level;

	if (game->mouse.start == 0)
	{
		game->mouse.old_x = x;
		game->mouse.old_y = y;
	}
	game->mouse.turn = get_radian(x - game->mouse.old_x);
	eye_level = game->mouse.old_y - y;
	game->player.eye_level += eye_level;
	game->mouse.old_y = y;
	game->mouse.old_x = x;
	radian = game->mouse.turn / game->mouse.speed;
	if (radian < 10)
		player_camera_turn(&game->player, radian);
	game->mouse.start = 1;
	return (0);
}
