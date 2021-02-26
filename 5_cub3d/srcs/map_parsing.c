/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:29:50 by mchae             #+#    #+#             */
/*   Updated: 2021/02/26 20:18:39 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_map_info(t_game *game)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_strchr(game->info_map[RESOLUTION], ' ');
	invalid_char_error(tmp, RESOLUTION);
	game->screen_width = ft_atoi(tmp);
	tmp = ft_strrchr(game->info_map[RESOLUTION], ' ');
	game->screen_height = ft_atoi(tmp);
	while (++i <= SPRITE)
	{
		tmp = ft_strrchr(game->info_map[i], ' ') + 1;
		game->texture_path[i] = ft_strdup(tmp);
	}
	parsing_color(game, FLOOR_COLOR, game->floor_color);
	parsing_color(game, CEILING_COLOR, game->ceiling_color);
}

void	parsing_color(t_game *game, int type, int *p_color)
{
	int		i;
	int		j;
	char	*tmp;
	char	**tmp_split;

	tmp = ft_strchr(game->info_map[type], ' ');
	invalid_char_error(tmp, type);
	tmp_split = ft_split(tmp, ',');
	i = -1;
	j = 0;
	while (tmp_split[j])
		j++;
	if (j != 3)
		error_exit("color over count");
	while (++i < 3)
		p_color[i] = ft_atoi(tmp_split[i]);
	char_free(tmp_split, 2);
}
