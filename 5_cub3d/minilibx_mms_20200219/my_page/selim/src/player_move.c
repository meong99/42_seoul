/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:06:07 by selim             #+#    #+#             */
/*   Updated: 2021/02/03 15:24:06 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		move_forward(t_player *p, char **map, int key)
{
	if (key == 1)
	{
		if (map[(int)(p->posx + p->dir_x * \
					p->move_speed)][(int)(p->posy)] == '0')
			p->posx += (p->dir_x) * p->move_speed;
		if (map[(int)p->posx][(int)(p->posy + \
					p->dir_y * p->move_speed)] == '0')
			p->posy += (p->dir_y) * p->move_speed;
	}
	if (key == -1)
	{
		if (map[(int)(p->posx - p->dir_x * \
				p->move_speed)][(int)(p->posy)] == '0')
			p->posx -= (p->dir_x) * p->move_speed;
		if (map[(int)p->posx][(int)(p->posy - \
				p->dir_y * p->move_speed)] == '0')
			p->posy -= (p->dir_y) * p->move_speed;
	}
}

void		move_leftright(t_player *p, char **map, int key)
{
	if (key == 1)
	{
		if (map[(int)(p->posx)][(int)(p->posy \
				+ p->dir_x * p->move_speed)] == '0')
			p->posy += p->dir_x * p->move_speed;
		if (map[(int)(p->posx - p->dir_y * \
				p->move_speed)][(int)p->posy] == '0')
			p->posx -= p->dir_y * p->move_speed;
	}
	if (key == -1)
	{
		if (map[(int)p->posx][(int)(p->posy - \
				p->dir_x * p->move_speed)] == '0')
			p->posy -= p->dir_x * p->move_speed;
		if (map[(int)(p->posx + p->dir_y * \
				p->move_speed)][(int)p->posy] == '0')
			p->posx += p->dir_y * p->move_speed;
	}
}

void		rotate_right_player(t_game *g)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = g->player.dir_x;
	old_plane_x = g->player.plane_x;
	g->player.dir_x = g->player.dir_x * cos(-g->player.rot_speed) - \
		g->player.dir_y * sin(-g->player.rot_speed);
	g->player.dir_y = old_dir_x * sin(-g->player.rot_speed) + \
		g->player.dir_y * cos(-g->player.rot_speed);
	g->player.plane_x = g->player.plane_x * cos(-g->player.rot_speed) - \
		g->player.plane_y * sin(-g->player.rot_speed);
	g->player.plane_y = old_plane_x * sin(-g->player.rot_speed) + \
		g->player.plane_y * cos(-g->player.rot_speed);
}

void		rotate_left_player(t_game *g)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = g->player.dir_x;
	old_plane_x = g->player.plane_x;
	g->player.dir_x = g->player.dir_x * cos(g->player.rot_speed) - \
			g->player.dir_y * sin(g->player.rot_speed);
	g->player.dir_y = old_dir_x * sin(g->player.rot_speed) + \
			g->player.dir_y * cos(g->player.rot_speed);
	g->player.plane_x = g->player.plane_x * cos(g->player.rot_speed) - \
			g->player.plane_y * sin(g->player.rot_speed);
	g->player.plane_y = old_plane_x * sin(g->player.rot_speed) + \
			g->player.plane_y * cos(g->player.rot_speed);
}

void		player_move(t_game *game, t_player *p)
{
	double newlevel;

	newlevel = game->config.eyelevel + p->eyelevel * 30;
	if (newlevel < game->config.screenheight / 4 \
			&& newlevel > -game->config.screenheight / 4)
		game->config.eyelevel = newlevel;
	if (p->walk_forward == 1)
		move_forward(&game->player, game->config.map, p->walk_forward);
	if (p->walk_forward == -1)
		move_forward(&game->player, game->config.map, p->walk_forward);
	if (p->move_lr == 1)
		move_leftright(&game->player, game->config.map, p->move_lr);
	if (p->move_lr == -1)
		move_leftright(&game->player, game->config.map, p->move_lr);
	if (p->turndirection == 1)
		rotate_right_player(game);
	if (p->turndirection == -1)
		rotate_left_player(game);
}
