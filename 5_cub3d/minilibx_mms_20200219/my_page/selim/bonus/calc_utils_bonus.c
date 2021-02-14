/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:47:32 by selim             #+#    #+#             */
/*   Updated: 2021/02/04 16:55:26 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int			set_ctype_sp(t_game *g, int y, int x)
{
	if (g->config.map[y][x] == '3')
		return (C_EXTRA);
	return (C_S);
}

void		set_sprite(t_game *g)
{
	int x;
	int y;
	int i;

	if (!(g->sprite = (t_sprite_y *)malloc(sizeof(t_sprite_y)\
						* g->config.sprite_num)))
		exit_error(g, EXIT_FAILURE, "Malloc error at sprite");
	i = 0;
	y = 0;
	while (y < g->config.rows)
	{
		x = 0;
		while (x < g->config.colums)
		{
			if (g->config.map[y][x] == '2' || g->config.map[y][x] == '3')
			{
				g->sprite[i].x = 0.5f + y;
				g->sprite[i].y = 0.5f + x;
				g->sprite[i].c_type = set_ctype_sp(g, y, x);
				i++;
			}
			x++;
		}
		y++;
	}
}

void		set_ray_item(t_game *g, int x)
{
	g->rayy.camera_x = 2 * x / (double)g->config.screenwidth - 1;
	g->rayy.dir_x = g->player.dir_x + g->player.plane_x * g->rayy.camera_x;
	g->rayy.dir_y = g->player.dir_y + g->player.plane_y * g->rayy.camera_x;
	g->rayy.map_x = (int)g->player.posx;
	g->rayy.map_y = (int)g->player.posy;
	g->rayy.delta_dist_x = fabs(1 / g->rayy.dir_x);
	g->rayy.delta_dist_y = fabs(1 / g->rayy.dir_y);
	g->rayy.hit = 0;
}
