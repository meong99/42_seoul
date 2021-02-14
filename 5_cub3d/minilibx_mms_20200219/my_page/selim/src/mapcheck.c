/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:48:47 by selim             #+#    #+#             */
/*   Updated: 2021/02/04 00:15:25 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		mapcheck_02(t_game *game, int i, int j)
{
	if (game->config.map[i][j] == '2')
		game->config.sprite_num++;
	if (i <= 0 || i >= game->config.rows - 1 \
			|| j <= 0 || j >= game->config.colums - 1)
		return (0);
	else if (game->config.map[i][j + 1] == ' '
	|| game->config.map[i][j + 1] == '\0' || game->config.map[i][j - 1] == ' ')
		return (0);
	else if ((int)ft_strlen(game->config.map[i - 1]) <= j
	|| game->config.map[i - 1][j] == ' ' || game->config.map[i - 1][j] == '\0')
		return (0);
	else if ((int)ft_strlen(game->config.map[i + 1]) <= j
	|| game->config.map[i + 1][j] == ' ' || game->config.map[i + 1][j] == '\0')
		return (0);
	return (1);
}

void	set_player_direction(t_player *player, double radian)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = player->dir_x;
	player->dir_x = tmp_dir_x * cos(radian) - player->dir_y * sin(radian);
	player->dir_y = tmp_dir_x * sin(radian) + player->dir_y * cos(radian);
	tmp_plane_x = player->plane_x;
	player->plane_x = tmp_plane_x * cos(radian) - player->plane_y * sin(radian);
	player->plane_y = tmp_plane_x * sin(radian) + player->plane_y * cos(radian);
}

int		set_playerpos(t_game *g, int i, int j)
{
	char	c;
	double	temp_angle;

	if (g->player.posx || g->player.posy)
		return (0);
	g->player.direction = g->config.map[i][j];
	c = g->player.direction;
	if (g->player.direction == 'W')
		temp_angle = 0;
	else if (c == 'S')
		temp_angle = 90;
	else if (c == 'E')
		temp_angle = 180;
	else
		temp_angle = 270;
	set_player_direction(&g->player, temp_angle * (M_PI / 180));
	g->player.posx = i + 0.5f;
	g->player.posy = j + 0.5f;
	g->config.map[(int)g->player.posx][(int)g->player.posy] = '0';
	return (1);
}

int		check_map_validation(t_game *g, t_config c)
{
	static int	i = -1;
	int			j;

	while (g->config.map[++i])
	{
		j = -1;
		while (g->config.map[i][++j])
		{
			if (ft_strchr("NSWE", g->config.map[i][j]))
			{
				if (!set_playerpos(g, i, j))
					return (0);
			}
			else if (c.map[i][j] == '0' || c.map[i][j] == '2')
			{
				if (!mapcheck_02(g, i, j))
					return (0);
			}
			else if (ft_strchr("1 ", g->config.map[i][j]))
				continue ;
			else
				return (0);
		}
	}
	return (1);
}

int		check_values(t_game *game)
{
	int i;

	if (!game->config.screenwidth || !game->config.screenheight)
		return (exit_error(game, EXIT_FAILURE, "Need info on Screensize"));
	if (!game->config.rows || !game->config.colums || !game->config.tile)
		return (exit_error(game, EXIT_FAILURE, "Need info on map"));
	if (!game->config.floor_color || !game->config.ceiling_color)
		return (exit_error(game, EXIT_FAILURE, "Color part error1"));
	i = -1;
	while (++i < TEXTURES - 3)
	{
		if (!game->config.tex[i].tex_path)
			return (exit_error(game, EXIT_FAILURE, "Tex_path error"));
	}
	if (game->config.istype[C_C] != 2 || game->config.istype[C_F] != 2)
		return (exit_error(game, EXIT_FAILURE, "Color part error2"));
	return (1);
}
