/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:53:25 by selim             #+#    #+#             */
/*   Updated: 2021/02/04 00:18:06 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		calc_step_direction(t_game *g)
{
	if (g->rayy.dir_x < 0)
	{
		g->rayy.step_x = -1;
		g->rayy.side_dist_x = (g->player.posx - \
				g->rayy.map_x) * g->rayy.delta_dist_x;
	}
	else
	{
		g->rayy.step_x = 1;
		g->rayy.side_dist_x = (g->rayy.map_x + 1.0 \
				- g->player.posx) * g->rayy.delta_dist_x;
	}
	if (g->rayy.dir_y < 0)
	{
		g->rayy.step_y = -1;
		g->rayy.side_dist_y = (g->player.posy - \
				g->rayy.map_y) * g->rayy.delta_dist_y;
	}
	else
	{
		g->rayy.step_y = 1;
		g->rayy.side_dist_y = (g->rayy.map_y + 1.0 - \
				g->player.posy) * g->rayy.delta_dist_y;
	}
}

void		perform_dda(t_game *g)
{
	while (g->rayy.hit == 0)
	{
		if (g->rayy.side_dist_x < g->rayy.side_dist_y)
		{
			g->rayy.side_dist_x += g->rayy.delta_dist_x;
			g->rayy.map_x += g->rayy.step_x;
			if (g->rayy.step_x == -1)
				g->rayy.side = C_NO;
			else
				g->rayy.side = C_SO;
		}
		else
		{
			g->rayy.side_dist_y += g->rayy.delta_dist_y;
			g->rayy.map_y += g->rayy.step_y;
			if (g->rayy.step_y == -1)
				g->rayy.side = C_WE;
			else
				g->rayy.side = C_EA;
		}
		if (g->config.map[g->rayy.map_x][g->rayy.map_y] == '1')
			g->rayy.hit = 1;
	}
}

void		calc_wall(t_game *g)
{
	if (g->rayy.side <= 1)
		g->rayy.perp_wall_dist = (g->rayy.map_x - \
				g->player.posx + (1 - g->rayy.step_x) / 2) / g->rayy.dir_x;
	else
		g->rayy.perp_wall_dist = (g->rayy.map_y - \
				g->player.posy + (1 - g->rayy.step_y) / 2) / g->rayy.dir_y;
	g->rayy.line_height = (int)(g->config.screenheight\
			/ g->rayy.perp_wall_dist);
	g->rayy.draw_start = -g->rayy.line_height / 2 + \
						g->config.screenheight / 2 + g->config.eyelevel;
	if (g->rayy.draw_start < 0)
		g->rayy.draw_start = 0;
	g->rayy.draw_end = g->rayy.line_height / 2 + \
				g->config.screenheight / 2 + g->config.eyelevel;
	if (g->rayy.draw_end >= g->config.screenheight)
		g->rayy.draw_end = g->config.screenheight - 1;
}

void		calc_texture(t_game *g, int x, int side, int y)
{
	int			color;
	double		height;

	if (g->rayy.side <= 1)
		g->rayy.wall_x = g->player.posy + \
						g->rayy.perp_wall_dist * g->rayy.dir_y;
	else
		g->rayy.wall_x = g->player.posx + \
						g->rayy.perp_wall_dist * g->rayy.dir_x;
	g->rayy.wall_x -= floor(g->rayy.wall_x);
	g->rayy.tex_x = (int)(g->rayy.wall_x * g->config.tex[side].width);
	if (side == 1 || side == 2)
		g->rayy.tex_x = (g->config.tex[side].width) - g->rayy.tex_x - 1;
	height = g->config.tex[side].height;
	g->rayy.step = 1.0 * g->config.tex[side].height / g->rayy.line_height;
	g->rayy.tex_pos = (g->rayy.draw_start - g->config.screenheight / 2 + \
			g->rayy.line_height / 2 - g->config.eyelevel) * g->rayy.step;
	while (++y < g->rayy.draw_end)
	{
		g->rayy.tex_y = (int)g->rayy.tex_pos & ((int)height - 1);
		g->rayy.tex_pos += g->rayy.step;
		color = g->config.tex[side].texture[(int)height\
			* g->rayy.tex_y + g->rayy.tex_x];
		g->buf[y][x] = color;
	}
}

void		calc_raycasting(t_game *g)
{
	int x;

	x = 0;
	while (x < g->config.screenwidth)
	{
		set_ray_item(g, x);
		calc_step_direction(g);
		perform_dda(g);
		calc_wall(g);
		calc_texture(g, x, g->rayy.side, g->rayy.draw_start - 1);
		g->z_buf[x] = g->rayy.perp_wall_dist;
		x++;
	}
}
