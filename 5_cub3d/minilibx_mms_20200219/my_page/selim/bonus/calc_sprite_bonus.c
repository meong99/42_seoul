/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:05:32 by selim             #+#    #+#             */
/*   Updated: 2021/02/04 16:57:22 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	sort_sprite(t_game *g)
{
	int			i;
	int			j;
	t_sprite_y	temp;

	i = -1;
	while (++i < g->config.sprite_num)
	{
		g->sprite[i].distance = ((g->player.posx - g->sprite[i].x) *\
			(g->player.posx - g->sprite[i].x) + (g->player.posy - \
			g->sprite[i].y) * (g->player.posy - g->sprite[i].y));
	}
	i = -1;
	while (++i < g->config.sprite_num - 1)
	{
		j = -1;
		while (++j < g->config.sprite_num - 1 - i)
		{
			if (g->sprite[j].distance < g->sprite[j + 1].distance)
			{
				temp = g->sprite[j];
				g->sprite[j] = g->sprite[j + 1];
				g->sprite[j + 1] = temp;
			}
		}
	}
}

void	translate_sprite(t_game *g, int i)
{
	g->ray_sprite.relative_dist_x = g->sprite[i].x - g->player.posx;
	g->ray_sprite.relative_dist_y = g->sprite[i].y - g->player.posy;
	g->ray_sprite.inverse_determinant = 1.0 / (g->player.dir_y * \
		g->player.plane_x - g->player.dir_x * g->player.plane_y);
	g->ray_sprite.trans_x = g->ray_sprite.inverse_determinant * \
		(g->player.dir_y * g->ray_sprite.relative_dist_x \
		- g->player.dir_x * g->ray_sprite.relative_dist_y);
	g->ray_sprite.trans_y = g->ray_sprite.inverse_determinant * \
		(-g->player.plane_y * g->ray_sprite.relative_dist_x + \
		g->player.plane_x * g->ray_sprite.relative_dist_y);
	g->ray_sprite.screen_x = (int)((g->config.screenwidth / 2) * \
		(1 + g->ray_sprite.trans_x / g->ray_sprite.trans_y));
}

void	calc_sprite_height_width(t_game *g)
{
	g->ray_sprite.height = abs((int)(g->config.screenheight\
					/ g->ray_sprite.trans_y));
	g->ray_sprite.draw_start_y = -g->ray_sprite.height / 2 \
				+ g->config.screenheight / 2 + g->config.eyelevel;
	if (g->ray_sprite.draw_start_y < 0)
		g->ray_sprite.draw_start_y = 0;
	g->ray_sprite.draw_end_y = g->ray_sprite.height / 2 + \
				g->config.screenheight / 2 + g->config.eyelevel;
	if (g->ray_sprite.draw_end_y >= g->config.screenheight)
		g->ray_sprite.draw_end_y = g->config.screenheight - 1;
	g->ray_sprite.width = abs((int)(g->config.screenheight \
				/ g->ray_sprite.trans_y));
	g->ray_sprite.draw_start_x = -g->ray_sprite.width \
				/ 2 + g->ray_sprite.screen_x;
	if (g->ray_sprite.draw_start_x < 0)
		g->ray_sprite.draw_start_x = 0;
	g->ray_sprite.draw_end_x = g->ray_sprite.width / 2 + \
				g->ray_sprite.screen_x;
	if (g->ray_sprite.draw_end_x >= g->config.screenwidth)
		g->ray_sprite.draw_end_x = g->config.screenwidth - 1;
}

void	get_sprite(t_game *g, int x, int height, t_tex temp)
{
	int draw;
	int color;
	int y;

	g->ray_sprite.tex_x = (int)((256 * (x - (-g->ray_sprite.width / 2 + \
		g->ray_sprite.screen_x)) * temp.width\
			/ g->ray_sprite.width) / 256);
	if (g->ray_sprite.trans_y > 0 && x > 0 && \
		x < g->config.screenwidth && g->ray_sprite.trans_y < g->z_buf[x])
	{
		y = g->ray_sprite.draw_start_y;
		while (y < g->ray_sprite.draw_end_y)
		{
			draw = (y - g->config.eyelevel) * 256 - \
				(g->config.screenheight) * 128 + g->ray_sprite.height * 128;
			g->ray_sprite.tex_y = ((draw * height) / \
				g->ray_sprite.height) / 256;
			color = temp.texture[(int)temp.width * \
				g->ray_sprite.tex_y + g->ray_sprite.tex_x];
			if ((color & 0x00FFFFFF) != 0)
				g->buf[y][x] = color;
			y++;
		}
	}
}

void	calc_sprite(t_game *game)
{
	int		i;
	int		stripe;
	int		type;
	t_tex	temp;

	sort_sprite(game);
	i = 0;
	while (i < game->config.sprite_num)
	{
		type = game->sprite[i].c_type;
		temp = game->config.tex[type];
		translate_sprite(game, i);
		calc_sprite_height_width(game);
		stripe = game->ray_sprite.draw_start_x;
		while (stripe < game->ray_sprite.draw_end_x)
		{
			get_sprite(game, stripe, temp.height, temp);
			stripe++;
		}
		i++;
	}
}
