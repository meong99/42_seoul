/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:05:49 by selim             #+#    #+#             */
/*   Updated: 2021/02/04 13:24:28 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_player(t_game *game)
{
	game->player.width = 0;
	game->player.height = 0;
	game->player.turndirection = 0;
	game->player.walk_forward = 0;
	game->player.move_lr = 0;
	game->player.rotationangle = M_PI / 2;
	game->player.walkspeed = 5;
	game->player.turnspeed = 3 * (M_PI / 180);
	game->player.move_speed = .05;
	game->player.rot_speed = .05;
	game->player.rotationspeed = 0;
	game->player.eyelevel = 0;
	game->player.posx = 0;
	game->player.posy = 0;
	game->player.dir_x = 0.0;
	game->player.dir_y = -1.0;
	game->player.plane_x = -0.66;
	game->player.plane_y = 0.0;
}

void	init_config(t_game *game)
{
	int i;

	game->config.screenwidth = 0;
	game->config.screenheight = 0;
	game->config.rows = 0;
	game->config.colums = 0;
	game->config.tile = 0;
	i = 0;
	while (i < TEXTURES)
		game->config.tex[i++].tex_path = NULL;
	i = 0;
	while (i <= C_MAP)
		game->config.istype[i++] = 0;
	game->config.floor_color = 0;
	game->config.ceiling_color = 0;
	game->config.map = NULL;
	game->config.rotation_speed = .11;
	game->config.updown_speed = 30;
	game->config.eyelevel = 0;
	game->config.fov = 80 * M_PI / 180;
	game->config.sprite_num = 0;
}

void	init_mlx_functions(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			game->config.screenwidth, game->config.screenheight, "cub3d");
	game->img.img = mlx_new_image(game->mlx,
			game->config.screenwidth, game->config.screenheight);
	game->img.data = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
}

void	init_zbuf(t_game *game)
{
	int i;

	if (!(game->z_buf = (double *)malloc(sizeof(double) * \
					game->config.screenwidth)))
		exit_error(game, EXIT_FAILURE, "Buf malloc fail\n");
	i = -1;
	while (++i < game->config.screenwidth)
		game->z_buf[i] = 0;
}

void	init_buffer(t_game *game)
{
	int i;
	int j;

	if (!(game->buf = (int **)malloc(sizeof(int *) * \
					game->config.screenheight)))
		exit_error(game, EXIT_FAILURE, "Buf malloc fail!\n");
	i = -1;
	while (++i < game->config.screenheight)
	{
		if (!(game->buf[i] = (int *)malloc(sizeof(int) * \
					game->config.screenwidth)))
			exit_error(game, EXIT_FAILURE, "Buf malloc fail!\n");
	}
	i = -1;
	while (++i < game->config.screenheight)
	{
		j = -1;
		while (++j < game->config.screenwidth)
			game->buf[i][j] = 0;
	}
	init_zbuf(game);
}
