/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selim <selim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:43:52 by selim             #+#    #+#             */
/*   Updated: 2021/02/04 13:23:44 by selim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_machine(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->config.rows)
	{
		if (game->config.map[i])
			free(game->config.map[i]);
	}
	free(game->config.map);
	i = -1;
	while (++i < TEXTURES - 3)
	{
		if (game->config.tex[i].texture)
			free(game->config.tex[i].texture);
	}
}

void	ft_free(void *s)
{
	free(s);
	s = 0;
}

void	all_free(t_game *game)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->sprite)
		ft_free(game->sprite);
	if (game->buf)
		free_2stars((void *)game->buf);
	if (game->z_buf)
		ft_free(game->z_buf);
	if (game->mlx && game->win)
		mlx_destroy_image(game->mlx, game->win);
	exit(0);
}

void	free_2stars(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = 0;
		i++;
	}
	free(str);
	str = 0;
}
