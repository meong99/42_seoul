/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:30 by mchae             #+#    #+#             */
/*   Updated: 2021/03/27 20:12:43 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_init(t_game *game, char *filename)
{
	int i;

	i = -1;
	game->info.cols = 0;
	game->info.sprite_num = 0;
	game->player.forward = 0;
	game->player.back = 0;
	game->player.right = 0;
	game->player.left = 0;
	game->player.left_turn = 0;
	game->player.right_turn = 0;
	while (++i < 8)
		game->info.info_check[i] = -1;
	map_parsing(game, filename);
	buf_init(&game->info, &game->ray);
	game->sprite_dist =\
	(t_sprite_dist*)var_malloc(sizeof(t_sprite_dist) * \
		game->info.sprite_num);
}

void	mlx_win_img_init(t_info *info, t_img *img)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->screen_width,
		info->screen_height, "cub3D");
	img->img = \
		mlx_new_image(info->mlx, info->screen_width, info->screen_height);
	img->data = (int*)mlx_get_data_addr(\
		img->img, &img->bpp, &img->size_l, &img->endian);
	img->padding = (img->size_l - info->screen_width * (img->bpp / 8)) / 4;
}

void	player_init(t_player *player)
{
	int		angle;

	player->turn_speed = get_radian(3);
	player->move_speed = 0.05;
	player->dir_x = 1.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.66;
	if (player->char_dir == 'E')
		angle = 0;
	else if (player->char_dir == 'S')
		angle = 90;
	else if (player->char_dir == 'W')
		angle = 180;
	else
		angle = 270;
	player_camera_turn(player, get_radian(angle));
}

void	buf_init(t_info *info, t_ray *ray)
{
	int		i;
	int		j;

	i = -1;
	ray->buf = (int**)var_malloc(sizeof(int*) * info->screen_height);
	while (++i < info->screen_height)
		ray->buf[i] = (int*)var_malloc(sizeof(int) * info->screen_width);
	i = -1;
	while (++i < info->screen_height)
	{
		j = -1;
		while (++j < info->screen_width)
			ray->buf[i][j] = 0;
	}
	ray->sprite_buf = (double*)var_malloc(sizeof(double) * info->screen_width);
}
